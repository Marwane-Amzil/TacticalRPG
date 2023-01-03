#include <Entities/Characters/MagicCharacter.hpp>

// 0 IS THE DEFAULT VALUE FOR THE STRENGHT SKILL
MagicCharacter::MagicCharacter(const int x, const int y, const int hp, const char player, const int will, const int res_phy, const int res_mag, const int magic)
	: super(x, y, hp, player, will, res_phy, res_mag, magic, 0)
{

}

MagicCharacter::~MagicCharacter()
{
}


