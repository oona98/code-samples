#ifndef GAMEEVENTHANDLER_HH
#define GAMEEVENTHANDLER_HH

#include "interfaces/igameeventhandler.h"

namespace Student {

/**
 * @brief The GameEventHandler class is a class for adding players and
 * handling players' resources
 */
class GameEventHandler : public Course::iGameEventHandler {
public:
    /**
     * @brief Default destructor.
     */
    virtual ~GameEventHandler() = default;

    /**
     * @brief Modify Player's resource.
     * @param player Pointer to the Player whose resource is being modified.
     * @param resource Defines the modified resource.
     * @param amount Defines the amount of change.
     * @post Exception guarantee: Basic
     * @return
     * True - Modification was succesful. \n
     * False - Modification failed. \n
     */
    virtual bool modifyResource(std::shared_ptr<Course::PlayerBase> player,
                                Course::BasicResource resource,
                                int amount) final;

    /**
     * @brief Modify Player's resources.
     * @param player Pointer to the Player whose resources are being modified.
     * @param resources ResourceMap containing change amounts.
     * @return
     * True - Modification was succesful. \n
     * False - Modification failed. \n
     */
    virtual bool modifyResources(std::shared_ptr<Course::PlayerBase> player,
                                 Course::ResourceMap resources) final;

    /**
     * @brief getResourceValue gives a value of player's resource
     * @param player is shared_ptr to a player who's in question
     * @param resource which is asked for
     * @return player resource value (int)
     */
    int getResourceValue(std::shared_ptr<Course::PlayerBase> player,
                         Course::BasicResource resource);

    /**
     * @brief addPlayer adds a new player to map and initializes player's
     * resources
     * @param player is a shared_ptr to the player to add
     * @return
     * True - Adding was succesful. \n
     * False - Adding failed. \n
     */
    bool addPlayer(std::shared_ptr<Course::PlayerBase> player);

    /**
     * @brief isObjectAtHand checks if player can afford some GameObject
     * @param player is a shared_ptr to the player who's in question
     * @param resources which the GameObject requires
     * @return
     * True - If player can afford GameObject. \n
     * False - If player can't afford GameObject. \n
     */
    bool isObjectAtHand(std::shared_ptr<Course::PlayerBase> player,
                              Course::ResourceMap resources);

private:
    std::map<std::shared_ptr<Course::PlayerBase>, Course::ResourceMap>
                resources_ = {}; // map that contains players and their resources

}; // class GameEventHandler

} // namespace Student


#endif // GAMEEVENTHANDLER_HH
