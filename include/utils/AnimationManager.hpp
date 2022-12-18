#pragma once

#ifndef __ANIMATION_MANAGER_H__
#define __ANIMATION_MANAGER_H__

#include <unordered_map> // std::unordered_map
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

		const std::unordered_map<std::string, gui::Animation*>& get(const std::string& type) const;

		const gui::Animation& get(const std::string& type, const std::string& name) const;
		
		gui::Animation& get(const std::string& type, const std::string& name);

	private:

		std::unordered_map<std::string, std::unordered_map<std::string, gui::Animation*>> _animations;
	};
}

#endif // !__ANIMATION_MANAGER_H__