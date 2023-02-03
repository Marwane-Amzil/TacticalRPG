#include <GUI/ui/States/MenuState.hpp>
#include <GUI/ui/StateMachine.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <GUI/ui/States/PlayStates/CharacterChoice.hpp>
#include <iostream>

MenuState::MenuState(StateMachine& machine, sf::RenderWindow& window, gui::World& world, utils::TextureManager& texture_manager, const bool replace)
	: State(machine, window, replace), _world(world), _texture_manager(texture_manager)
{
    _winclose = new sf::RectangleShape();
    _font = new sf::Font();
    _image = new sf::Texture();
    _closingImage = new sf::Texture();

    _pos = 0;
    _pressed = theselect = false;
    _font->loadFromFile("./assets/ui/menu/font/ethn.otf");
    _image->loadFromFile("./assets/ui/menu/img/menu-Play.png");
	_closingImage->loadFromFile("./assets/ui/menu/img/Button-close.png");

    m_background.setTexture(*_image);
    _pos_mouse = { 0,0 };
    _mouse_coord = { 0, 0 };

    // The different containers are linked by the id. option[0] refeeres to coords[0] refeers to size[0]
    _options = { "War Game", "Play", "Options", "About", "Quit" };
    _texts.resize(5);
    _coords = { {460,100},{200,213},{188,295},{200,370},{220,447} };
    _sizes = { 50,28,24,24,24 };

    for (std::size_t i{}; i < _texts.size(); ++i) {
        _texts[i].setFont(*_font);
        _texts[i].setString(_options[i]);
        _texts[i].setCharacterSize(_sizes[i]);
        _texts[i].setOutlineColor(sf::Color::Black);
        _texts[i].setPosition(_coords[i]);
    }
    _texts[1].setOutlineThickness(4);
    _pos = 1;
    
    _winclose->setSize(sf::Vector2f(50, 50));
    _winclose->setPosition(1178, 38);
	_winclose->setTexture(_closingImage);
}

void MenuState::pause()
{
	std::cout << "MenuState Pause\n";
}

void MenuState::resume()
{
	std::cout << "MenuState Resume\n";
}

void MenuState::update()
{
    std::string path;
    sf::Event event;
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _window.close();
        }

        _pos_mouse = sf::Mouse::getPosition(_window);
        _mouse_coord = _window.mapPixelToCoords(_pos_mouse);


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !_pressed) {
            if (_pos < 4) {
                ++_pos;
                _pressed = true;
                _texts[_pos].setOutlineThickness(4);
                _texts[_pos - 1].setOutlineThickness(0);
                _pressed = false;
                theselect = false;
                path = _options[_pos];
                _image->loadFromFile("./assets/ui/menu/img/menu-" + path + ".png");

            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !_pressed) {
            if (_pos > 1) {
                --_pos;
                _pressed = true;
                _texts[_pos].setOutlineThickness(4);
                _texts[_pos + 1].setOutlineThickness(0);
                _pressed = false;
                theselect = false;
                path = _options[_pos];
                _image->loadFromFile("./assets/ui/menu/img/menu-" + path + ".png");

            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect) {
            theselect = true;
            if (_pos == 4) {
                _machine.quit();
            }

			if (_pos == 1) {
				_machine.run(StateMachine::build<CharacterChoice>(_machine, _window, _world, _texture_manager, true));
			}
            std::cout << _options[_pos] << '\n';
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (_winclose->getGlobalBounds().contains(_mouse_coord)) {
                //std::cout << "Close the window!" << '\n';
                _machine.quit();
            }
        }
    }
}

void MenuState::draw()
{
	// Clear the previous drawing
	_window.clear();
    _window.draw(m_background);
    _window.draw(*_winclose);
    for (auto t : _texts) {
        _window.draw(t);
    }
	_window.display();
}
