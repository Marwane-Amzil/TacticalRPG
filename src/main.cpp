#include <iostream>
#include <Entities.hpp>
#include <Skills.hpp>
#include <Constants.hpp>
#include <Grid.hpp>
#include <Entities/Obstacle.hpp>
#include <SFML/Graphics.hpp>
#include <GUI/game/World.hpp>
#include <utils/TextureManager.hpp>
#include <utils/AnimationManager.hpp>
#include <utils/SpriteFactory.hpp>
#include <GUI/game/EntitySprite.hpp>

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
	warrior->getFirstSkill()->activate(grid, mageTwo);




	std::cout << "\nHp mageTwo After " << mageTwo->getHp();
	std::cout << "\nhp mageThree After" << mageThree->getHp();


	//std::cout << Warrior->getMagic();

	sf::RenderWindow window(sf::VideoMode(1080, 780), "SFML works!");
	window.setVerticalSyncEnabled(true);
	gui::World world;
	utils::TextureManager textureManager;
	utils::AnimationManager animationManager;
	utils::SpriteFactory spriteFactory(world, textureManager, animationManager);
	std::vector<gui::EntitySprite*> sprites;
	sf::Clock timer;

	sprites.push_back(spriteFactory.createCharacter(new Mage(1, 1, 'R')));
	sprites.push_back(spriteFactory.createCharacter(new Mage(4, 5, 'B')));
	sprites.push_back(spriteFactory.createCharacter(new Knight(7, 7, 'R')));
	sprites.push_back(spriteFactory.createCharacter(new Knight(9, 9, 'B')));
	sprites[0]->setCurrentAnimation(5);
	sprites[0]->playAnimation();
	sprites[0]->loopCurrentAnimation(true);
	sprites[1]->setCurrentAnimation(6);
	sprites[1]->playAnimation();
	sprites[1]->loopCurrentAnimation(true);
	sprites[2]->setCurrentAnimation(7);
	sprites[2]->playAnimation();
	sprites[2]->loopCurrentAnimation(true);
	sprites[3]->setCurrentAnimation(8);
	sprites[3]->playAnimation();
	sprites[3]->loopCurrentAnimation(true);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		for (auto& sprite : sprites)
		{
			sprite->update(timer.getElapsedTime());
			sprite->move(1.f, 0.f);
		}
		
		timer.restart();

		window.clear();
		window.draw(world);
		window.display();
	}

	return 0;
}