#include <iostream>
#include <Grid.hpp>
#include <Entities/Characters/MagicCharacters/Mage.hpp>
#include <Skills/MagicalSkills/Fireball.hpp>
#include <Constants.hpp>

int main(int argc, char* argv[])
{
	Mage* mage = new Mage(0, 0, 'B');
	Mage mageTwo(1, 1, 'R');
	Grid grid;
	
	std::cout << "hp Before" << mageTwo.getHp();
	mage->getFirstSkill();
	mage->setFirstSkill(new Fireball(10,10, mage,nullptr));
	
	mage->getFirstSkill()->activate(grid,mageTwo);

	std::cout << "Hp After "<< mageTwo.getHp();
	
	
	//std::cout << typeid(mage->getFirstSkill()).name();

	std::cin.get();

    return 0;
}