#pragma once

#ifndef __ANIMATION_MANAGER_H__
#define __ANIMATION_MANAGER_H__

#include <map> // std::map
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

		const std::map<std::string, gui::Animation*>& get(const std::string& type) const;

		const gui::Animation& get(const std::string& type, const std::string& name) const;
		
	private:

		std::map<std::string, std::map<std::string, gui::Animation*>> _animations;
	};
}

#endif // !__ANIMATION_MANAGER_H__