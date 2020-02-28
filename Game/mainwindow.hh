#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>

#include "interfaces/gameeventhandler.hh"
#include "interfaces/objectmanager.hh"

#include "graphics/gamescene.hh"
#include "core/worldgenerator.h"
#include "core/playerbase.h"


namespace Ui {
class MainWindow;
}

/**
 * @brief The MainWindow class
 */
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    /**
     * @brief MainWindow constructor
     * @param parent is the parent of the MainWindow
     * @param GEHandler associates the given GameEventHandler to the MainWindow
     */
    explicit MainWindow(QWidget *parent = 0,
                       std::shared_ptr<Student::GameEventHandler> GEHandler = {});

    /**
     * @brief MainWindow destructor
     */
    ~MainWindow();

    /**
     * @brief setSize receives the width and the height of the game's map
     * and sets them to the scene.
     * @param width is the width of the game's map
     * @param height is the height of the game's map
     */
    void setSize(int width, int height);

    /**
     * @brief setScale receives the scale of the game's map and sets it to
     * the scene.
     * @param scale is the scale of the tile
     */
    void setScale(int scale);

    /**
     * @brief drawItem adds a new game object to the scene.
     * @param obj is the game object
     */
    void drawItem( std::shared_ptr<Course::GameObject> obj);

    /**
     * @brief updateTextLabels updates info texts of player on turn and
     * player's resources.
     */
    void updateTextLabels();

    /**
     * @brief isGameEnded checks if game is over and changes info text if
     * it the game is over.
     */
    void isGameEnded();

    /**
     * @brief addBuilding adds a building object to the player on turn, to
     * the selected tile and the game scene.
     * @param building is the building object
     */
    void addBuilding(std::shared_ptr<Course::BuildingBase> building);

    /**
     * @brief addWorker adds a worker object to the player on turn, to
     * the selected tile and the game scene.
     * @param worker is the worker object
     */
    void addWorker(std::shared_ptr<Course::WorkerBase> worker);

public slots:
    /**
     * @brief updateButtons is called from the GameScene.
     * This slot updates the UI-buttons to be enabled if they can be clicked
     * after the certain point of the game map has been clicked.
     * @param gameObject is the game object that has been clicked
     */
    void updateButtons(std::shared_ptr<Course::GameObject> gameObject);

private slots:
    /**
     * @brief on_HQButton_clicked is called when user clicks the HQButton.
     * This function calls modifyResources to the player on turn and
     * addBuilding for a new HeadQuarters object.
     */
    void on_HQButton_clicked();

    /**
     * @brief on_outpostButton_clicked is called when user clicks the outpostButton.
     * This function calls modifyResources to the player on turn and
     * addBuilding for a new Outpost object.
     */
    void on_outpostButton_clicked();

    /**
     * @brief on_farmButton_clicked is called when user clicks the farmButton.
     * This function calls modifyResources to the player on turn and
     * addBuilding for a new Farm object.
     */
    void on_farmButton_clicked();

    /**
     * @brief on_boatButton_clicked is called when user clicks the boatButton.
     * This function calls modifyResources to the player on turn and
     * addBuilding for a new Boat object.
     */
    void on_boatButton_clicked();

    /**
     * @brief on_mineButton_clicked is called when user clicks the mineButton.
     * This function calls modifyResources to the player on turn and
     * addBuilding for a new Mine object.
     */
    void on_mineButton_clicked();

    /**
     * @brief on_assignBWButton_clicked is called when user clicks the
     * assignBWButton.
     * This function calls modifyResources to the player on turn and
     * addWorker for a new BasicWorker object.
     */
    void on_assignBWButton_clicked();

    /**
     * @brief on_assignMinerButton_clicked is called when user clicks the
     * assignMinerButton.
     * This function calls modifyResources to the player on turn and
     * addWorker for a new Miner object.
     */
    void on_assignMinerButton_clicked();

    /**
     * @brief on_assignSaboteurButton_clicked is called when user clicks the
     * assignSaboteurButton.
     * This function calls modifyResources to the both of players, drawItem and
     * setCoordinate for a new Saboteur object.
     */
    void on_assignSaboteurButton_clicked();

    /**
     * @brief on_endTurnButton_clicked is called when user clicks the
     * endTurnButton.
     * This function changes the player on turn and updates player's
     * resources if there is production.
     */
    void on_endTurnButton_clicked();

    /**
     * @brief on_endGameButton_clicked is called when user clicks the
     * endGameButton.
     * This function creates a new StartDialog, sends message to StartDialog
     * opens it and closes the MainWindow.
     */
    void on_endGameButton_clicked();

    /**
     * @brief on_guideButton_clicked is called when user clicks the
     * guideButton.
     * This function creates a new GuideDialog and opens it.
     */
    void on_guideButton_clicked();

private:
    Ui::MainWindow* ui_; //  a shared_ptr to user interface
    std::shared_ptr<Student::GameEventHandler> GEHandler_ = nullptr; // a shared_ptr to GameEventHandler
    std::shared_ptr<Student::ObjectManager> objectManager_ = nullptr; // a shared_ptr to ObjectManager
    std::shared_ptr<Student::GameScene> scene_ = nullptr; // a shared_ptr to GameScene
    Course::WorldGenerator* worldGenerator_ = nullptr; // a pointer to WorldGenerator
    std::shared_ptr<Course::PlayerBase> playerOnTurn_ = nullptr; // a shared_ptr to player who's on turn

    std::shared_ptr<Course::PlayerBase> player1_ = nullptr; // a shared_ptr to player 1
    std::shared_ptr<Course::PlayerBase> player2_ = nullptr; // a shared_ptr to player 2
    std::shared_ptr<Course::GameObject> recentObject_ = nullptr; // object that has been clicked recently
    std::shared_ptr<Course::TileBase> recentTile_ = nullptr; // tile that has been clicked recently
    std::shared_ptr<Course::PlayerBase> winner_ = nullptr; // winner of the game
    bool turnUsed_ = false; // true if player has used it's turn
};

#endif // MAINWINDOW_HH
