#include <Entities/Character.hpp>

Character::Character(const int x, const int y, const int hp, const char player, const int will, const int res_phy, const int res_mag, const int magic, const int strength)
	: super(x, y, hp), _player(player), _will(will), _res_phy(res_phy), _res_mag(res_mag), _can_move(true), _can_act(true), _can_sp_act(false), _magic(magic), _strength(strength) {}

// ----------------------------------------------   Start  Getters / Setters    ------------------------------------------------------------
char Character::getPlayer() const
{
	return _player;
}

int Character::getWill() const
{
	return _will;
}

int Character::getResPhy() const
{
	return _res_phy;
}

int Character::getResMag() const
{
	return _res_mag;
}

bool Character::getMove() const
{
	return _can_move;
}

const Skill* Character::getFirstSkill() const
{
	return _skills[0];
}

const Skill* Character::getSecondSkill() const
{
	return _skills[1];
}

const Skill* Character::getSpecialSkill() const
{
	return _skills[2];
}

bool Character::getAction() const
{
	return _can_act;
}

bool Character::getSpecialAction() const
{
	return _can_sp_act;
}

int Character::getMagic() const
{
	return _magic;
}

int Character::getStrength() const
{
	return _strength;
}

void Character::setWill(const int will)
{
	_will = will;
}

void Character::setResPhy(const int res_phy)
{
	_res_phy = res_phy;
}

void Character::setResMag(const int res_mag)
{
	_res_mag = res_mag;
}

void Character::setMove(const bool can_move)
{
	_can_move = can_move;
}

void Character::setAction(const bool can_act)
{
	_can_act = can_act;
}

void Character::setSpecialAction(const bool can_sp_act)
{
	_can_sp_act = can_sp_act;
}


// ----------------------------------------------   End  Getters / Setters    ------------------------------------------------------------