#include <iostream>
#include <Grid.hpp>
#include <Entities/Characters/MagicCharacters/Mage.hpp>
#include <Entities/Characters/PhysicalCharacters/Warrior.hpp>
#include <Entities/Obstacle.hpp>
#include <constants.hpp>
#include <GUI/Sheets/Menu/Menu.hpp>

using namespace gui;
int main(int argc, char* argv[])
{
    Menu* menu = new Menu();
    menu->run_menu();
    delete menu;
    menu = nullptr;
    /*
    * Grid plateau;
    plateau[0][0] = new Mage(0, 0, 'B');
    plateau[1][1] = new Warrior(1, 1, 'B');
    plateau[2][2] = new Obstacle(2, 2, 50);

    for (const Position& position : dynamic_cast<Character*>(plateau[0][0])->getPossibleMoves(plateau))
    {
        std::cout << position << std::endl;
    }
        
    std::cin.get();
    */
    
    return EXIT_SUCCESS;
    return 0;
}