#pragma once

#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <utility> // std::move

struct CharacterComponent
{
	int will;
	int hp;
	int res_phy;
	int res_mag;
	int magic;
	int strength;
	bool can_move;
	bool can_use_skill;
	bool can_use_sp_skill;

	inline explicit CharacterComponent(int _Will, int _Hp, int _ResPhy, int _ResMag, int _Magic, int _Strength) :
		will(_Will), hp(_Hp), res_phy(_ResPhy), res_mag(_ResMag), magic(_Magic), strength(_Strength), can_move(true), can_use_skill(true), can_use_sp_skill(true) {}

	inline CharacterComponent(const CharacterComponent& other) :
		will(other.will), hp(other.hp), res_phy(other.res_phy), res_mag(other.res_mag), magic(other.magic), strength(other.strength), can_move(other.can_move), can_use_skill(other.can_use_skill), can_use_sp_skill(other.can_use_sp_skill) {}
	
	inline CharacterComponent(CharacterComponent&& _Other) noexcept :
		will(std::move(_Other.will)), hp(std::move(_Other.hp)), res_phy(std::move(_Other.res_phy)), res_mag(std::move(_Other.res_mag)), magic(std::move(_Other.magic)), strength(std::move(_Other.strength)), can_move(std::move(_Other.can_move)), can_use_skill(std::move(_Other.can_use_skill)), can_use_sp_skill(std::move(_Other.can_use_sp_skill)) {}
};

#endif // !__CHARACTER_H__