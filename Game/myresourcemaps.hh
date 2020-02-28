#ifndef MYRESOURCEMAPS_HH
#define MYRESOURCEMAPS_HH

#include "core/basicresources.h"

namespace Student  {

// Here are consts used in game:

namespace ConstResourceMaps {

// Building - Farm
const Course::ResourceMap FARM_BUILD_COST = {
    {Course::BasicResource::FOOD, -200},
    {Course::BasicResource::STONE, -200}
};
const Course::ResourceMap FARM_PRODUCTION = {
    {Course::BasicResource::MONEY, 10},
    {Course::BasicResource::FOOD, 20},
    {Course::BasicResource::WOOD, 10},
    {Course::BasicResource::STONE, 10},
    {Course::BasicResource::ORE, 20}
};


// Building - HeadQuarters
const Course::ResourceMap HQ_BUILD_COST = {
    {Course::BasicResource::ORE, -1080}
};


// Building - Outpost
const Course::ResourceMap OUTPOST_BUILD_COST = {
    {Course::BasicResource::ORE, -1020}
};


// Building - Mine
const Course::ResourceMap MINE_BUILD_COST = {
    {Course::BasicResource::FOOD, -200},
    {Course::BasicResource::WOOD, -200}
};
const Course::ResourceMap MINE_PRODUCTION = {
    {Course::BasicResource::MONEY, 40},
    {Course::BasicResource::FOOD, 30},
    {Course::BasicResource::WOOD, 10},
    {Course::BasicResource::STONE, 80},
    {Course::BasicResource::ORE, 40}
};


// Building - Boat
const Course::ResourceMap BOAT_BUILD_COST = {
    {Course::BasicResource::WOOD, -600}
};
const Course::ResourceMap BOAT_PRODUCTION = {
    {Course::BasicResource::MONEY, 40},
    {Course::BasicResource::FOOD, 30},
    {Course::BasicResource::WOOD, 10},
    {Course::BasicResource::STONE, 80},
    {Course::BasicResource::ORE, 10}
};


// Worker - BasicWorker
const Course::ResourceMap BW_RECRUITMENT_COST = {
    {Course::BasicResource::MONEY, -100}
};


// Worker - Miner
const Course::ResourceMap MINER_RECRUITMENT_COST = {
    {Course::BasicResource::MONEY, -200}
};
const Course::ResourceMapDouble MINER_WORKER_EFFICIENCY = {
    {Course::BasicResource::MONEY, 0.25},
    {Course::BasicResource::FOOD, 1.00},
    {Course::BasicResource::WOOD, 0.75},
    {Course::BasicResource::STONE, 2.00},
    {Course::BasicResource::ORE, 0.50}
};


// Worker - Saboteur
const Course::ResourceMap SABOTEUR_RECRUITMENT_COST = {
    {Course::BasicResource::FOOD, -200}
};
const Course::ResourceMapDouble SABOTEUR_WORKER_EFFICIENCY = {
    {Course::BasicResource::MONEY, 0.25},
    {Course::BasicResource::FOOD, 1.00},
    {Course::BasicResource::WOOD, 0.75},
    {Course::BasicResource::STONE, 0.50},
    {Course::BasicResource::ORE, 0.50}
};
const Course::ResourceMap SABOTEUR_HARM_COST = {
    {Course::BasicResource::ORE, -200}
};


// Tile - CornField
const Course::ResourceMap CORNFIELD_BP = {
    {Course::BasicResource::MONEY, 0},
    {Course::BasicResource::FOOD, 0},
    {Course::BasicResource::WOOD, 0},
    {Course::BasicResource::STONE, 0},
    {Course::BasicResource::ORE, 0},
};


// Tile - Rock
const Course::ResourceMap ROCK_BP = {
    {Course::BasicResource::MONEY, 0},
    {Course::BasicResource::FOOD, 0},
    {Course::BasicResource::WOOD, 0},
    {Course::BasicResource::STONE, 0},
    {Course::BasicResource::ORE, 0},
};


// Tile - Water
const Course::ResourceMap WATER_BP = {
    {Course::BasicResource::MONEY, 0},
    {Course::BasicResource::FOOD, 0},
    {Course::BasicResource::WOOD, 0},
    {Course::BasicResource::STONE, 0},
    {Course::BasicResource::ORE, 0},
};

} // namespace ConstResourceMaps

} // namespace Student

#endif // MYRESOURCEMAPS_HH
