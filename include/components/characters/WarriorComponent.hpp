#pragma once

#ifndef __WARRIOR_H__
#define __WARRIOR_H__

#include <components/CharacterComponent.hpp> // CharacterComponent

struct WarriorComponent : public CharacterComponent
{
	using super = CharacterComponent;
	
	inline WarriorComponent() :
		super(80, 100, 50, 50, 0, 50) {}

	inline WarriorComponent(const WarriorComponent& other) :
		super(other) {}

	inline WarriorComponent(WarriorComponent&& other) noexcept :
		super(std::move(other)) {}
};

#endif // !__WARRIOR_H__