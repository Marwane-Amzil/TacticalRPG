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
			m_characters[nb].setScale(2.8f, 2.8f);
			
			multiy = multiy - 0.2f;
			if (multiy < 0) {
				multiy = 0.8f;
			}
			nb++;
			if (nb == 5){
				color = 'R';
				multyx = 0.83f;
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
	


	for (size_t i = 0; i < m_characters.size(); i++)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (m_characters[i].getGlobalBounds().contains(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y))
			{
				int pos_grille_x = static_cast<int>(((sf::Mouse::getPosition(_window).x)-460) / 50) * 50 + 460;
				int pos_grille_y = static_cast<int>(((sf::Mouse::getPosition(_window).y)-40) / 50) * 50 + 40;
				auto [x, y] = _window.getSize();
				std::cout << m_characters[i].getPosition().x << " " << m_characters[i].getPosition().y << std::endl;
				m_characters[i].setScale(1, 1);
				m_characters[i].setPosition(pos_grille_x,pos_grille_y);

			}
		}
	}
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
