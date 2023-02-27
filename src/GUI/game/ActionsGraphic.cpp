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
	font.loadFromFile("assets/ui/menu/font/Roboto-Bold.ttf");

	_actionsTexture.loadFromFile("assets/images/actionsGraphics/gallerybutton_selecthover_blank.png");
	
	

	auto [x, y] = target.getSize();
	
	float background_width = (1000.0 / 1920) * x;
	float background_height = (1000.0 / 1080) * y;
	
	
	float width_choice = (x - (background_width))/2;
		
	for (int i = 0; i < 6; i++)
	{
		sf::Sprite* _sprite = new sf::Sprite();
		_sprite->setTexture(_actionsTexture);
		_sprite->setTextureRect(sf::IntRect(0, 0,400 , 87));
		_sprite->setPosition(i+25, i*87 + (background_height - 6*77));
		_actionSprites[i] = _sprite;
	}

	_actionsTexts[1].setPosition(110, 1 * 77 + (background_height - 6 * 77));
	_actionsTexts[2].setPosition(110, 2 * 77 + (background_height - 6 * 77));

	
}



std::array<sf::Sprite*,6> gui::ActionsGraphic::getSprites() const
{
	return _actionSprites;
}

void gui::ActionsGraphic::setText(Character* character)
{
	
	_actionsTexts[1].setString("ACTIONS");
	_actionsTexts[1].setCharacterSize(25);
	_actionsTexts[1].setFillColor(sf::Color::White);
	_actionsTexts[1].setFont(font);
	
	_actionsTexts[2].setString(character->getFirstSkill()->getName());
	_actionsTexts[2].setCharacterSize(25);
	_actionsTexts[2].setFillColor(sf::Color::White);
	_actionsTexts[2].setFont(font);
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
	target.draw(_actionsTexts[1], states);
	target.draw(_actionsTexts[2], states);


	
	
}
