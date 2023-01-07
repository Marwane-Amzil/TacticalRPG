#pragma once

#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include <components/CharacterComponent.hpp> // CharacterComponent

struct KnightComponent : public CharacterComponent
{
	using super = CharacterComponent;

	inline KnightComponent() :
		super(80, 100, 50, 50, 0, 50) {}

	inline KnightComponent(const KnightComponent& other) :
		super(other) {}

	inline KnightComponent(KnightComponent&& other) noexcept :
		super(std::move(other)) {}
};

#endif // !__KNIGHT_H__