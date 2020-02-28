#ifndef BOAT_HH
#define BOAT_HH

#include "buildings/buildingbase.h"
#include "myresourcemaps.hh"

namespace Student {

/**
 * @brief The Boat class represents a boat-building in the game.
 *
 * A boat can be placed on a Water tile.
 *
 * Building a boat requires resources:
 * * Wood: 600
 *
 * Boat has production if there is a basic worker on a boat:
 * * Money: 40
 * * Food: 30
 * * Wood: 10
 * * Stone: 80
 * * Ore: 10
 */
class Boat : public Course::BuildingBase
{
public:
    /**
     * @brief Disabled parameterless constructor.
     */
    Boat() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param eventhandler points to the student's GameEventHandler.
     * @param owner points to the owning player.
     * @param tile points to the tile upon which the building is constructed.
     *
     * @post Exception Guarantee: No guarantee.
     * @exception OwnerConflict - if the building conflicts with tile's
     * ownership.
     */
    explicit Boat(
            const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
            const std::shared_ptr<Course::iObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& buildcost = ConstResourceMaps::BOAT_BUILD_COST,
            const Course::ResourceMap& production = ConstResourceMaps::BOAT_PRODUCTION
            );

    /**
     * @brief Default destructor.
     */
    virtual ~Boat() = default;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;

}; // class Boat

} // namespace Student

#endif // BOAT_HH
