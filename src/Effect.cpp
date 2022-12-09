#include "Effect.hpp"

Effect::Effect(float timer)
	: _timer(timer)
{
}

float Effect::getTimer() const
{
	return _timer;
}
