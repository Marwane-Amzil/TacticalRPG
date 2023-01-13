#pragma once

#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include <SFML/Graphics/Rect.hpp> // sf::IntRect
#include <SFML/System/Time.hpp> // sf::Time
#include <vector> // std::vector

struct AnimationComponent
{
	std::vector<sf::IntRect> frames;
	sf::Time frame_time;
	sf::Time current_time;
	bool is_playing;
	bool is_looping;
	std::size_t current_frame;

	inline explicit AnimationComponent(const std::vector<sf::IntRect>& _Frames, sf::Time _FrameTime, bool is_looping = true) :
		frames(_Frames), frame_time(_FrameTime), current_time(), is_playing(true), is_looping(is_looping), current_frame(0) {}
};

#endif // !__ANIMATION_H__