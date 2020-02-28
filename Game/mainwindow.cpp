#include <QEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsObject>

#include <memory>
#include <string>

#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include "startdialog.hh"
#include "guidedialog.hh"

#include "tiles/tilebase.h"
#include "tiles/forest.h"
#include "tiles/grassland.h"
#include "tiles/cornfield.hh"
#include "tiles/water.hh"
#include "tiles/rock.hh"

#include "buildings/buildingbase.h"
#include "buildings/headquarters.h"
#include "buildings/outpost.h"
#include "buildings/farm.h"
#include "buildings/boat.hh"
#include "buildings/mine.hh"

#include "workers/workerbase.h"
#include "workers/basicworker.h"
#include "workers/miner.hh"
#include "workers/saboteur.hh"

#include "core/resourcemaps.h"
#include "core/placeablegameobject.h"
#include "myresourcemaps.hh"
#include "exceptions/illegalaction.h"


MainWindow::MainWindow(QWidget* parent,
                       std::shared_ptr<Student::GameEventHandler> handler):
    QMainWindow(parent),
    ui_(new Ui::MainWindow),
    GEHandler_(handler),
    objectManager_(new Student::ObjectManager),
    scene_(new Student::GameScene(this))
{
    ui_->setupUi(this);

    player1_ = std::make_shared<Course::PlayerBase>("Player 1");
    player2_ = std::make_shared<Course::PlayerBase>("Player 2");

    playerOnTurn_ = player1_;

    ui_->graphicsView->setScene(dynamic_cast<QGraphicsScene*>(scene_.get()));

    worldGenerator_ = &Course::WorldGenerator::getInstance();

    worldGenerator_->addConstructor<Course::Grassland>(2);
    worldGenerator_->addConstructor<Course::Forest>(2);
    worldGenerator_->addConstructor<Student::Rock>(2);
    worldGenerator_->addConstructor<Student::Water>(2);
    worldGenerator_->addConstructor<Student::CornField>(2);

    GEHandler_ = std::make_shared<Student::GameEventHandler>();

    GEHandler_->addPlayer(player1_);
    GEHandler_->addPlayer(player2_);

    updateTextLabels();

    // Initializing UI-buttons
    ui_->HQButton->setEnabled(false);
    ui_->outpostButton->setEnabled(false);
    ui_->farmButton->setEnabled(false);
    ui_->boatButton->setEnabled(false);
    ui_->mineButton->setEnabled(false);
    ui_->assignBWButton->setEnabled(false);
    ui_->assignMinerButton->setEnabled(false);
    ui_->assignSaboteurButton->setEnabled(false);

    // If there occurs a click on the map GameScene sends a signal to the
    // MainWindow's slot updateButtons
    QObject::connect(scene_.get(),
                     SIGNAL(mapClicked(std::shared_ptr<Course::GameObject>)),
                     this,
                     SLOT(updateButtons(std::shared_ptr<Course::GameObject>)));
}

MainWindow::~MainWindow() {
    delete ui_;
}

void MainWindow::setSize(int width, int height) {
    scene_->setSize(width, height);

    worldGenerator_->generateMap(scene_->getSize().first,
                                 scene_->getSize().second, 1,
                                 objectManager_, GEHandler_);

    // Sending game map's tiles to the GameScene for drawing
    for (int x = 0; x < scene_->getSize().first; x++) {
        for (int y = 0; y < scene_->getSize().second; y++) {
            drawItem(objectManager_->getTile(Course::Coordinate(x, y)));
        }
    }
}

void MainWindow::setScale(int scale) {
    scene_->setScale(scale);
}

void MainWindow::drawItem( std::shared_ptr<Course::GameObject> obj) {
    scene_->drawItem(obj);
}

void MainWindow::updateTextLabels() {
    ui_->turnDisplayLabel->setText(QString::fromStdString(playerOnTurn_->getName()));
    if (playerOnTurn_ == player1_) {
        ui_->turnDisplayLabel->setStyleSheet("QLabel {color : black}");
    } else {
        ui_->turnDisplayLabel->setStyleSheet("QLabel {color : purple}");
    }

    ui_->moneyDisplayLabel->setText(QString::number(GEHandler_->getResourceValue(playerOnTurn_,Course::BasicResource::MONEY)));
    ui_->foodDisplayLabel->setText(QString::number(GEHandler_->getResourceValue(playerOnTurn_,Course::BasicResource::FOOD)));
    ui_->woodDisplayLabel->setText(QString::number(GEHandler_->getResourceValue(playerOnTurn_,Course::BasicResource::WOOD)));
    ui_->stoneDisplayLabel->setText(QString::number(GEHandler_->getResourceValue(playerOnTurn_,Course::BasicResource::STONE)));
    ui_->oreDisplayLabel->setText(QString::number(GEHandler_->getResourceValue(playerOnTurn_,Course::BasicResource::ORE)));
}

void MainWindow::isGameEnded() {
    std::vector<std::shared_ptr<Course::TileBase>> tiles = objectManager_->getAllTiles();
    int player1score = 0;
    int player2score = 0;

    // Calculates the tiles owners and checks if all tiles of the map have an owner
    for (std::shared_ptr<Course::TileBase> tile : tiles) {
        if (tile->getOwner() == nullptr) {
            // If there is a tile without an owner, the game continues
            return;
        } else if (tile->getOwner() == player1_) {
            ++player1score;
        } else if (tile->getOwner() == player2_) {
            ++player2score;
        }
    }

    // Checks who owns the most of the tiles and marks the winner
    if (player1score == player2score) {
        ui_->infoDisplayLabel->setText("Game ended to draw");
    } else if (player1score > player2score) {
        winner_ = player1_;
        ui_->infoDisplayLabel->setText("Player 1 won");
    } else {
        winner_ = player2_;
        ui_->infoDisplayLabel->setText("Player 2 won");
    }
    ui_->endTurnButton->setEnabled(false);
}

void MainWindow::addBuilding(std::shared_ptr<Course::BuildingBase> building) {
    try {
        recentTile_->setOwner(playerOnTurn_);
        recentTile_->addBuilding(building);
        scene_->drawItem(building);

        // Adds neighbour tiles to player's ownership if the building is
        // a HeadQuarters or an Outpost
        building->onBuildAction();

        playerOnTurn_->addObject(building);
    } catch (Course::IllegalAction& e) {
        qDebug() << e.what();
    }

    // There is nothing to be done after turn is used
    ui_->HQButton->setEnabled(false);
    ui_->outpostButton->setEnabled(false);
    ui_->farmButton->setEnabled(false);
    ui_->boatButton->setEnabled(false);
    ui_->mineButton->setEnabled(false);

    scene_->update(scene_->sceneRect());
    updateTextLabels();

    turnUsed_ = true;
    ui_->infoDisplayLabel->setText("Your turn ended");
    isGameEnded();
}

void MainWindow::addWorker(std::shared_ptr<Course::WorkerBase> worker) {
    try {
        recentObject_->setOwner(playerOnTurn_);
        recentTile_->addWorker(worker);
        scene_->drawItem(worker);
        playerOnTurn_->addObject(worker);
    } catch (Course::IllegalAction& e) {
        qDebug() << e.what();
    }

    // There is nothing to be done after turn is used
    ui_->assignBWButton->setEnabled(false);
    ui_->assignMinerButton->setEnabled(false);

    updateTextLabels();

    turnUsed_ = true;
    ui_->infoDisplayLabel->setText("Your turn ended");
}

void MainWindow::updateButtons(std::shared_ptr<Course::GameObject> gameObject) {
    // If turn has been used, there happens nothing when the game map is clicked
    if (turnUsed_) {
        return;
    }

    // Initializing UI-buttons
    ui_->HQButton->setEnabled(false);
    ui_->outpostButton->setEnabled(false);
    ui_->farmButton->setEnabled(false);
    ui_->boatButton->setEnabled(false);
    ui_->mineButton->setEnabled(false);
    ui_->assignBWButton->setEnabled(false);
    ui_->assignMinerButton->setEnabled(false);
    ui_->assignSaboteurButton->setEnabled(false);

    // The object that has been clicked on the game map
    recentObject_ = gameObject;

    // Checks if the player has been clicked on the empty tile on map
    if (gameObject->getType() == "Forest" ||
            gameObject->getType() == "Grassland" ||
            gameObject->getType() == "Water" ||
            gameObject->getType() == "CornField" ||
            gameObject->getType() == "Rock") {

        // The tile that has been clicked on the map
        recentTile_ = objectManager_->getTile(gameObject->getCoordinate());

        // This building is for checking if building can be placed on tile
        std::shared_ptr<Course::PlaceableGameObject> building =
                std::make_shared<Course::PlaceableGameObject>(GEHandler_,
                                                 objectManager_, playerOnTurn_);

        // Checks if the clicked tile is not another player's
        if (building->canBePlacedOnTile(recentTile_)) {
            if (recentTile_->getType() == "Water") {
                // Checks if there is enought resources for building a Boat
                if (GEHandler_->isObjectAtHand(playerOnTurn_,
                                 Student::ConstResourceMaps::BOAT_BUILD_COST)) {
                    ui_->boatButton->setEnabled(true);
                }
            } else if (recentTile_->getType() == "Rock") {
                // Checks if there is enought resources for building a Mine
                if (GEHandler_->isObjectAtHand(playerOnTurn_,
                                 Student::ConstResourceMaps::MINE_BUILD_COST)) {
                    ui_->mineButton->setEnabled(true);
                }
            } else {
                // Checks if there is enought resources for building a HeadQuarters
                if (GEHandler_->isObjectAtHand(playerOnTurn_,
                                 Student::ConstResourceMaps::HQ_BUILD_COST)) {
                    ui_->HQButton->setEnabled(true);
                }
                // Checks if there is enought resources for building an Outpost
                if (GEHandler_->isObjectAtHand(playerOnTurn_,
                                 Student::ConstResourceMaps::OUTPOST_BUILD_COST)) {
                    ui_->outpostButton->setEnabled(true);
                }
                // Checks if there is enought resources for building a Farm
                if (GEHandler_->isObjectAtHand(playerOnTurn_,
                                 Student::ConstResourceMaps::FARM_BUILD_COST)) {
                    ui_->farmButton->setEnabled(true);
                }
            }
        }
    }
    // Checks if the player has been clicked on a building where can be placed
    // a worker
    else if (gameObject->getType() == "Farm" ||
               gameObject->getType() == "Boat" ||
               gameObject->getType() == "Mine") {
        // The tile that has been clicked on the map
        recentTile_ = objectManager_->getTile(gameObject->getCoordinate());

        // Checks if the tile has an owner
        if (recentTile_->getOwner() != nullptr) {
            // Checks if the tile is owned by the player on turn
            if (recentTile_->getOwner() == playerOnTurn_) {
                // Checks if the BasicWorker can be added on the current tile
                // and if there is enough resources for hiring a BasicWorker
                if ((gameObject->getType() == "Farm" ||
                        gameObject->getType() == "Boat") &&
                        GEHandler_->isObjectAtHand(playerOnTurn_,
                                 Student::ConstResourceMaps::BW_RECRUITMENT_COST)) {
                    ui_->assignBWButton->setEnabled(true);
                }
                // Checks if the Miner can be added on the current tile
                // and if there is enough resources for hiring a Miner
                else if (gameObject->getType() == "Mine" &&
                           GEHandler_->isObjectAtHand(playerOnTurn_,
                                 Student::ConstResourceMaps::MINER_RECRUITMENT_COST)) {
                    ui_->assignMinerButton->setEnabled(true);
                }
            }
            // If the tile is owned by another player
            else {
                // Checks if the Saboteur can be added on the current tile
                // and if there is enough resources for hiring a Saboteur
                if (gameObject->getType() == "Farm" &&
                        GEHandler_->isObjectAtHand(playerOnTurn_,
                                 Student::ConstResourceMaps::SABOTEUR_RECRUITMENT_COST)) {
                    ui_->assignSaboteurButton->setEnabled(true);
                }
            }
        }
    }
}

void MainWindow::on_HQButton_clicked() {
    std::shared_ptr<Course::HeadQuarters> headQuarters =
            std::make_shared<Course::HeadQuarters>(GEHandler_,
                                             objectManager_, playerOnTurn_);
    GEHandler_->modifyResources(playerOnTurn_, Student::ConstResourceMaps::HQ_BUILD_COST);
    addBuilding(headQuarters);
}

void MainWindow::on_outpostButton_clicked() {
    std::shared_ptr<Course::Outpost> outpost =
            std::make_shared<Course::Outpost>(GEHandler_,
                                             objectManager_, playerOnTurn_);
    GEHandler_->modifyResources(playerOnTurn_, Student::ConstResourceMaps::OUTPOST_BUILD_COST);
    addBuilding(outpost);
}

void MainWindow::on_farmButton_clicked() {
    std::shared_ptr<Course::Farm> farm =
            std::make_shared<Course::Farm>(GEHandler_,
                                             objectManager_, playerOnTurn_);
    GEHandler_->modifyResources(playerOnTurn_, Student::ConstResourceMaps::FARM_BUILD_COST);
    addBuilding(farm);
}

void MainWindow::on_boatButton_clicked() {
    std::shared_ptr<Student::Boat> boat =
            std::make_shared<Student::Boat>(GEHandler_,
                                             objectManager_, playerOnTurn_);
    GEHandler_->modifyResources(playerOnTurn_, Student::ConstResourceMaps::BOAT_BUILD_COST);
    addBuilding(boat);
}

void MainWindow::on_mineButton_clicked() {
    std::shared_ptr<Student::Mine> mine =
            std::make_shared<Student::Mine>(GEHandler_,
                                             objectManager_, playerOnTurn_);
    GEHandler_->modifyResources(playerOnTurn_, Student::ConstResourceMaps::MINE_BUILD_COST);
    addBuilding(mine);
}

void MainWindow::on_assignBWButton_clicked() {
    std::shared_ptr<Course::BasicWorker> basicWorker =
            std::make_shared<Course::BasicWorker>(GEHandler_,
                                             objectManager_, playerOnTurn_);

    GEHandler_->modifyResources(playerOnTurn_, Student::ConstResourceMaps::BW_RECRUITMENT_COST);
    addWorker(basicWorker);
}

void MainWindow::on_assignMinerButton_clicked() {
    std::shared_ptr<Student::Miner> miner =
            std::make_shared<Student::Miner>(GEHandler_,
                                             objectManager_, playerOnTurn_);

    GEHandler_->modifyResources(playerOnTurn_, Student::ConstResourceMaps::MINER_RECRUITMENT_COST);
    addWorker(miner);
}

void MainWindow::on_assignSaboteurButton_clicked() {
    std::shared_ptr<Student::Saboteur> saboteur =
            std::make_shared<Student::Saboteur>(GEHandler_,
                                             objectManager_, playerOnTurn_);
    GEHandler_->modifyResources(playerOnTurn_, Student::ConstResourceMaps::SABOTEUR_RECRUITMENT_COST);

    // Saboteur subtracts another player's resources
    if (playerOnTurn_ == player1_) {
        GEHandler_->modifyResources(player2_, Student::ConstResourceMaps::SABOTEUR_HARM_COST);
    } else {
        GEHandler_->modifyResources(player1_, Student::ConstResourceMaps::SABOTEUR_HARM_COST);
    }

    saboteur->setCoordinate(recentTile_->getCoordinate());

    scene_->drawItem(saboteur);

    // There is nothing to be done after turn is used
    ui_->assignSaboteurButton->setEnabled(false);

    updateTextLabels();

    turnUsed_ = true;
    ui_->infoDisplayLabel->setText("Your turn ended");
}

void MainWindow::on_endTurnButton_clicked() {
    if (playerOnTurn_ == player1_) {
        playerOnTurn_ = player2_;
    } else {
        playerOnTurn_ = player1_;
    }

    turnUsed_ = false;

    std::vector<std::shared_ptr<Course::TileBase>> tiles = objectManager_->getAllTiles();

    // Adds resources for player if there is production on farm, boat or mine
    for (std::shared_ptr<Course::TileBase> tile : tiles) {
        // Checks if there is a worker on tile
        if (tile->getWorkers().size() != 0) {
            // Checks if tile's building's owner is the player on turn
            if (tile->getBuildings().at(0)->getOwner() == playerOnTurn_) {
                if (tile->getBuildings().at(0)->getType() == "Farm") {
                    GEHandler_->modifyResources(playerOnTurn_,
                                      Student::ConstResourceMaps::FARM_PRODUCTION);
                } else if (tile->getBuildings().at(0)->getType() == "Boat") {
                    GEHandler_->modifyResources(playerOnTurn_,
                                      Student::ConstResourceMaps::BOAT_PRODUCTION);
                } else if (tile->getBuildings().at(0)->getType() == "Mine") {
                    GEHandler_->modifyResources(playerOnTurn_,
                                      Student::ConstResourceMaps::MINE_PRODUCTION);
                }
            }
        }
    }
    // Initializing UI-buttons
    ui_->HQButton->setEnabled(false);
    ui_->outpostButton->setEnabled(false);
    ui_->farmButton->setEnabled(false);
    ui_->boatButton->setEnabled(false);
    ui_->mineButton->setEnabled(false);
    ui_->assignBWButton->setEnabled(false);
    ui_->assignMinerButton->setEnabled(false);
    ui_->assignSaboteurButton->setEnabled(false);

    updateTextLabels();
    ui_->infoDisplayLabel->setText("Click the map for adding objects");
}

void MainWindow::on_endGameButton_clicked() {
    StartDialog* startDialog = new StartDialog;

    // Sends a message
    if (winner_ == nullptr) {
        startDialog->setMessage("Last game didn't have a winner");
    } else if (winner_ == player1_) {
        startDialog->setMessage("Last game was won by player 1");
    } else {
        startDialog->setMessage("Last game was won by player 2");
    }
    // Opens a new StartDialog and closes the MainWindow
    startDialog->show();
    close();
}

void MainWindow::on_guideButton_clicked() {
    // Opens a GuideDialog
    GuideDialog* guideDialog = new GuideDialog;
    guideDialog->show();
}
