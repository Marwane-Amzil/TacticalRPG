#include <GUI/ui/States/PlayStates/CharacterChoice.hpp>
#include <GUI/game/EntitySprite.hpp>
#include <Entities.hpp>
#include <iostream>
#include <GUI/ui/States/PlayState.hpp>


CharacterChoice::CharacterChoice(StateMachine& machine, sf::RenderWindow& window, bool replace)
: super(machine, window, replace){
    
    //_spriteFactory.createCharacter(new Healer(2, 2, 'Rs'));
	m_characters[0] = _spriteFactory.createCharacter(new Mage(15, 5, 'B'));
	

	
    //m_characters[1] = _spriteFactory.createCharacter(new Knight(0, 0, 'B'));
	//m_characters[2] = _spriteFactory.createCharacter(new Healer(10, 10, 'B'));
	//m_characters[3] = _spriteFactory.createCharacter(new Warrior(19, 19, 'B'));


	/*m_characters[0]->setCurrentAnimation(5);
	m_characters[0]->playAnimation();
	m_characters[0]->loopCurrentAnimation(true);*/

}

void CharacterChoice::pause()
{
}

void CharacterChoice::resume()
{
}

void CharacterChoice::update()
{
	for (sf::Event event = sf::Event(); _window.pollEvent(event);)
	{

	}
	for (auto character : m_characters)
	{
		character->update(_clock.getElapsedTime());
	}
}

void CharacterChoice::draw()
{
    _window.clear();
    _window.draw(_world);
	for (auto character : m_characters)
	{
		_window.draw(*character);

	}
    _window.display();
}
