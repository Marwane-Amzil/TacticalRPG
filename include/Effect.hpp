#pragma once
#ifndef __EFFECT_H__
#define __EFFECT_H__

class Effect
{
public:
	Effect(float timer);
	~Effect() = default;

private:
	float _timer;
};

#endif // !__EFFECT_H__ 
