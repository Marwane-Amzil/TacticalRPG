#pragma once

#ifndef __WORLD_H__
#define __WORLD_H__

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <GUI/game/EntitySprite.hpp>
#include <Grid.hpp>
#include <array>
#include <Constants.hpp>

namespace gui
{
	class EntitySprite;
	

	class World : public sf::Drawable
	{
	public:

		explicit World(sf::RenderTarget& target);

		Grid& getGrid();

		const std::array<std::array<EntitySprite*, ::grid::ROWS>, ::grid::COLUMNS>& getSprites();

		void addEntity(EntitySprite* sprite);

		void removeEntity(EntitySprite* sprite);

		void removeEntity(int x, int y);

		void update();
		
		sf::RectangleShape getShape() const;

		void clean();

		virtual ~World()  = default;

		const std::array<EntitySprite*, ::grid::COLUMNS>& operator[](size_t index) const;
		
		std::array<EntitySprite*, ::grid::COLUMNS>& operator[](size_t index);

	private:

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:


		sf::Texture background_texture;
		gui::EntitySprite background_sprite;
		
		sf::Texture cloud_texture;
		gui::EntitySprite _cloud_sprite;
		sf::Texture desert_texture;
		gui::EntitySprite _desert_sprite;


		sf::RectangleShape _shape;
		Grid _grid;
		std::array<std::array<EntitySprite*, ::grid::ROWS>, ::grid::COLUMNS> _backgroundSprites;

		std::array<std::array<EntitySprite*, ::grid::ROWS>, ::grid::COLUMNS> _sprites;
	};
}

#endif // !__WORLD_H__