#pragma once
#include <GUI/ui/States/PlayState.hpp>

class RenderWindow;
class Texture;
class Sprite;

class ChoosePlay : public PlayState
{
public :
	ChoosePlay(StateMachine& machine, sf::RenderWindow& window, bool replace = true);
	void pause() override;
	void resume() override;

	void update() override;
	void draw() override;
};

