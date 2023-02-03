#include <GUI/game/ActionsGraphic.hpp>
#include <GUI/game/EntitySprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <Entity.hpp>
#include <Constants.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>


gui::ActionsGraphic::ActionsGraphic(sf::RenderTarget& target)
	: _shape(), _actionSprites()
{
	
	_actionsTexture.loadFromFile("assets/images/actionsGraphics/gallerybutton_selecthover_blank.png");
	
	

	auto [x, y] = target.getSize();
	
	float background_width = (1000.0 / 1920) * x;
	float background_height = (1000.0 / 1080) * y;
	
	float width_choice = (x - (background_width))/2;
	for (int i = 0; i < 6; i++)
	{
		sf::Sprite* _spire = new sf::Sprite();
		_spire->setTexture(_actionsTexture);
		_spire->setTextureRect(sf::IntRect(0, 0,223 , 50));
		_spire->setPosition(i+50, i*50+(background_height - 6*50));
		_actionSprites[i] = _spire;
	}
	
	//_shape.setSize(sf::Vector2f(223,6*50));
	//_shape.setPosition(50, 6*50 + ((background_height - 6 * 50)));
}


void gui::ActionsGraphic::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_shape, states);
	//target.clear();

	for (int i = 0; i < 6; i++)
	{
		target.draw(*_actionSprites[i], states);
	}
	
}
