#ifndef SABOTEUR_HH
#define SABOTEUR_HH

#include "workers/workerbase.h"
#include "myresourcemaps.hh"

namespace Student {

/**
 * @brief The Saboteur class represents a saboteur in the game.
 *
 * Saboteur can be hired on another player's farm.
 * Hiring a saboteur requires food from player who hires it:
 * * Food: 200
 *
 * Another players resources are also reduced:
 * * Ore: 200
 *
 */
class Saboteur : public Course::WorkerBase
{
public:
    /**
     * @brief Disabled parameterless constructor.
     */
    Saboteur() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param eventhandler points to the student's GameEventHandler.
     * @param owner points to the owning player.
     * @param descriptions contains descriptions and flavor texts.
     */
    Saboteur(const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
                const std::shared_ptr<Course::iObjectManager>& objectmanager,
                const std::shared_ptr<Course::PlayerBase>& owner,
                const int& tilespaces = 1,
                const Course::ResourceMap& cost =
                    ConstResourceMaps::SABOTEUR_RECRUITMENT_COST,
                const Course::ResourceMapDouble& efficiency =
                    ConstResourceMaps::SABOTEUR_WORKER_EFFICIENCY
                );

    /**
     * @brief Default destructor.
     */
    virtual ~Saboteur() = default;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;

    /**
     * @brief Check if the worker can be placed on the Tile according to
     * it's placement rule. Only rule is that the Tile must have same owner
     * as the worker.
     * @param target is the Tile that worker is being placed on.
     * @return
     * True - If baseclass' method return true and target Tile has space
     * for worker.
     * False - If both conditions aren't met.
     * @note Override to change placement rules for derived worker.
     * @post Exception guarantee: Basic
     */
    virtual bool canBePlacedOnTile(
            const std::shared_ptr<Course::TileBase> &target) const override;

    /**
     * @brief Performs the Worker's default action.
     */
    virtual void doSpecialAction() override;

    /**
     * @brief Returns Worker's efficiency at resource production.
     * Worker consumes FOOD and MONEY. Resource consumption and resource
     * focus determine final multiplier that is based on WORKER_EFFICIENCY.
     *
     * @return
     */
    virtual const Course::ResourceMapDouble tileWorkAction() override;

private:

}; // class Saboteur

} // namespace Student

#endif // SABOTEUR_HH
