#include "GUI/WindowClass.hpp"
WindowClass::WindowClass() : super(sf::VideoMode(800, 600), "Tactical", sf::Style::Titlebar | sf::Style::Close)
{
	setVerticalSyncEnabled(true);

};