#pragma once

#ifndef __AXE_SKILL_H__
#define __AXE_SKILL_H__

#include <Skills/PhysicalSkill.hpp>

class AxeSkill : public PhysicalSkill
{
public:
	
	/**
	*
	*/
	explicit AxeSkill(int multiplier, int range, Character* character, Effect* effect = nullptr);
	/**
	*
	*/
	inline ~AxeSkill() noexcept = default;
	/**
	*
	*/
	void activate(Grid& grid, Character& character) const override;

	std::vector<Position> getPossibleZones(const Grid& grid) const override;


private:

	typedef PhysicalSkill super;

private:
	
	const int base_damage = 15;
};

#endif // !__AXE_SKILL_H__ 
