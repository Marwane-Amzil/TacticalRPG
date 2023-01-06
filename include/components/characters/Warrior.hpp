#pragma once

#ifndef __WARRIOR_H__
#define __WARRIOR_H__

#include <components\Character.hpp> // Character

struct Warrior : public Character
{
	using super = Character;
	
	inline Warrior() :
		super(80, 100, 50, 50, 0, 50) {}

	inline Warrior(const Warrior& other) :
		super(other) {}

	inline Warrior(Warrior&& other) noexcept :
		super(std::move(other)) {}
};

#endif // !__WARRIOR_H__