#include <Skill.hpp>
#include <Effect.hpp>

Skill::Skill(int multiplier, int range , Character* character, Effect *effect)
	: _multiplier(multiplier), _range(range), _character(character), _effect(effect) {}

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

Character* Skill::getOwner() const
{
	return _character;
}
