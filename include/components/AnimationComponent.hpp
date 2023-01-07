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
	bool is_looping;
	std::size_t current_frame;

	inline explicit AnimationComponent(const std::vector<sf::IntRect>& frames, sf::Time frame_time, bool is_looping = true) :
		frames(frames), frame_time(frame_time), is_looping(is_looping), current_frame(0) {}

	inline AnimationComponent(const AnimationComponent& other) :
		frames(other.frames), frame_time(other.frame_time), is_looping(other.is_looping), current_frame(other.current_frame) {}

	inline AnimationComponent(AnimationComponent&& other) noexcept :
		frames(std::move(other.frames)), frame_time(other.frame_time), is_looping(other.is_looping), current_frame(other.current_frame) {}
};

#endif // !__ANIMATION_H__