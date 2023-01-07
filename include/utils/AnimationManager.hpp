#pragma once

#ifndef __ANIMATION_MANAGER_H__
#define __ANIMATION_MANAGER_H__

#include <components/AnimationComponent.hpp> // AnimationComponent
#include <map> // std::map
#include <vector> // std::vector
#include <string> // std::string

class AnimationManager
{
public:

	inline AnimationManager() = default;

	inline ~AnimationManager() noexcept = default;

	void loadAnimations();

	std::vector<AnimationComponent> getAnimations() const;

	std::vector<AnimationComponent> getSpecialAnimations(std::string_view type) const;

private:

	std::vector<std::vector<sf::IntRect>> _animations;
	std::map<std::string, std::map<std::string, std::vector<sf::IntRect>>> _specials;
};

#endif // __ANIMATION_MANAGER_H__