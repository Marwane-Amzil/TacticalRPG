#include <iostream>
#include <Entities/Characters/MagicCharacters/Mage.hpp>
#include <Skills/MagicalSkills/Fireball.hpp>
#include <Skills/PhysicalSkills/SwordSkill.hpp>
#include <Constants.hpp>
#include <Grid.hpp>
#include <Entities/Obstacle.hpp>
int main(int argc, char* argv[])
{
	// Declaration 
	Mage* mage = new Mage(2, 2, 'B');
	Mage* mageTwo = new Mage(3, 2, 'R');
	Mage* mageThree = new Mage(3, 2, 'R');
	//Obstacle* obstacle = new Obstacle(3, 2, 100);
	
	SwordSkill* swordskill = new SwordSkill(10, 2, mage, nullptr);
	Grid grid;
	
	grid.addEntity(mage);
	grid.addEntity(mageTwo);
	grid.addEntity(mageThree);
	//grid.addEntity(obstacle);
	//grid.display();

	/*std::cout << "hp mageTwo Before" << mageTwo.getHp();
	std::cout << "\nhp mageThree Before" << mageThree.getHp();*/

	mage->getFirstSkill();
	mage->setFirstSkill(swordskill);
	std::vector<Position> possibleZones = mage->getFirstSkill()->getPossibleZones(grid);

	for (const Position& position : possibleZones) {
		std::cout << "\n" << position.getX() << " " << position.getY();
	}
	//mage->getFirstSkill()->activate(grid,mageTwo);

	
	
	
	/*std::cout << "\nHp mageTwo After "<< mageTwo.getHp();
	std::cout << "\nhp mageThree After" << mageThree.getHp();*/


	//std::cout << mage->getMagic();
	
	std::cin.get();

	return 0;
}

