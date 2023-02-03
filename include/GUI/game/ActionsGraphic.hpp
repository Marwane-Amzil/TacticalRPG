#pragma once

#ifndef __ACTIONSGRAPHIC_H__
#define __ACTIONSGRAPHIC_H__
#include <Entity.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics.hpp>
#include <GUI/game/EntitySprite.hpp>
#include <Grid.hpp>
#include <array>
#include <Constants.hpp>

namespace gui
{
	class EntitySprite;

	class ActionsGraphic : public sf::Drawable
	{
	public:

		explicit ActionsGraphic(sf::RenderTarget& target);

		//sf::RectangleShape getShape() const;

		//void clean();

		virtual ~ActionsGraphic() = default;

	private:

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:
		
		Entity* _character;
		
		//sf::Texture _background_texture;
		// Shape du drawable.
		sf::RectangleShape _shape;
		// Background du menu.
		sf::Texture _actionsTexture;
		std::array<sf::Sprite*, 6> _actionSprites;
		
		std::array<sf::Text, 6> _actionsTexts;

		
		
		
		
	};
}

#endif // !__ActionsGraphic_H__