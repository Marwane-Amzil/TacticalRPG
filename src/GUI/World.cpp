#include <GUI/World.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <Entity.hpp>

gui::World::World()
	: _shape(), _sprites() {}

void gui::World::addCharacter(gui::EntitySprite* sprite)
{
	int x = sprite->getEntity()->getPosition().getX();
	int y = sprite->getEntity()->getPosition().getY();

	_sprites[x][y] = sprite;
	_sprites[x][y]->setTextureRect(sf::IntRect(0, 710, 50, 60));
}

inline gui::World::~World() noexcept
{
	for (size_t i = 0; i < ::grid::ROWS; i++)
	{
		for (size_t j = 0; j < ::grid::COLUMNS; j++)
		{
			delete _sprites[i][j];
		}
	}
}

void gui::World::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_shape, states);
	
	for (size_t i = 0; i < ::grid::ROWS; i++)
	{
		for (size_t j = 0; j < ::grid::COLUMNS; j++)
		{
			if (_sprites[i][j])
			{
				target.draw(*_sprites[i][j], states);
			}
		}
	}
}
