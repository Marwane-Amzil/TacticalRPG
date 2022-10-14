#include <Personnage/Personnage.hpp>
#include <Plateau.hpp>
#include <iostream>

Personnage::Personnage(const int x, const int y, const int pv, const int force, const int magie, const int res_phy, const int res_mag, const char joueur)
	: _sprite(sf::Vector2f(25.0f, 50.0f)), _texture(), _position(x, y), _pv(pv), _force(force), _magie(magie), _res_phy(res_phy), _res_mag(res_mag), _joueur(joueur), _peut_attaquer(true), _peut_deplacer(true), _tour_fini(false)
{
	Position sprite_position = _position;
	sprite_position.PositionToPx();
	_sprite.setPosition(sprite_position.getX(), sprite_position.getY());
}

/*
Personnage::Personnage(const Personnage& autre)
	: _sprite(autre._sprite), _texture(autre._texture), _pv(autre._pv), _force(autre._force), _magie(autre._magie), _res_phy(autre._res_phy), _res_mag(autre._res_mag), _joueur(autre._joueur), _peut_attaquer(autre._peut_attaquer), _peut_deplacer(autre._peut_deplacer), _tour_fini(autre._tour_fini) {}
*/

Personnage::~Personnage() {}

const sf::RectangleShape& Personnage::getSprite() const
{
	return _sprite;
}

const Position& Personnage::getPosition() const
{
	return _position;
}

int Personnage::getPv() const
{
	return _pv;
}

int Personnage::getResPhy() const
{
	return _res_phy;
}

int Personnage::getResMag() const
{
	return _res_mag;
}

char Personnage::getJoueur() const
{
	return _joueur;
}

bool Personnage::getPeutAttaquer() const
{
	return _peut_attaquer;
}

bool Personnage::getPeutDeplacer() const
{
	return _peut_deplacer;
}

bool Personnage::getTourFini() const
{
	return _tour_fini;
}

bool Personnage::estMort() const
{
	if (_pv <= 0)
	{
		return true;
	}
	
	return false;
}

void Personnage::setSpriteTexture(const sf::Texture& texture)
{
	_texture = texture;
}

void Personnage::setSpritePosition(const Position& position)
{
	_sprite.setPosition(position.getX(), position.getY());
}

void Personnage::setPosition(const int x, const int y)
{
	_position.setX(x);
	_position.setY(y);
}

void Personnage::setPosition(const Position& position)
{
	_position.setPosition(position.getX(), position.getY());
}

void Personnage::setPv(const int pv)
{
	_pv = pv;
}

void Personnage::setResPhy(const int res_phy)
{
	_res_phy = res_phy;
}

void Personnage::setResMag(const int res_mag)
{
	_res_mag = res_mag;
}

void Personnage::setJoueur(const char joueur)
{
	_joueur = joueur;
}

void Personnage::peutAttaquer(bool peut_attaquer)
{
    _peut_attaquer = peut_attaquer;
}

void Personnage::peutDeplacer(bool peut_deplacer)
{
    _peut_deplacer = peut_deplacer;
}

void Personnage::tourFini(bool tour_fini)
{
    _tour_fini = tour_fini;
    if (_tour_fini)
    {  
        _peut_attaquer = false;
        _peut_deplacer = false;
    }
}

void Personnage::initialiser()
{
	_peut_attaquer = true;
	_peut_deplacer = true;
	_tour_fini = false;
}

bool Personnage::operator==(const Personnage& autre) const
{
	return equals(autre);
}

bool Personnage::operator!=(const Personnage& autre) const
{
	return !(*this == autre);
}

void Personnage::attaquer_deduire_pv(const Position &position_defenseur,Plateau &plateau)
{
	//si l'attaquant à de la force, c'est une classe non magique
	if (getForce()!=0)
	{   //pv def=  pv def + def def - attak attckant 
		//		= 60 +(20 -40)
		//get pv - (force attack _ res phy def)

		plateau(position_defenseur)->setPv(plateau(position_defenseur)->getPv() + (plateau(position_defenseur)->getResPhy() - getForce() ));

	}
	//sinon l'attaquant est une classe magique
	else
	{
		plateau(position_defenseur)->setPv(plateau(position_defenseur)->getPv() +  (plateau(position_defenseur)->getResMag() - getMagie() ));

	}
	_peut_attaquer=false;
	//plateau.verif_mort(position_defenseur);// si le defenseur a plus de pv , alors on le supprime du plateau

}

void Personnage::perso_check_tour_fini()
{
	if (_peut_deplacer==false && _peut_attaquer==false)
	{
		_tour_fini=true;
	}
}
