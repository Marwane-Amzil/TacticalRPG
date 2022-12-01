#pragma once

#ifndef __WINDOWCLASS_H__
#define __WINDOWCLASS_H__

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>

class WindowClass : sf::Window{
	public:
		WindowClass();
	private :
		typedef sf::Window super;
};

#endif