#include <utils/EntityCreator.hpp> // EntityCreator declarations

EntityCreator::EntityCreator(World& _World) noexcept
	: _world(_World) {}

Entity EntityCreator::create() noexcept
{
	return _world.create();
}
