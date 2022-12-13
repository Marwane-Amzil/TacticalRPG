#pragma once

#ifndef __Fireball_H__
#define __Fireball_H__

#include <Skills/MagicalSkill.hpp>

class Fireball : public MagicalSkill
{
public:

	explicit Fireball(int multiplier, int range, Effect* effect = nullptr);
	
	inline ~Fireball() noexcept = default;

	void activate(Character* character) const override;

private:

	typedef MagicalSkill super;

private:
	
	const int base_damage = 7;
};

#endif // !__Fireball_H__