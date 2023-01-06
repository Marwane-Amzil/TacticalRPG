#pragma once

#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include <components\Character.hpp> // Character

struct Knight : public Character
{
	using super = Character;

	inline Knight() :
		super(80, 100, 50, 50, 0, 50) {}

	inline Knight(const Knight& other) :
		super(other) {}

	inline Knight(Knight&& other) noexcept :
		super(std::move(other)) {}
};

#endif // !__KNIGHT_H__