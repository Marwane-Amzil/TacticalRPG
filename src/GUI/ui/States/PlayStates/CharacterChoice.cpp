#include <GUI/ui/States/PlayStates/CharacterChoice.hpp>
#include <iostream>
#include <GUI/ui/States/PlayState.hpp>


CharacterChoice::CharacterChoice(StateMachine& machine, sf::RenderWindow& window, bool replace)
: super(machine, window, replace){
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
    _window.draw(getWorld());
    _window.display();
}
