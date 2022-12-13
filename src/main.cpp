#include <iostream>
#include <Grid.hpp>
#include <Entities/Characters/MagicCharacters/Mage.hpp>
#include <Skills/MagicalSkills/Fireball.hpp>
#include <Constants.hpp>

int main(int argc, char* argv[])
{
	Mage* mage = new Mage(0, 0, 'B');
	Mage* mageTwo = new Mage(1, 1, 'R');
	
	
	std::cout << "hp Before" << mageTwo->getHp();
	mage->getFirstSkill();
	mage->setFirstSkill(new Fireball(1, 1, nullptr));
	
	mage->getFirstSkill()->activate(mageTwo);

	std::cout << "Hp After "<< mageTwo->getHp();
	
	
	std::cout << typeid(mage->getFirstSkill()).name();

	std::cin.get();

    return 0;
}