#include <Skill.hpp>
#include <Effect.hpp>

Skill::Skill(int multiplier, int range , Effect *effect) 
	: _multiplier(multiplier), _range(range), _effect(effect) {}

int Skill::getMultiplier() const
{
	return _multiplier;
}

int Skill::getRange() const
{
	return _range;
}

const Effect* Skill::getEffect() const
{
	return _effect;
}

