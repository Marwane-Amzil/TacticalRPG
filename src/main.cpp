#include <iostream>
#include <Grid.hpp>
#include <Entities.hpp>
#include <Skills.hpp>
#include <Constants.hpp>

int main(int argc, char* argv[])
{
	Entity* mage = new Mage(0, 0, 'B');
	
	std::cout << dynamic_cast<Character*>(mage)->getFirstSkill() << '\n';
	dynamic_cast<Character*>(mage)->setFirstSkill(new Fireball(1, 1, nullptr));
	std::cout << dynamic_cast<Character*>(mage)->getFirstSkill() << '\n';

	std::cin.get();

    return 0;
}