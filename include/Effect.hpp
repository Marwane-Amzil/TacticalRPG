#pragma once
#ifndef __EFFECT_H__
#define __EFFECT_H__

class Effect
{
public:
	Effect(float timer);
	~Effect() = default;
	float getTimer() const;

private:
	float _timer;
};

#endif // !__EFFECT_H__ 
