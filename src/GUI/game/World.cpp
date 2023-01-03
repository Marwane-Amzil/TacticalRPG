#include <GUI/game/World.hpp>
#include <GUI/game/EntitySprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <Entity.hpp>

gui::World::World()
	: _shape(), _sprites() {}

void gui::World::addEntity(gui::EntitySprite* sprite)
{
	int x = sprite->getEntity()->getPosition().getX();
	int y = sprite->getEntity()->getPosition().getY();

	_grid.addEntity(sprite->getEntity());
	_sprites[x][y] = sprite;
	_sprites[x][y]->setPosition(x * 25, y * 35);
}

void gui::World::removeEntity(gui::EntitySprite* sprite)
{
	int x = sprite->getEntity()->getPosition().getX();
	int y = sprite->getEntity()->getPosition().getY();

	delete _sprites[x][y];
	_sprites[x][y] = nullptr;
	_grid[x][y] = nullptr;
}

const Grid& gui::World::getGrid() const
{
	return _grid;
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

gui::World::~World() noexcept
{
	for (size_t i = 0; i < ::grid::ROWS; i++)
	{
		for (size_t j = 0; j < ::grid::COLUMNS; j++)
		{
			delete _sprites[i][j];
		}
	}
}

const std::array<gui::EntitySprite*, ::grid::COLUMNS>& gui::World::operator[](size_t index) const
{
	return _sprites[index];
}

std::array<gui::EntitySprite*, ::grid::COLUMNS>& gui::World::operator[](size_t index)
{
	return _sprites[index];
}