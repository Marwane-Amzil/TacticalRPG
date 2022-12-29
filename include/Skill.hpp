#pragma once

#ifndef __SKILL_H__
#define __SKILL_H__

#include <vector> // std::vector
#include <Position.hpp>

class Effect;
class Character;
class Grid;
class Position;


class Skill
{
public:
		
	/**
	*
	*/
	explicit Skill(int multiplier, int range, Character* character, Effect *effect = nullptr);
	/**
	*
	*/
	inline virtual ~Skill() noexcept = default;
	/**
	*
	*/
	int getMultiplier() const;
	/**
	*
	*/
	int getRange() const;
	/**
	*
	*/
	const Effect* getEffect() const;
	/**
	*
	*/
	Character* getOwner() const;


	
	virtual void activate(Grid& grid, Character& character) const = 0;
	
	virtual std::vector<Position> getPossibleZones(const Grid& grid) const = 0;

	/**
	*
	*/
	//virtual bool canActivate(Grid* grid) const = 0;

	
private:
		
	int _multiplier;
	int _range;
	Effect *_effect;
	Character *_character;
};

#endif // !__SKILL_H__ 
