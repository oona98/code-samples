#include <QEvent>
#include <QGraphicsSceneMouseEvent>
#include <math.h>

#include "gamescene.hh"
#include "mapitem.hh"

namespace Student {

GameScene::GameScene(QWidget* parent, int width, int height, int scale):
    QGraphicsScene(parent),
    mapBoundRect_(nullptr),
    width_(6),
    height_(6),
    scale_(80) {
    setSize(width, height);
    setScale(scale);
}

void GameScene::setSize(int width, int height) {
    if ( width >= SCENE_WIDTH_LIMITS.first && width <= SCENE_WIDTH_LIMITS.second )
    {
        width_ = width;
    }
    if ( height >= SCENE_HEIGHT_LIMITS.first && height <= SCENE_HEIGHT_LIMITS.second )
    {
        height_ = height;
    }
    resize();
}

void GameScene::setScale(int scale) {
    if ( scale >= SCENE_SCALE_LIMITS.first && scale <= SCENE_SCALE_LIMITS.second )
    {
        scale_ = scale;
    }
    resize();
}

void GameScene::resize() {
    if ( mapBoundRect_ != nullptr ){
        QGraphicsScene::removeItem(mapBoundRect_);
    }

    // Calculates rect with middle at (0,0).
    // Basically left upper corner coords and then width and height
    QRect rect = QRect( 0, 0, width_ * scale_, height_ * scale_);

    addRect(rect, QPen(Qt::black));
    setSceneRect(rect);
    mapBoundRect_ = itemAt(rect.topLeft(), QTransform());
    // Draw on the bottom of all items
    mapBoundRect_->setZValue(-1);
}

std::pair<int, int> GameScene::getSize() const {
    return {width_, height_};
}

void GameScene::drawItem( std::shared_ptr<Course::GameObject> obj) {
    MapItem* nItem = new MapItem(obj, scale_);
    addItem(nItem);
}

bool GameScene::event(QEvent *event) {
    if(event->type() == QEvent::GraphicsSceneMousePress)
    {
        QGraphicsSceneMouseEvent* mouse_event =
                dynamic_cast<QGraphicsSceneMouseEvent*>(event);

        if ( sceneRect().contains(mouse_event->scenePos())){

            QPointF point = mouse_event->scenePos() / scale_;

            point.rx() = floor(point.rx());
            point.ry() = floor(point.ry());

            QGraphicsItem* pressed = itemAt(point * scale_, QTransform());

            if ( pressed != mapBoundRect_ ){
                emit mapClicked(static_cast<MapItem*>(pressed)->getBoundObject());
            }
        }
    }
    return QGraphicsScene::event(event);
}


} // namespace Student
