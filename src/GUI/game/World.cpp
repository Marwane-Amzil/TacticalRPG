#include <GUI/game/World.hpp>
#include <GUI/game/EntitySprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <Entity.hpp>
#include <Constants.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>

gui::World::World(sf::RenderTarget& target)
	: _shape(), _grid(), _backgroundSprites() , _sprites()
{	
	auto[x, y] = target.getSize();

	float background_width = (1000.0 / 1920) * x;
	float background_height = (1000.0 / 1080) * y;

	//std::cout << "\nwidth : " << background_width << "						height : " << background_height;


	background_texture.loadFromFile("assets/images/background.png", sf::IntRect(0, 0, static_cast<int>(background_width / 19), static_cast<int>(background_height / 19)));
	background_sprite.setTexture(&background_texture);

	

	int basic_x_pos = static_cast<int>(0.24 * x);
	int basic_y_pos = static_cast<int>(0.04 * y);

	
	_shape.setSize(sf::Vector2f(19 * static_cast<int>(background_height / 20 ) + basic_y_pos , 19 * static_cast<int>(background_height / 20) + basic_y_pos));
	_shape.setPosition(basic_x_pos, basic_y_pos);

	

	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 20; ++j) {
			background_sprite.setPosition(i * static_cast<int>(background_width / 20) + basic_x_pos,
				j * static_cast<int>(background_height / 20) + basic_y_pos);
			_backgroundSprites[i][j] = new EntitySprite(background_sprite);
		}
	}
	
	
}


void gui::World::addEntity(gui::EntitySprite* sprite)
{
	int x = sprite->getEntity()->getPosition().getX();
	int y = sprite->getEntity()->getPosition().getY();

	_grid.addEntity(sprite->getEntity());
	
	int pos_world_x = sprite->getPosition().x;      
	int pos_world_y = sprite->getPosition().y;
	
	_sprites[x][y] = sprite;
	_sprites[x][y]->setPosition(pos_world_x, pos_world_y);
}

void gui::World::removeEntity(gui::EntitySprite* sprite)
{
	int x = sprite->getEntity()->getPosition().getX();
	int y = sprite->getEntity()->getPosition().getY();

	delete _sprites[x][y];
	_sprites[x][y] = nullptr;
	_grid[x][y] = nullptr;
}

void gui::World::removeEntity(int x, int y)
{
	delete _sprites[x][y];
	_sprites[x][y] = nullptr;
	_grid[x][y] = nullptr;
}

Grid& gui::World::getGrid() 
{
	return _grid;
}

const std::array<std::array<gui::EntitySprite*, ::grid::ROWS>, ::grid::COLUMNS>& gui::World::getSprites()
{
	return _sprites;
}


sf::RectangleShape gui::World::getShape() const
{
	return _shape;
}

void gui::World::clean()
{
	for (auto& col : _sprites)
	{
		for (gui::EntitySprite* const& sprite : col)
		{
			if (sprite)
			{
				removeEntity(sprite);
			}
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
			target.draw(*_backgroundSprites[i][j], states);
		}
	}
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

const std::array<gui::EntitySprite*, ::grid::COLUMNS>& gui::World::operator[](size_t index) const
{
	return _sprites[index];
}

std::array<gui::EntitySprite*, ::grid::COLUMNS>& gui::World::operator[](size_t index)
{
	return _sprites[index];
}