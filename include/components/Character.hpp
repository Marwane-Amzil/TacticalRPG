#pragma once

#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <utility> // std::move

struct Character
{
	int _will;
	int _hp;
	int _res_phy;
	int _res_mag;
	int _magic;
	int _strength;
	bool _can_move;
	bool _can_use_skill;
	bool _can_use_sp_skill;

	inline explicit Character(int will, int hp, int res_phy, int res_mag, int magic, int strength) :
		_will(will), _hp(hp), _res_phy(res_phy), _res_mag(res_mag), _magic(magic), _strength(strength), _can_move(true), _can_use_skill(true), _can_use_sp_skill(false) {}

	inline Character(const Character& other) :
		_will(other._will), _hp(other._hp), _res_phy(other._res_phy), _res_mag(other._res_mag), _magic(other._magic), _strength(other._strength), _can_move(other._can_move), _can_use_skill(other._can_use_skill), _can_use_sp_skill(other._can_use_sp_skill) {}
	
	inline Character(Character&& other) noexcept :
		_will(std::move(other._will)), _hp(std::move(other._hp)), _res_phy(std::move(other._res_phy)), _res_mag(std::move(other._res_mag)), _magic(std::move(other._magic)), _strength(std::move(other._strength)), _can_move(std::move(other._can_move)), _can_use_skill(std::move(other._can_use_skill)), _can_use_sp_skill(std::move(other._can_use_sp_skill)) {}
};

#endif // !__CHARACTER_H__