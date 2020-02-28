#include "gameeventhandler.hh"

namespace Student {

bool GameEventHandler::modifyResource(std::shared_ptr<Course::PlayerBase> player,
                                      Course::BasicResource resource,
                                      int amount) {
    // Checks that player is already in map
    if (resources_.find(player) == resources_.end()) {
        return false;
    } else {
        resources_.at(player).at(resource) += amount;
        return true;
    }
}

bool GameEventHandler::modifyResources(std::shared_ptr<Course::PlayerBase> player,
                                       Course::ResourceMap resources) {
    // Checks that player is already in map
    if (resources_.find(player) == resources_.end()) {
        return false;
    } for (auto resource = resources.begin(); resource != resources.end(); resource++) {
        resources_.at(player).at(resource->first) += resource->second;
    }
    return true;
}

int GameEventHandler::getResourceValue(std::shared_ptr<Course::PlayerBase> player,
                                       Course::BasicResource resource) {
    return resources_.at(player).at(resource);
}

bool GameEventHandler::addPlayer(std::shared_ptr<Course::PlayerBase> player) {
    Course::ResourceMap initResources = {
        {Course::BasicResource::MONEY, 1000},
        {Course::BasicResource::FOOD, 1000},
        {Course::BasicResource::WOOD, 1000},
        {Course::BasicResource::STONE, 1000},
        {Course::BasicResource::ORE, 1000},
    };

    // Checks that player isn't already in map
    if (resources_.find(player) != resources_.end()) {
        return false;
    } else {
        resources_.insert({player, initResources});
        return true;
    }
}

bool GameEventHandler::isObjectAtHand(std::shared_ptr<Course::PlayerBase> player,
                                        Course::ResourceMap resources) {
    for (auto resource = resources.begin(); resource != resources.end(); resource++) {
        if (resources_.at(player).at(resource->first) + resource->second < 0) {
            return false;
        }
    }
    return true;
}

} // namespace Student
