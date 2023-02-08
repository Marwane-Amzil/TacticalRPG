#include <GUI/ui/States/PlayStates/CharacterChoice.hpp>
#include <GUI/game/EntitySprite.hpp>
#include <Entities.hpp>
#include <iostream>
#include <GUI/ui/StateMachine.hpp>
#include <GUI/ui/States/MenuState.hpp>
#include <GUI/ui/States/PlayStates/ChoosePlay.hpp>



CharacterChoice::CharacterChoice(StateMachine& machine, sf::RenderWindow& window, gui::World& world, utils::TextureManager& texture_manager, const bool replace)
: super(machine, window, world, texture_manager, replace), _animationManager(), _spriteFactory(_world, texture_manager, _animationManager)
{
	_clock.restart();

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
	std::cout << "pause choice\n";
}

void CharacterChoice::resume()
{
	std::cout << "resume choice\n";
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
			{
				_world.clean();
				_machine.run(StateMachine::build<MenuState>(_machine, _window, _world, _textureManager, true));
			}
			if(event.key.code == sf::Keyboard::Up)
			{
				_machine.run(StateMachine::build<ChoosePlay>(_machine, _window, _world, _textureManager, true));

			}
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
						click_looker = ((_world.getShape().getGlobalBounds().contains(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y))) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
						
					}
					click_looker = false;
						
					// 460 -> espace � gauche grille bords �crans
					// 40 -> espace en haut grille bords �crans
					
					int pos_grille_x = static_cast<int>(((sf::Mouse::getPosition(_window).x)- (0.24 * x)) / 50) * 50 + (0.24 * x);
					int pos_grille_y = static_cast<int>(((sf::Mouse::getPosition(_window).y) - (0.04 * y)) / 50) * 50 + (0.04 * y);
					
					int pos_grid_x = static_cast<int>(((sf::Mouse::getPosition(_window).x) - (0.24 * x)) / 50);
					int pos_grid_y = static_cast<int>(((sf::Mouse::getPosition(_window).y) - (0.04 * y)) / 50);
						
						//std::cout << pos_grille_x << " " << pos_grille_y << std::endl;
						std::cout << pos_grid_x << " et " << pos_grid_y<< std::endl;
					
					//gui::EntitySprite entitySprite(m_characters[i]);
					
						
					char color = 'B';
					if (i >4) {
						color = 'R';
						i -= 5;
					}

					switch (i)
					{
					case 0 :
						_CurrentCharacter = _spriteFactory.createCharacter(new Warrior(pos_grid_x, pos_grid_y, color));
						break;
					case 1 :
						_CurrentCharacter = _spriteFactory.createCharacter(new Archer(pos_grid_x, pos_grid_y, color));
						break;
					case 2:
						_CurrentCharacter = _spriteFactory.createCharacter(new Knight(pos_grid_x, pos_grid_y, color));
						break;
					case 3:
						_CurrentCharacter = _spriteFactory.createCharacter(new Healer(pos_grid_x, pos_grid_y, color));
						break;
					default:
						_CurrentCharacter = _spriteFactory.createCharacter(new Mage(pos_grid_x, pos_grid_y, color));
						break;
					}

					
					
					//_CurrentCharacter->update(_clock.getElapsedTime());
					//_clock.restart();
				}
			}
		}
	
}// End Update()


//_spriteFactory.createCharacter(m_characters[i].getEntity());



/*m_characters[i].setScale(0.8, 0.8);
m_characters[i].setPosition(pos_grille_x, pos_grille_y);
m_characters[i].setPosition(pos_grille_x, pos_grille_y);
*/
//_world.addEntity(&entitySprite);
//_world.addEntity(&m_characters[i]);

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
