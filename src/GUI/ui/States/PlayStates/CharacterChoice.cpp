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
	
	float multiy = 0.83f;
	float multyx = 0.1f;
	
	auto [x, y] = _window.getSize();


	//met les différentes textures dans m_characters_blue/red
	for (auto characterName : _m_characterNames){
		m_characters_blue[nb].setTexture(_textureManager.getTextureAt('B', characterName));
		m_characters_blue[nb].setPosition(multyx * x,  multiy * y);
		m_characters_blue[nb].setTextureRect(sf::IntRect(70, 650, 50, 50));
		m_characters_blue[nb].setScale(2.8f, 2.8f);
		multiy = multiy - 0.2f;
		nb++;
	}

	multyx = 0.8f;
	multiy = 0.83f;
	nb = 0;
	for (auto characterName : _m_characterNames) {
	
		m_characters_red[nb].setTexture(_textureManager.getTextureAt('R', characterName));
		m_characters_red[nb].setPosition(multyx * x, multiy * y);
		m_characters_red[nb].setTextureRect(sf::IntRect(70, 650, 50, 50));
		m_characters_red[nb].setScale(2.8f, 2.8f);
		multiy = multiy - 0.2f;
		nb++;

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
	if (count == 1)
		{
			_machine.run(StateMachine::build<ChoosePlay>(_machine, _window, _world, _textureManager, true));

		}
	
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
			
		}
	}
	

	


	auto [x, y] = _window.getSize();

	
	bool click_looker = false;
	
	int j = 0;
	while (!click_looker) {
		j = (j + 1) % 5;
		if (color_looker == 0) {
			click_looker = (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_characters_blue[j].getGlobalBounds().contains(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y));
		}
		else if (color_looker == 1) {
			click_looker = (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_characters_red[j].getGlobalBounds().contains(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y));

		}
		else {
			click_looker = 1;
		}
		
	}


	if (m_characters_blue[j].getGlobalBounds().contains(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y) && color_looker== 0)
	{

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			click_looker = false;
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
				
			
			
				
			

			switch (j)
			{
			case 0 :
				_CurrentCharacter = _spriteFactory.createCharacter(new Warrior(pos_grid_x, pos_grid_y, 'B'));
				break;
			case 1 :
				_CurrentCharacter = _spriteFactory.createCharacter(new Archer(pos_grid_x, pos_grid_y, 'B'));
				break;
			case 2:
				_CurrentCharacter = _spriteFactory.createCharacter(new Knight(pos_grid_x, pos_grid_y, 'B'));
				break;
			case 3:
				_CurrentCharacter = _spriteFactory.createCharacter(new Healer(pos_grid_x, pos_grid_y, 'B'));
				break;
			default:
				_CurrentCharacter = _spriteFactory.createCharacter(new Mage(pos_grid_x, pos_grid_y, 'B'));
				break;
			}

			
			
			//_CurrentCharacter->update(_clock.getElapsedTime());
			//_clock.restart();
		}
	}


	if (m_characters_red[j].getGlobalBounds().contains(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y) && color_looker == 1)
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

			int pos_grille_x = static_cast<int>(((sf::Mouse::getPosition(_window).x) - (0.24 * x)) / 50) * 50 + (0.24 * x);
			int pos_grille_y = static_cast<int>(((sf::Mouse::getPosition(_window).y) - (0.04 * y)) / 50) * 50 + (0.04 * y);

			int pos_grid_x = static_cast<int>(((sf::Mouse::getPosition(_window).x) - (0.24 * x)) / 50);
			int pos_grid_y = static_cast<int>(((sf::Mouse::getPosition(_window).y) - (0.04 * y)) / 50);

		





			switch (j)
			{
			case 0:
				_CurrentCharacter = _spriteFactory.createCharacter(new Warrior(pos_grid_x, pos_grid_y, 'R'));
				break;
			case 1:
				_CurrentCharacter = _spriteFactory.createCharacter(new Archer(pos_grid_x, pos_grid_y, 'R'));
				break;
			case 2:
				_CurrentCharacter = _spriteFactory.createCharacter(new Knight(pos_grid_x, pos_grid_y, 'R'));
				break;
			case 3:
				_CurrentCharacter = _spriteFactory.createCharacter(new Healer(pos_grid_x, pos_grid_y, 'R'));
				break;
			default:
				_CurrentCharacter = _spriteFactory.createCharacter(new Mage(pos_grid_x, pos_grid_y, 'R'));
				break;
			}



			//_CurrentCharacter->update(_clock.getElapsedTime());
			//_clock.restart();
		}
	}

	switch (color_looker) {

	case 0 :
		color_looker = 1;
		count++;

		break;
	case 1 :
		color_looker = 0;
		count++;

		break;
	default:
		color_looker = 0;
		break;
	}
	

}// End Update()



void CharacterChoice::draw()
{
    _window.clear();
    _window.draw(_world);
	for (auto character : m_characters_blue)
	{
		_window.draw(character);

	}
	for (auto character : m_characters_red)
	{
		_window.draw(character);

	}
    _window.display();
}
