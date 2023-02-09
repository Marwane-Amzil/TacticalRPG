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

// -- Grid --
namespace grid
{
    static constexpr size_t ROWS = 20;
    static constexpr size_t COLUMNS = 20;
}
// -- Mage --
namespace mage
{
    static constexpr int MOVES = 3;
    static constexpr int NEG_MOVES = -3;
}

// -- Healer --
namespace healer
{
    static constexpr int MOVES = 4;
    static constexpr int NEG_MOVES = -4;
}

// -- Warrior --
namespace warrior
{
    static constexpr int MOVES = 4;
    static constexpr int NEG_MOVES = -4;
}

// -- Knight --
namespace knight
{
    static constexpr int MOVES = 5;
    static constexpr int NEG_MOVES = -5;
}

// -- Archer --
namespace archer
{
    static constexpr int MOVES = 3;
    static constexpr int NEG_MOVES = -3;
}

namespace skill
{
	static constexpr size_t MAX_SKILLS = 3;
}

namespace fireball
{
	static constexpr int DAMAGE = 20;
    static constexpr int AOE_RANGE_X = 3;
	static constexpr int AOE_RANGE_Y = 3;
    static constexpr int RANGE_X = 10;
    static constexpr int RANGE_Y = 10;
	//static constexpr bool IS_DIAG = true;
	static constexpr int NEG_RANGE_X = -10;
    static constexpr int NEG_RANGE_Y = -10;

}

namespace axeskill
{
    static constexpr int DAMAGE = 13;
    static constexpr int RANGE_X = 2;
	static constexpr int RANGE_Y = 2;
	//static constexpr bool IS_DIAG = true;
	static constexpr int NEG_RANGE_X = -2;
    static constexpr int NEG_RANGE_Y = -2;
}

namespace swordskill
{
    static constexpr int DAMAGE = 20;
	static constexpr int RANGE_X = 2;
	static constexpr int RANGE_Y = 2;
	//static constexpr bool IS_DIAG = false;
    static constexpr int NEG_RANGE_X = -2;
    static constexpr int NEG_RANGE_Y = -2;
}

namespace bowshot
{
    static constexpr int DAMAGE = 13;
    static constexpr int RANGE_X = 7;
    static constexpr int RANGE_Y = 7;
    //static constexpr bool IS_DIAG = true;
    static constexpr int NEG_RANGE_X = -2;
    static constexpr int NEG_RANGE_Y = -2;
}

#endif //!__CONSTANTS_H__