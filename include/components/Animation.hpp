#pragma once

#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include <SFML/Graphics/Rect.hpp> // sf::IntRect
#include <SFML/System/Time.hpp> // sf::Time
#include <vector> // std::vector

struct Animation
{
	std::vector<sf::IntRect> frames;
	sf::Time frame_time;
	bool is_looping;
	std::size_t current_frame;

	explicit Animation(sf::Time frame_time, bool is_looping = true) : frame_time(frame_time), is_looping(is_looping), current_frame(0) {}
};

#endif // !__ANIMATION_H__