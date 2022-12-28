#pragma once

#ifndef __ANIMATION_MANAGER_H__
#define __ANIMATION_MANAGER_H__

#include <map> // std::map
#include <vector> // std::vector
#include <string> // std::string

namespace gui
{
	class Animation;
}

namespace utils
{
	class AnimationManager
	{
	public:

		AnimationManager();

		~AnimationManager() noexcept;
		
		void loadAnimations();

		const std::vector<gui::Animation*>& getAnimations() const;
		
		const gui::Animation& getSpecialAnimation(const std::string& type) const;
		
	private:

		std::vector<gui::Animation*> _animations;
		std::map<std::string, gui::Animation*> _specials;
	};
}

#endif // !__ANIMATION_MANAGER_H__