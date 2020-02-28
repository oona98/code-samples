#ifndef MINE_HH
#define MINE_HH

#include "buildings/buildingbase.h"
#include "myresourcemaps.hh"

namespace Student {

/**
 * @brief The Mine class represents a mine-building in the game.
 *
 * A mine can be placed on a Rock tile.
 *
 * Building a mine requires resources:
 * * Food: 200
 * * Wood: 200
 *
 * Mine has production if there is a miner on a mine:
 * * Money: 40
 * * Food: 30
 * * Wood: 10
 * * Stone: 80
 * * Ore: 40
 */
class Mine : public Course::BuildingBase
{
public:
    /**
     * @brief Disabled parameterless constructor.
     */
    Mine() = delete;

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
    explicit Mine(
            const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
            const std::shared_ptr<Course::iObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& buildcost = ConstResourceMaps::MINE_BUILD_COST,
            const Course::ResourceMap& production = ConstResourceMaps::MINE_PRODUCTION
            );

    /**
     * @brief Default destructor.
     */
    virtual ~Mine() = default;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;

}; // class Mine

} // namespace Student


#endif // MINE_HH
