#pragma once

#ifndef __WORLD_H__
#define __WORLD_H__

#include <SFML/Graphics/RectangleShape.hpp>
#include <Grid.hpp>
#include <array>
#include <Constants.hpp>

namespace gui
{
	class EntitySprite;
	
	class World : public sf::Drawable
	{
	public:

		explicit World();

		const Grid& getGrid() const;

		void addEntity(EntitySprite* sprite);

		void removeEntity(EntitySprite* sprite);

		virtual ~World() noexcept;

		const std::array<EntitySprite*, ::grid::COLUMNS>& operator[](size_t index) const;
		
		std::array<EntitySprite*, ::grid::COLUMNS>& operator[](size_t index);

	private:

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:

		sf::RectangleShape _shape;
		Grid _grid;
		std::array<std::array<EntitySprite*, ::grid::ROWS>, ::grid::COLUMNS> _sprites;
	};
}

#endif // !__WORLD_H__