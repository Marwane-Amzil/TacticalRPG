#include <Entities/Characters/PhysicalCharacter.hpp>

PhysicalCharacter::PhysicalCharacter(const int x, const int y, const int hp, const char player, const int will, const int res_phy, const int res_mag, const int strength)
	: super(x, y, hp, player, will, res_phy, res_mag), _strength(strength) {}

PhysicalCharacter::~PhysicalCharacter()
{
}
