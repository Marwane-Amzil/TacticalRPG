#include <iostream>
#include <Entities/Characters/MagicCharacters/Mage.hpp>
#include <Skills/MagicalSkills/Fireball.hpp>
#include <Skills/PhysicalSkills/SwordSkill.hpp>
#include <Constants.hpp>
#include <Grid.hpp>

int main(int argc, char* argv[])
{
	// Declaration 
	Mage* mage = new Mage(0, 0, 'B');
	Mage mageTwo(3, 3, 'R');
	Mage mageThree(11, 11, 'R');
	Fireball* fireball = new Fireball(10, 2, mage, nullptr);
	Grid grid;
	SwordSkill* swordskill = new SwordSkill(10, 2, &mageTwo, nullptr);
	
	std::vector<Position> possibleZones = swordskill->getPossibleZones(grid);
	for (const Position& position : possibleZones) {
		std::cout << "\nswordskill" << position.getX() << " ; " << position.getY() << std::endl;
	}
	grid.addEntity(mage);
	grid.addEntity(&mageTwo);
	grid.addEntity(&mageThree);
	//grid.display();
	std::cout << "hp mageTwo Before" << mageTwo.getHp();
	std::cout << "\nhp mageThree Before" << mageThree.getHp();

	mage->getFirstSkill();
	mage->setFirstSkill(fireball);

	mage->getFirstSkill()->activate(grid,mageTwo);
	
	std::string test = typeid(fireball).name();
	/*if (test == "class Fireball * __ptr64")
	{
		std::cout << typeid(mageTwo).name() << std::endl;
	}
	else
	{
		std::cout << "nope" << std::endl;
	}*/
	std::cout << "\nHp mageTwo After "<< mageTwo.getHp();
	std::cout << "\nhp mageThree After" << mageThree.getHp();


	//std::cout << mage->getMagic();
	
	std::cin.get();

	return 0;
}

