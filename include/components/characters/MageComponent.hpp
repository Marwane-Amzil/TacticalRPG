#pragma once

#ifndef __MAGE_H__
#define __MAGE_H__

#include <components/CharacterComponent.hpp> // CharacterComponent

struct MageComponent : public CharacterComponent
{
	using super = CharacterComponent;

	inline MageComponent() :
		super(60, 70, 50, 50, 0, 50) {}

	inline MageComponent(const MageComponent& other) :
		super(other) {}

	inline MageComponent(MageComponent&& other) noexcept :
		super(std::move(other)) {}
};

#endif // !__MAGE_H__