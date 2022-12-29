#include <iostream>
#include <Grid.hpp>
#include <Entities/Characters/MagicCharacters/Mage.hpp>
#include <Skills/MagicalSkills/Fireball.hpp>
#include <Constants.hpp>

int main(int argc, char* argv[])
{
	Mage* mage = new Mage(0, 0, 'B');
	Mage mageTwo(10, 10, 'R');
	Grid grid;
	grid.addEntity(mage);
	grid.addEntity(&mageTwo);
	std::cout << "hp Before" << mageTwo.getHp();
	mage->getFirstSkill();
	mage->setFirstSkill(new Fireball(1000,2, mage,nullptr));
	
	mage->getFirstSkill()->activate(grid,mageTwo);

	std::cout << "\nHp After "<< mageTwo.getHp();

	std::cin.get();

    return 0;
}