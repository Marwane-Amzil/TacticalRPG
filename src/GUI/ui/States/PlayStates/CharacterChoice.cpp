#include <GUI/ui/States/PlayStates/CharacterChoice.hpp>
#include <GUI/game/EntitySprite.hpp>
#include <Entities.hpp>
#include <iostream>
#include <GUI/ui/States/PlayState.hpp>


CharacterChoice::CharacterChoice(StateMachine& machine, sf::RenderWindow& window, bool replace)
: super(machine, window, replace)
{
	_animationManager.loadAnimations();
    //_spriteFactory.createCharacter(new Healer(2, 2, 'Rs'));
	int nb = 0;
	char color = 'B';
	float multiy = 0.8f;
	float multyx = 0.1f;
	auto [x, y] = _window.getSize();

	for (size_t i = 0; i < 2; i++){
		for (auto characterName : _m_characterNames){
			
			m_characters[nb].setTexture(_textureManager.getTextureAt(color, characterName));
			m_characters[nb].setPosition(multyx * x,  multiy * y);
			m_characters[nb].setTextureRect(sf::IntRect(70, 650, 50, 50));
			m_characters[nb].setScale(2.8, 2.8);
			
			multiy = multiy - 0.2;
			if (multiy < 0) {
				multiy = 0.8;
			}
			nb++;
			if (nb == 5){
				color = 'R';
				multyx = 0.83;
			}
		}
	}
	

	
}

void CharacterChoice::pause()
{
}

void CharacterChoice::resume()
{
}

void CharacterChoice::update()
{
	/*for (sf::Event event = sf::Event(); _window.pollEvent(event);)
	{

	}
	for (auto character : m_characters)
	{
		character.update(_clock.getElapsedTime());
	}
	*/
}

void CharacterChoice::draw()
{
    _window.clear();
    _window.draw(_world);
	for (auto character : m_characters)
	{
		_window.draw(character);

	}
    _window.display();
}
