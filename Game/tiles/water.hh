#ifndef WATER_HH
#define WATER_HH

#include "tiles/tilebase.h"
#include "myresourcemaps.hh"

namespace Student {

/**
 * @brief The Water class represents water in the gameworld.
 *
 * Water has BasicProduction if there is a boat and a basic worker on tile:
 * * Money: 40
 * * Food: 30
 * * Wood: 10
 * * Stone: 80
 * * Ore: 10
 *
 * Tile supports 1 building.
 * Only a Boat can be built on a Water tile.
 */
class Water : public Course::TileBase
{
public:
    /**
     * @brief Disabled parameterless constructor.
     */
    Water() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param location is the Coordinate where the Tile is located in the game.
     * @param eventhandler points to the student's GameEventHandler.
     */
    Water(const Course::Coordinate& location,
           const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
           const std::shared_ptr<Course::iObjectManager>& objectmanager,
           const unsigned int& max_build = 1,
           const unsigned int& max_work = 2,
           const Course::ResourceMap& production = ConstResourceMaps::WATER_BP);

    /**
     * @brief Default destructor.
     */
    virtual ~Water() = default;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;

    /**
     * @brief Adds a Boat to the tile. Building on water adds
     * one hold-marker to the building.
     *
     * Phases: \n
     * 1. Check that there is space for the boat. \n
     * 2. Call parent's addBuilding \n
     * 3. Add a HoldMarker for the boat. \n
     *
     * @post Exception guarantee: Strong
     * @exception OwnerConflict - If the tile's ownership prevents placing the
     * \b building.
     * @exception NoSpace - If the tile doesn't have enough space for
     * the \b building.
     */
    void addBuilding(const std::shared_ptr<Course::BuildingBase>& building) override;

}; // class Water

} // namespace Student

#endif // WATER_HH
