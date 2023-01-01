#pragma once

#ifndef __Fireball_H__
#define __Fireball_H__

#include <Skills/MagicalSkill.hpp>

class Fireball : public MagicalSkill
{
public:

	explicit Fireball(int multiplier, int range, Character* character,Effect* effect = nullptr);
	
	inline ~Fireball() noexcept = default;

	void activate(Grid& grid, Character& character) const override;
	
	std::vector<Position> getPossibleZones(const Grid& grid) const override;


private:

	typedef MagicalSkill super;

private:
	
	const int _base_damage = 7;
};

#endif // !__Fireball_H__