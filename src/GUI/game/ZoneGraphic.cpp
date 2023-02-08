#include <GUI/game/ZoneGraphic.hpp>
#include <GUI/game/EntitySprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <Skill.hpp>
#include <Entity.hpp>
#include <Constants.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>


gui::ZoneGraphic::ZoneGraphic(sf::RenderTarget& target)
	: _shape(), _actionSprites(), _character()
{
	window_x = target.getSize().x;
	window_y = target.getSize().y;
	
	font.loadFromFile("assets/ui/menu/font/ethn.otf");

	_actionsTexture.loadFromFile("assets/images/ZoneGraphic/BlueZone.png");
	
	_spriteTest.setTexture(_actionsTexture);
	_spriteTest.setTextureRect(sf::IntRect(0, 0, 500, 500));
	_spriteTest.setPosition(0, 0);
	
	auto [x, y] = target.getSize();

}



std::vector<sf::Sprite*> gui::ZoneGraphic::getSprites() const
{
	return _actionSprites;
}

void gui::ZoneGraphic::setZones(Character* character, Grid& grid)
{
	
	for (const Position& pos : character->getPossibleMoves(grid))
	{

		_actionsTexture.loadFromFile("assets/images/ZoneGraphic/BlueZone.png");

		float background_width = (1000.0 / 1920) * window_x;
		float background_height = (1000.0 / 1080) * window_y;
		
		int pos_window_x = (pos.getX() * 50 ) + background_width ;
		int pos_window_y = (pos.getY() * 50 ) + background_height ;

		std::cout << pos_window_x << "   " << pos_window_y<< std::endl;
		
		size = character->getPossibleMoves(grid).size();
		for (int i = 0; i < size ; i++)
		{
			sf::Sprite* _sprite = new sf::Sprite();
			_sprite->setTexture(_actionsTexture);
			_sprite->setTextureRect(sf::IntRect(0, 0, 50, 48));
			_sprite->setPosition(pos_window_x, pos_window_x);
			_actionSprites.push_back(_sprite);
		}
		
		
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
