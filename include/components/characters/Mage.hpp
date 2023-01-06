#pragma once

#ifndef __MAGE_H__
#define __MAGE_H__

#include <components\Character.hpp> // Character

struct Mage : public Character
{
	using super = Character;

	inline Mage() :
		super(60, 70, 50, 50, 0, 50) {}

	inline Mage(const Mage& other) :
		super(other) {}

	inline Mage(Mage&& other) noexcept :
		super(std::move(other)) {}
};

#endif // !__MAGE_H__