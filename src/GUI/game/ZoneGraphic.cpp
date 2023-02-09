#include <GUI/game/ZoneGraphic.hpp>
#include <GUI/game/EntitySprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <GUI/game/World.hpp>
#include <Skill.hpp>
#include <Entity.hpp>
#include <Constants.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>


gui::ZoneGraphic::ZoneGraphic(sf::RenderTarget& target)
	: _shape(), _character()
{
	window_x = target.getSize().x;
	window_y = target.getSize().y;
}



std::vector<sf::Sprite*> gui::ZoneGraphic::getSprites() const
{
	return _actionSprites;
}

void gui::ZoneGraphic::showMovingZones(Character* character, Grid& grid)
{
	char color = character->getPlayer();
	std::string startCirclePath = "assets/images/ZoneGraphic/";
	std::string endCirclePath =  "lueZone.png";
	std::string path = startCirclePath + color + endCirclePath;
	_actionsTexture.loadFromFile(path);
	_actionSprites.clear();

	for (Position& pos : character->getPossibleMoves(grid))
	{
		std::cout << _actionSprites.size() << std::endl;

		int pos_window_x =  (pos.getX() * 50 + (0.24 * window_x)) + 10;
		int pos_window_y =  (pos.getY() * 50 + (0.04 * window_y)) + 11;
		std::cout << character->getPlayer();


		sf::Sprite* _sprite = new sf::Sprite();
		_sprite->setTexture(_actionsTexture);
		_sprite->setTextureRect(sf::IntRect(0, 0, 30, 28));
		_sprite->setPosition(pos_window_x, pos_window_y);
		_actionSprites.push_back(_sprite);
	}
}


sf::RectangleShape gui::ZoneGraphic::getShape() const
{
	return _shape;
}



void gui::ZoneGraphic::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_shape, states);
	//target.clear();

	for (int i = 0; i < _actionSprites.size(); i++)
	{
		target.draw(*_actionSprites[i], states);
	}
	
	//target.draw(_spriteTest);
}
