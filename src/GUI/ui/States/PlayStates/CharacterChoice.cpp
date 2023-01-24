#include <GUI/ui/States/PlayStates/CharacterChoice.hpp>
#include <GUI/game/EntitySprite.hpp>
#include <Entities/Characters/MagicCharacters/Healer.hpp>
#include <iostream>
#include <GUI/ui/States/PlayState.hpp>


CharacterChoice::CharacterChoice(StateMachine& machine, sf::RenderWindow& window, bool replace)
: super(machine, window, replace){
    
    _spriteFactory.createCharacter(new Healer(2, 2, 'Rs'));
    _spriteFactory.createCharacter(new Healer(15, 5, 'R'));

}

void CharacterChoice::pause()
{
}

void CharacterChoice::resume()
{
}

void CharacterChoice::update()
{
}

void CharacterChoice::draw()
{
    _window.clear();
    _window.draw(_world);
    _window.display();
}
