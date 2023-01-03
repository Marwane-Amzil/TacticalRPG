#include <iostream>
#include <Entities.hpp>
#include <Skills.hpp>
#include <Constants.hpp>
#include <Grid.hpp>
#include <Entities/Obstacle.hpp>
int main(int argc, char* argv[])
{
	// Declaration 
	Archer* warrior = new Archer(2, 2, 'B');
	Archer* mageTwo = new Archer(3, 2, 'R');
	Warrior* mageThree = new Warrior(4, 2, 'R');
	//Obstacle* obstacle = new Obstacle(3, 2, 100);
	
	SwordSkill* swordskill = new SwordSkill(10, 2, warrior, nullptr);
	Grid grid;
	
	grid.addEntity(warrior);
	grid.addEntity(mageTwo);
	grid.addEntity(mageThree);
	//grid.addEntity(obstacle);
	//grid.display();

	std::cout << "hp mageTwo Before" << mageTwo->getHp();
	std::cout << "\nhp mageThree Before" << mageThree->getHp();

	warrior->getFirstSkill();
	warrior->setFirstSkill(swordskill);
	std::vector<Position> possibleZones = warrior->getFirstSkill()->getPossibleZones(grid);

	for (const Position& position : possibleZones) {
		std::cout << "\n" << position;
	}
	warrior->getFirstSkill()->activate(grid,mageTwo);

	
	
	
	std::cout << "\nHp mageTwo After "<< mageTwo->getHp();
	std::cout << "\nhp mageThree After" << mageThree->getHp();


	//std::cout << Warrior->getMagic();
	
	std::cin.get();

	return 0;
}

