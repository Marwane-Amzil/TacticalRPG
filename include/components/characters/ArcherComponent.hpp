#pragma once

#ifndef __HEALER_H__
#define __HEALER_H__

#include <components/CharacterComponent.hpp> // CharacterComponent

struct HealerComponent : public CharacterComponent
{
	using super = CharacterComponent;

	inline HealerComponent() :
		super(60, 70, 50, 50, 0, 50) {}

	inline HealerComponent(const HealerComponent& other) :
		super(other) {}

	inline HealerComponent(HealerComponent&& other) noexcept :
		super(std::move(other)) {}
};

#endif // !__HEALER_H__