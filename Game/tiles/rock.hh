#ifndef ROCK_HH
#define ROCK_HH

#include "tiles/tilebase.h"
#include "myresourcemaps.hh"

namespace Student {

/**
 * @brief The Rock class represents rock in the gameworld.
 *
 * Rock has BasicProduction if there is a mine and a miner on tile:
 * * Money: 40
 * * Food: 30
 * * Wood: 10
 * * Stone: 80
 * * Ore: 40
 *
 * Tile supports 1 building
 * Only a Mine can be built on a Rock tile
 */
class Rock : public Course::TileBase
{
public:
    /**
     * @brief Disabled parameterless constructor.
     */
    Rock() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param location is the Coordinate where the Tile is located in the game.
     * @param eventhandler points to the student's GameEventHandler.
     */
    Rock(const Course::Coordinate& location,
           const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
           const std::shared_ptr<Course::iObjectManager>& objectmanager,
           const unsigned int& max_build = 1,
           const unsigned int& max_work = 2,
           const Course::ResourceMap& production = ConstResourceMaps::ROCK_BP);

    /**
     * @brief Default destructor.
     */
    virtual ~Rock() = default;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;

    /**
     * @brief Adds a new building-object to the tile. Building on rock adds
     * one hold-marker to the building.
     *
     * Phases: \n
     * 1. Check that there is space for the building. \n
     * 2. Call parent's addBuilding \n
     * 3. Add a HoldMarker for the building. \n
     *
     * @post Exception guarantee: Strong
     * @exception OwnerConflict - If the tile's ownership prevents placing the
     * \b building.
     * @exception NoSpace - If the tile doesn't have enough space for
     * the \b building.
     */
    void addBuilding(const std::shared_ptr<Course::BuildingBase>& building) override;

}; // class Rock

} // namespace Student

#endif // ROCK_HH
