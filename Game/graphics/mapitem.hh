#ifndef MAPITEM_HH
#define MAPITEM_HH

#include <QGraphicsItem>

#include "core/gameobject.h"

namespace Student {

/**
 * @brief The MapItem class is a QGraphicsItem that
 * acts as a single GameObject's graphical element in GameScene (map of the game)
 */
class MapItem : public QGraphicsItem
{
public:
    /**
     * @brief Constructor
     * @param obj is a shared_ptr to the game object
     * @param size of the created MapItem in pixels
     * @pre obj must have a valid Coordinate
     */
    MapItem(const std::shared_ptr<Course::GameObject>& obj, int size);

    /**
     * @brief boundingRect gives the bounding rectangle of the MapItem
     * @return the bounding rectangle of this item.
     */
    QRectF boundingRect() const override;

    /**
     * @brief paints the map Item to the game scene
     * @param painter is a pointer to QPainter
     * @param option is a pointer to QStyleOptionGraphicsItem
     * @param widget is a pointer to QWidget
     * @note The GraphicsView containing the scene this belongs to
     * usually calls this function.
     */
    void paint(QPainter* painter,
               const QStyleOptionGraphicsItem* option,
               QWidget* widget);
    /**
     * @brief getBoundObject returns a shared_ptr to GameObject this
     * MapItem is bound to
     * @return the object this item is bound to.
     */
    const std::shared_ptr<Course::GameObject> &getBoundObject();

    /**
     * @brief setSize sets MapItem's size
     * @param size of the object in pixels.
     * @pre 0 < size <= 500
     * @post Exception guarantee: No-throw
     */
    void setSize(int size);

    /**
     * @brief paintImage paints image for a MapItem
     * @param target is a pointer to a target for image to paint
     * @param imageType is type of image to add for MapItem
     * @param painter is a pointer to QPainter
     */
    virtual void paintImage(QRectF* target, std::string imageType, QPainter* painter);

private:
    const std::shared_ptr<Course::GameObject> gameObject_; // GameObject this MapItem is bound to
    QPoint sceneLocation_; // MapItem's location on GameScene
    int size_; // MapItem's size in pixels
};

} // namespace Student

#endif // MAPITEM_HH
