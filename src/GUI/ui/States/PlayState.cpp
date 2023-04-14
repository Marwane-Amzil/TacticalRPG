#include <iostream>
#include <memory>
#include <stdexcept>
#include <GUI/ui/States/PlayState.hpp>
#include <GUI/ui/StateMachine.hpp>
#include <GUI/ui/States/MenuState.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <GUI/game/EntitySprite.hpp>
#include <array>


PlayState::PlayState(StateMachine& machine, sf::RenderWindow& window, gui::World& world, utils::TextureManager& texture_manager, iut::ClientSocket& client, const bool replace)
	: State(machine, window, replace), _world(world), _textureManager(texture_manager), _client(client) {}