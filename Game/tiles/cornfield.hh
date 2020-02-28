#ifndef CORNFIELD_HH
#define CORNFIELD_HH

#include "tiles/tilebase.h"
#include "myresourcemaps.hh"

namespace Student {

/**
 * @brief The CornField class represents corn field in the gameworld.
 *
 * CornField has BasicProduction if there is a farm and a basic worker on tile::
 * * Money: 10
 * * Food: 20
 * * Wood: 10
 * * Stone: 10
 * * Ore: 20
 *
 * Tile supports 1 building
 * Only a Farm can be built on a CornField tile
 */
class CornField : public Course::TileBase
{
public:
    /**
     * @brief Disabled parameterless constructor.
     */
    CornField() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param location is the Coordinate where the Tile is located in the game.
     * @param eventhandler points to the student's GameEventHandler.
     */
    CornField(const Course::Coordinate& location,
           const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
           const std::shared_ptr<Course::iObjectManager>& objectmanager,
           const unsigned int& max_build = 1,
           const unsigned int& max_work = 2,
           const Course::ResourceMap& production = ConstResourceMaps::CORNFIELD_BP);

    /**
     * @brief Default destructor.
     */
    virtual ~CornField() = default;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;

    /**
     * @brief Adds a new building-object to the tile. Building on corn field adds
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

}; // class CornField

} // namespace Student

#endif // CORNFIELD_HH
