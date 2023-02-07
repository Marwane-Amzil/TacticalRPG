#include <GUI/game/ActionsGraphic.hpp>
#include <GUI/game/EntitySprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <Skill.hpp>
#include <Entity.hpp>
#include <Constants.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>


gui::ActionsGraphic::ActionsGraphic(sf::RenderTarget& target)
	: _shape(), _actionSprites(), _character()
{
	
	_actionsTexture.loadFromFile("assets/images/actionsGraphics/gallerybutton_selecthover_blank.png");
	
	

	auto [x, y] = target.getSize();
	
	float background_width = (1000.0 / 1920) * x;
	float background_height = (1000.0 / 1080) * y;
	
	
	float width_choice = (x - (background_width))/2;
		
	for (int i = 0; i < 6; i++)
	{
		sf::Sprite* _sprite = new sf::Sprite();
		_sprite->setTexture(_actionsTexture);
		_sprite->setTextureRect(sf::IntRect(0, 0,223 , 50));
		_sprite->setPosition(i+50, i*50+(background_height - 6*50));
		_actionSprites[i] = _sprite;
	}

	_actionsTexts[0].setPosition(50, 2*50 + (background_height - 6 * 50));

	
}



std::array<sf::Sprite*,6> gui::ActionsGraphic::getSprites() const
{
	return _actionSprites;
}

void gui::ActionsGraphic::setText(Character* character)
{
	_actionsTexts[0].setString(character->getFirstSkill()->getName());
	_actionsTexts[0].setCharacterSize(20);
	_actionsTexts[0].setFillColor(sf::Color::Magenta);
}


sf::RectangleShape gui::ActionsGraphic::getShape() const
{
	return _shape;
}



void gui::ActionsGraphic::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_shape, states);
	//target.clear();

	for (int i = 0; i < 6; i++)
	{
		target.draw(*_actionSprites[i], states);
	}
	target.draw(_actionsTexts[0], states);

	
	
}
