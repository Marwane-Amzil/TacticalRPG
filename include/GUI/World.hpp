#pragma once

#ifndef __WORLD_H__
#define __WORLD_H__

#include <SFML/Graphics/RectangleShape.hpp>
#include <GUI/EntitySprite.hpp>
#include <array>
#include <Constants.hpp>

class Grid;

namespace gui
{
	class World : public sf::Drawable
	{
	public:

		explicit World();

		void addCharacter(EntitySprite* sprite);

		virtual inline ~World() noexcept;

	private:

		void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override;

	private:

		sf::RectangleShape _shape;
		std::array<std::array<EntitySprite*, ::grid::ROWS>, ::grid::COLUMNS> _sprites;
	};
}

#endif // !__WORLD_H__