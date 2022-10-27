#include <Entities/Character.hpp>

Character::Character(const int x, const int y, const int hp, const char player, const int will, const int res_phy, const int res_mag)
	: super(x, y, hp), _player(player), _will(will), _res_phy(res_phy), _res_mag(res_mag) {}

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

Character::~Character()
{
}
