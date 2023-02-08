#pragma once

#ifndef __ZONEGRAPHIC_H__
#define __ZONEGRAPHIC_H__
#include <Entity.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics.hpp>
#include <GUI/game/EntitySprite.hpp>
#include <Entities/Character.hpp>
#include <Grid.hpp>
#include <array>
#include <Constants.hpp>

namespace gui
{
	class EntitySprite;

	class ZoneGraphic : public sf::Drawable
	{
	public:

		explicit ZoneGraphic(sf::RenderTarget& target);

		sf::RectangleShape getShape() const;

		//void clean();

		virtual ~ZoneGraphic() = default;

		std::vector<sf::Sprite*> getSprites() const;

		void setZones(Character* character, Grid& grid);

	private:

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:

		Character* _character;
		sf::Font font;
		int window_x;
		int window_y;
		int size = 0;
		
		//sf::Texture _background_texture;
		// Shape du drawable.
		sf::RectangleShape _shape;
		// Background du menu.
		sf::Texture _actionsTexture;
		
		std::vector<sf::Sprite*> _actionSprites;

		std::array<sf::Text, 6> _actionsTexts;


		sf::Sprite _spriteTest;



	};
}

#endif // !__ActionsGraphic_H__