#include <Entities/Characters/MagicCharacter.hpp>

MagicCharacter::MagicCharacter(const int x, const int y, const int hp, const char player, const int will, const int res_phy, const int res_mag, const int magic)
	: super(x, y, hp, player, will, res_phy, res_mag), _magic(magic) 
{

}

MagicCharacter::~MagicCharacter()
{
}
