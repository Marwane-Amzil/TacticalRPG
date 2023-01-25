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
	char color = 'B';
	
	float multiy = 0.83f;
	float multyx = 0.1f;
	
	auto [x, y] = _window.getSize();

	for (size_t i = 0; i < 2; i++){
		for (auto characterName : _m_characterNames){
			m_characters[nb].setTexture(_textureManager.getTextureAt(color, characterName));
			m_characters[nb].setPosition(multyx * x,  multiy * y);
			m_characters[nb].setTextureRect(sf::IntRect(70, 650, 50, 50));
			m_characters[nb].setScale(2.8f, 2.8f);
			
			multiy = multiy - 0.2f;
			nb++;
		}
		color = 'R';
		multyx = 0.8f;
		multiy = 0.83f;
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
	sf::Event event;
	while (_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			_window.close();
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
				_window.close();
		}
	}

	
	auto [x, y] = _window.getSize();
	for (size_t i = 0; i < m_characters.size(); i++)
	{
		if (m_characters[i].getGlobalBounds().contains(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				bool click_looker = false;
				while (!click_looker) {
					sf::Vector2i vector = sf::Mouse::getPosition();
					//std::cout << "sheesh";
					click_looker = ((_world.getShape().getGlobalBounds().contains(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y))) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
				}
				click_looker = false;
				
					int pos_grille_x = static_cast<int>(((sf::Mouse::getPosition(_window).x) - 460) / 50) * 50 + 460;
					int pos_grille_y = static_cast<int>(((sf::Mouse::getPosition(_window).y) - 40) / 50) * 50 + 40;
					
					
					std::cout << pos_grille_x << " " << pos_grille_y << std::endl;
					m_characters[i].setScale(0.8, 0.8);
					m_characters[i].setPosition(pos_grille_x, pos_grille_y);
					//_world.addEntity(&m_characters[i]);

			}
		}
	}
	
}



/*
bool click_looker = false;
while (!click_looker) {
	sf::Vector2i vector = sf::Mouse::getPosition();

	click_looker = (sf::Mouse::getPosition(_window).x < static_cast<int>(0.93 * x)) && (sf::Mouse::getPosition(_window).x > static_cast<int>(0.83 * x)) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		_window.close();
	}
}
click_looker = false;
*/

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
