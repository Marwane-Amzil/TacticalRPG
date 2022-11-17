#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

/**
* @brief The Constants.hpp File has the role of stocking different Constants. 
* The Tactical-RPG Project is a game developement Project. This project involves having a lot of fixed values. 
* Throughout coding having One place where all those different constants are stocked seems to be the best solution for us.
* Using different namespaces gives the possibility to seperate the diffenrent variable by where they are needed, without having to add new variable names where they have the same function.
* When wantting to use this file you use :
*   - using namespace constants_className;
* in the header file.
*/

// -- GRID --
namespace constants_GRID {
    constexpr int ROWS = 20;
    constexpr int COLUMNS = 20;
}
// -- Mage --
namespace constants_Mage {
    constexpr int HP = 0;
    constexpr int MAGIC_POWER = 0;
    constexpr int STRENGHT_POWER = 0;
    constexpr int MAGIC_RESISTANCE = 0;
    constexpr int PHYSIC_RESISTANCE = 0;
    constexpr int WILL = 0;
    constexpr int MOVES = 0;
}

// -- Healer --
namespace constants_Healer {
    constexpr int HP = 0;
    constexpr int MAGIC_POWER = 0;
    constexpr int STRENGHT_POWER = 0;
    constexpr int MAGIC_RESISTANCE = 0;
    constexpr int PHYSIC_RESISTANCE = 0;
    constexpr int WILL = 0;
    constexpr int MOVES = 0;
}

// -- Warior --
namespace constants_Warrior {
    constexpr int HP = 0;
    constexpr int MAGIC_POWER = 0;
    constexpr int STRENGHT_POWER = 0;
    constexpr int MAGIC_RESISTANCE = 0;
    constexpr int PHYSIC_RESISTANCE = 0;
    constexpr int WILL = 0;
    constexpr int MOVES = 0;
}

// -- Knight --
namespace constants_Knight {
    constexpr int HP = 0;
    constexpr int MAGIC_POWER = 0;
    constexpr int STRENGHT_POWER = 0;
    constexpr int MAGIC_RESISTANCE = 0;
    constexpr int PHYSIC_RESISTANCE = 0;
    constexpr int WILL = 0;
    constexpr int MOVES = 0;
}

// -- Warrior --
namespace constants_Warrior {
    constexpr int HP = 0;
    constexpr int MAGIC_POWER = 0;
    constexpr int STRENGHT_POWER = 0;
    constexpr int MAGIC_RESISTANCE = 0;
    constexpr int PHYSIC_RESISTANCE = 0;
    constexpr int WILL = 0;
    constexpr int MOVES = 0;
}

#endif