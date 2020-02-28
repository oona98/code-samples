#include <QColor>
#include <QPainter>

#include "mapitem.hh"
#include "core/playerbase.h"
#include "tiles/tilebase.h"

namespace Student {

const std::map<std::string, QColor> MAPCOLORS = {
    {"Forest", QColor(118, 173, 124)},
    {"Grassland", QColor(198, 247, 171)},
    {"CornField", QColor(255, 248, 184)},
    {"Rock", QColor(228, 219, 226)},
    {"Water", QColor(191, 255, 252)}};

MapItem::MapItem(const std::shared_ptr<Course::GameObject>& obj, int size) :
    gameObject_(obj),
    sceneLocation_(gameObject_->getCoordinatePtr()->asQpoint()),
    size_(size) {
}

QRectF MapItem::boundingRect() const {
    return QRectF(sceneLocation_ * size_, sceneLocation_ * size_ + QPoint(size_, size_));
}

void MapItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    Q_UNUSED( option );
    Q_UNUSED( widget );

    QRectF target = boundingRect();

    if (gameObject_->getType() == "Forest" ||
             gameObject_->getType() == "Grassland" ||
             gameObject_->getType() == "CornField" ||
             gameObject_->getType() == "Rock" ||
             gameObject_->getType() == "Water") {
        painter->setBrush(QBrush(MAPCOLORS.at(gameObject_->getType())));

        if (gameObject_->getOwner() != nullptr) {
            if (gameObject_->getOwner()->getName() == "Player 1") {
                painter->setPen(QPen(QColor(0, 0, 0), 5));
            } else if (gameObject_->getOwner()->getName() == "Player 2") {
                painter->setPen(QPen(QColor(90, 49, 89), 5));
            }
            painter->drawRect(boundingRect().x(),
                                  boundingRect().y(),
                                  boundingRect().width(),
                                  boundingRect().height());
        }
    }

    if (gameObject_->getType() == "HeadQuarters" ||
            gameObject_->getType() == "Outpost" ||
            gameObject_->getType() == "Farm" ||
            gameObject_->getType() == "Boat" ||
            gameObject_->getType() == "Mine" ||
            gameObject_->getType() == "BasicWorker" ||
            gameObject_->getType() == "Miner" ||
            gameObject_->getType() == "Saboteur") {
        paintImage(&target, gameObject_->getType(), painter);
    }
    painter->drawRect(boundingRect());
}

const std::shared_ptr<Course::GameObject>& MapItem::getBoundObject() {
    return gameObject_;
}

void MapItem::setSize(int size) {
    if ( size > 0 && size <= 500 ){
        size_ = size;
    }
}

void MapItem::paintImage(QRectF* target, std::string imageType, QPainter* painter) {
    if (gameObject_->getOwner()->getName() == "Player 1") {
        if (imageType == "HeadQuarters") {
            QImage img_hq(":/images/hq1.png");
            painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
            painter->drawImage(*target, img_hq);
        } else if (imageType == "Outpost"){
            QImage img_hq(":/images/outpost1.png");
            painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
            painter->drawImage(*target, img_hq);
        } else if (imageType == "Farm"){
            QImage img_hq(":/images/farm1.png");
            painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
            painter->drawImage(*target, img_hq);
        } else if (imageType == "Boat"){
            QImage img_hq(":/images/boat1.png");
            painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
            painter->drawImage(*target, img_hq);
        } else if (imageType == "Mine"){
            QImage img_hq(":/images/mine1.png");
            painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
            painter->drawImage(*target, img_hq);
        } else if (imageType == "BasicWorker"){
            QImage img_hq(":/images/worker1.png");
            painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
            painter->drawImage(*target, img_hq);
        } else if (imageType == "Miner"){
            QImage img_hq(":/images/miner1.png");
            painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
            painter->drawImage(*target, img_hq);
        } else if (imageType == "Saboteur"){
            QImage img_hq(":/images/saboteur1.png");
            painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
            painter->drawImage(*target, img_hq);
        }
    } else if (gameObject_->getOwner()->getName() == "Player 2") {
        if (imageType == "HeadQuarters") {
            QImage img_hq(":/images/hq2.png");
            painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
            painter->drawImage(*target, img_hq);
        } else if (imageType == "Outpost"){
            QImage img_hq(":/images/outpost2.png");
            painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
            painter->drawImage(*target, img_hq);
        } else if (imageType == "Farm"){
            QImage img_hq(":/images/farm2.png");
            painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
            painter->drawImage(*target, img_hq);
        } else if (imageType == "Boat"){
            QImage img_hq(":/images/boat2.png");
            painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
            painter->drawImage(*target, img_hq);
        } else if (imageType == "Mine"){
            QImage img_hq(":/images/mine2.png");
            painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
            painter->drawImage(*target, img_hq);
        } else if (imageType == "BasicWorker"){
            QImage img_hq(":/images/worker1.png");
            painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
            painter->drawImage(*target, img_hq);
        } else if (imageType == "Miner"){
            QImage img_hq(":/images/miner1.png");
            painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
            painter->drawImage(*target, img_hq);
        } else if (imageType == "Saboteur"){
            QImage img_hq(":/images/saboteur1.png");
            painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
            painter->drawImage(*target, img_hq);
        }
    }
}

} // namespace Student
