#include <GUI/ui/States/NetworkState.hpp>

NetworkState::NetworkState(StateMachine& machine, sf::RenderWindow& window, gui::World& world, utils::TextureManager& texture_manager, iut::ClientSocket& client, const bool replace)
	: super(machine, window, replace), _world(world), _texture_manager(texture_manager), _client(client) {}
