#include "Skill.hpp"
#include <Effect.hpp>

Skill::Skill(int multiplier, int range , Effect *effect) 
	: _multiplier(multiplier), _range(range), _effect(effect)
{
}

Skill::~Skill()
{
}