#pragma once

#ifndef __GUERRIER_H__
#define __GUERRIER_H__

#include <Personnage/Personnage.hpp>

class Guerrier : public Personnage
{
public:

	Guerrier(const int x, const int y, const char joueur);

	Guerrier(const char x, const char y, const int joueur) = delete;

	~Guerrier();

	int getForce() const override;

	int getMagie() const override;

	char getType() const override;

	std::string getClasse() const override;

	std::vector<Position> getDeplacementPossible(const Plateau& plateau)const override;
	
	void setForce(const int force) override;
	
	void setMagie(const int magie) override;

	void attaquer(Personnage& ennemi) override;

	// void changerTextureAttaque() override;

	void attaquerSprite(const Position& position,Plateau& plateau, Fenetre& window) override;

	// void deplacer(const Position& to, Plateau& plateau) override;

	// void changerTextureDeplacement() override;

	void deplacerSprite(Fenetre& window, Position& to,Plateau &plateau) override;
	
	void afficher() const override;

	std::vector <Position> getAttaquePossible(const Plateau& plateau);


private:

	bool equals(const Personnage& personnage) const override;

private:

	typedef Personnage super;

private:

	const char _type = 'G';
};

#endif // !__GUERRIER_H__