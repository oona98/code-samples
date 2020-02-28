#ifndef GAMESCENE_HH
#define GAMESCENE_HH

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsObject>
#include <QDebug>

#include "core/gameobject.h"

namespace Student {

const std::pair<int, int> SCENE_WIDTH_LIMITS = {1, 100};
const std::pair<int, int> SCENE_HEIGHT_LIMITS = {1, 100};
const std::pair<int, int> SCENE_SCALE_LIMITS = {1, 500};

/**
 * @brief The GameScene is a QGraphicsScene that shows
 * a rendering of the game map.
 */
class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    /**
     * @brief Constructor for the class.
     *
     * @param qt_parent points to the parent object per Qt's parent-child-system.
     * @param width in tiles for the game map.
     * @param height in tiles for the game map.
     * @param scale is the size in pixels of a single square tile.
     *
     * @pre 0 < width <= 100 && 0 < height <= 100 && 0 < scale <= 500. Otherwise
     * default values are used for the created object.
     */
    GameScene(QWidget* qt_parent = nullptr,
                    int width = 6,
                    int height = 6,
                    int scale = 80);

    /**
     * @brief Default destructor.
     */
    ~GameScene() = default;

    /**
     * @brief Sets the map size and calls resize().
     * @param width in tiles.
     * @param height in tiles.
     * @pre width and height must each be between 1 and 100.
     * @post width and height are set to given sizes.
     * @post Exception guarantee: No-throw
     */
    void setSize(int width, int height);

    /**
     * @brief set the tile size, aka scale of the map and calls resize().
     * Function behaviour after objects has been drawn is not specified.
     * @param scale in pixels.
     * @pre 0 < scale <= 500
     * @post Scene scale is set to scale.
     * @post Exception guarantee: None
     */
    void setScale(int scale);

    /**
     * @brief resize recalculates the bounding rectangle
     */
    void resize();

    /**
     * @brief get the size of the map.
     * @return pair<width, height> in tiles.
     * @post Exception guarantee: No-throw
     */
    std::pair<int,int> getSize() const;

    /**
     * @brief draw a new item to the map.
     * @param obj shared ptr to the object
     * @pre obj must have a valid coordinate property.
     * @post Exception guarantee: None
     */
    void drawItem( std::shared_ptr<Course::GameObject> obj);

    /**
     * @brief simple event handler that notifies when objects or the play
     * area is clicked and emits signal mapClicked
     * @param event that has happened.
     * @return bool: QGraphicsScene::event(event);
     */
    virtual bool event(QEvent* event) override;

signals:
    /**
     * @brief mapClicked sends a signal to MainWindow when user clicks the map
     * @param gameObject is the GameObject which has been clicked
     */
    void mapClicked(std::shared_ptr<Course::GameObject> gameObject);

private:
    QGraphicsItem* mapBoundRect_; // Bounding rectangle of the GameScene
    int width_; // Width of GameScene in Tiles
    int height_; // Height of the GameScene in Tiles
    int scale_; // Size of one Tile in pixels
};

} // namespace Student

#endif // GAMESCENE_HH
