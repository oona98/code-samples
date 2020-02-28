#include "objectmanager.hh"
#include "tiles/tilebase.h"

namespace Student {

void ObjectManager::addTiles
            (const std::vector<std::shared_ptr<Course::TileBase>>& tiles) {
    for (std::shared_ptr<Course::TileBase> tile : tiles) {
        tiles_.push_back(tile);
    }
}

std::shared_ptr<Course::TileBase> ObjectManager::getTile
            (const Course::Coordinate& coordinate) {
    for(std::shared_ptr<Course::TileBase> tile : tiles_) {
        if (tile->getCoordinate() == coordinate) {
            return tile;
        }
    }
    return nullptr;
}

std::shared_ptr<Course::TileBase> ObjectManager::getTile
            (const Course::ObjectId& id) {
    for(std::shared_ptr<Course::TileBase> tile : tiles_) {
        if (tile->ID == id) {
            return tile;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<Course::TileBase>> ObjectManager::getTiles
            (const std::vector<Course::Coordinate> &coordinates) {
    std::vector<std::shared_ptr<Course::TileBase>> right_tiles = {};
    for(Course::Coordinate coordinate : coordinates) {
        if (getTile(coordinate) != nullptr) {
            right_tiles.push_back(getTile(coordinate));
        }
    }
    return right_tiles;
}

std::vector<std::shared_ptr<Course::TileBase> > ObjectManager::getAllTiles() const {
    return tiles_;
}

} // namespace Student
