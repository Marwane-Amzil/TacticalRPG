#pragma once

#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

/**
* The Constants.hpp file has the role of stocking different Constants. 
* The Tactical-RPG Project is a game developement Project. This project involves having a lot of fixed values. 
* Throughout coding having One place where all those different constants are stocked seems to be the best solution for us.
* Using different namespaces gives the possibility to seperate the diffenrent variable by where they are needed, without having to add new variable names where they have the same function.
* When wantting to use this file you use :
*   - using namespace constants_className;
* in the header file.
*/

// -- GRID --
namespace grid
{
    constexpr size_t ROWS = 20;
    constexpr size_t COLUMNS = 20;
}
// -- Mage --
namespace mage
{
    constexpr int MOVES = 3;
    constexpr int NEG_MOVES = -2;
}

// -- Healer --
namespace healer
{
    constexpr int MOVES = 4;
    constexpr int NEG_MOVES = -3;
}

// -- Warior --
namespace warrior
{
    constexpr int MOVES = 5;
    constexpr int NEG_MOVES = -4;
}

// -- Knight --
namespace knight
{
    constexpr int MOVES = 6;
    constexpr int NEG_MOVES = -5;
}

// -- archer --
namespace archer
{
    constexpr int MOVES = 4;
    constexpr int NEG_MOVES = -3;
}

namespace skill
{
	constexpr size_t MAX_SKILLS = 3;
}

namespace fireball
{
	constexpr int DAMAGE = 20;
	constexpr int RANGE = 3;
	constexpr int NEG_RANGE = -2;
}

namespace axeskill
{
    constexpr int DAMAGE = 20;
    constexpr int RANGE = 5;
    constexpr int NEG_RANGE = -4;
}

#endif //!__CONSTANTS_H__