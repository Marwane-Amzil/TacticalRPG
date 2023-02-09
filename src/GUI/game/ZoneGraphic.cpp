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

void gui::ZoneGraphic::setZones(Character* character, Grid& grid)
{
	_actionsTexture.loadFromFile("assets/images/ZoneGraphic/BlueZone.png");
	_actionSprites.clear();

	for (Position& pos : character->getPossibleMoves(grid))
	{
		std::cout << _actionSprites.size() << std::endl;

		int pos_window_x =  (pos.getX() * 50 + (0.24 * window_x)) + 10;
		int pos_window_y =  (pos.getY() * 50 + (0.04 * window_y)) + 11;

		//std::cout << world.getShape().getGlobalBounds().getPosition().x << "   " << world.getShape().getGlobalBounds().getPosition().y << std::endl;
		std::cout << pos.getX()*50 << "  j  " << pos.getY()*50 << std::endl;


		std::cout << pos_window_x << "  i   " << pos_window_y << std::endl;
		//std::cout << window_x << "   " << window_y << std::endl;

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
