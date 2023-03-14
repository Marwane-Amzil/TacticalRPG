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

void gui::ZoneGraphic::showMovingZones(sf::RenderTarget& target, Character* character, Grid& grid)
{
	char color = character->getPlayer();
	std::string startCirclePath = "assets/images/ZoneGraphic/";
	std::string endCirclePath =  "lueZone.png";
	std::string path = "assets/images/ZoneGraphic/BlueZone.png";
	_actionsTexture.loadFromFile(path);
	_moovementSprites.clear();
	_attackSprites.clear();

	for (Position& pos : character->getPossibleMoves(grid))
	{

		int pos_window_x =  (pos.getX() * 50 + (0.24 * window_x)) + 10;
		int pos_window_y =  (pos.getY() * 50 + (0.04 * window_y)) + 11;

		sf::Sprite* _sprite = new sf::Sprite();
		_sprite->setTexture(_actionsTexture);
		_sprite->setTextureRect(sf::IntRect(0, 0, 30, 28));
		_sprite->setPosition(pos_window_x, pos_window_y);
		_moovementSprites.push_back(_sprite);
		target.draw(*_sprite);

	}
}


void gui::ZoneGraphic::showAttackZones(sf::RenderTarget& target, const Skill* skill, Grid& grid)
{
	char color = skill->getOwner()->getPlayer();
	std::string startCirclePath = "assets/images/ZoneGraphic/";
	std::string endCirclePath = "lueZone.png";
	std::string path = "assets/images/ZoneGraphic/BlueZone.png";
	_actionsTexture.loadFromFile(path);
	_attackSprites.clear();
	_moovementSprites.clear();

	for (Position& pos : skill->getPossibleZones(grid))
	{
		int pos_window_x = (pos.getX() * 50 + (0.24 * window_x)) + 10;
		int pos_window_y = (pos.getY() * 50 + (0.04 * window_y)) + 11;

		sf::Sprite* _sprite = new sf::Sprite();
		_sprite->setTexture(_actionsTexture);
		_sprite->setTextureRect(sf::IntRect(0, 0, 30, 28));
		_sprite->setPosition(pos_window_x, pos_window_y);
		_attackSprites.push_back(_sprite);
		target.draw(*_sprite);
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

	for (int i = 0; i < _moovementSprites.size(); i++)
	{
		target.draw(*_moovementSprites[i], states);
	}

	for (int i = 0; i < _attackSprites.size(); i++)
	{
		target.draw(*_attackSprites[i], states);
	}
	
	//target.draw(_spriteTest);
}
