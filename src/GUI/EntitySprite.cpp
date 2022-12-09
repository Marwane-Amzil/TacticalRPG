#include <GUI/EntitySprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <Entity.hpp>

gui::EntitySprite::EntitySprite(Entity* entity)
	: sf::Sprite(), _entity(entity)
{
	if (_entity)
	{
		int x = _entity->getPosition().getX();
		int y = _entity->getPosition().getY();
		setPosition(x * 75, y * 40);
	}
}

const Entity* gui::EntitySprite::getEntity() const
{
	return _entity;
}