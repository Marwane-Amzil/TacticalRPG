#pragma once

#ifndef __PERSONNAGE_H__
#define __PERSONNAGE_H__

#include <Position.hpp>
#include <SFML/Graphics.hpp>

class Plateau;
class Fenetre;


class Personnage
{
public:

	Personnage() = delete;
	/**
	* @brief Constructeur prenant en parametres des entiers pour les stats de PV, force, magie, resistance physique et magique et un caractere representant le joueur.
	*
	* @param x: Sa position dans l'axe X
	* @param y: Sa position dans l'axe Y
	* @param pv: Son nombre de PV
	* @param force: Sa valeur de force (pour un guerrier)
	* @param magie: Sa valeur de magie (pour un mage)
	* @param res_phy: Sa valeur de resistance physique
	* @param res_mag: Sa valeur de resistance magique
	* @param joueur: Le joueur auquel il appartient
	*/
	Personnage(const int x, const int y, const int pv, const int force, const int magie, const int res_phy, const int res_mag, char joueur);
	/**
	* @brief Constructeur par copie.
	*
	* @param autre: Un autre personnage
	*/
	Personnage(const Personnage& autre) = delete;
	/**
	* @brief Methode qui retourne le sprite du personnage.
	*
	* @return Le sprite du personnage
	*/
	const sf::RectangleShape& getSprite() const;
	/**
	* @brief Methode qui retourne la position du personnage.
	*
	* @return La position du personnage
	*/
	const Position& getPosition() const;
	/**
	* @brief Methode qui retourne les PV restants du personnage.
	*
	* @return Retourne les PV actuels du personnage
	*/
    int getPv() const;
	/**
	* @brief Methode qui retourne la stat de resistance physique du personnage.
	*
	* @return Retourne la resistance physique du personnage
	*/
    int getResPhy() const;
	/**
	* @brief Methode qui retourne la stat de resistance magique du personnage.
	*
	* @return Retourne la resistance magique du personnage
	*/
    int getResMag() const;
	/**
	* @brief Methode qui retourne le joueur qui controle le personnage.
	*
	* @return Retourne le joueur auquel appartient le personnage.
	*/
    char getJoueur() const;
	/**
	* @brief Methode qui indique si le personnage peut attaquer ou non.
	*
	* @return true ou false
	*/
	bool getPeutAttaquer() const;
	/**
	* @brief Methode qui indique si le personnage peut se deplacer ou non.
	*
	* @return true ou false
	*/
	bool getPeutDeplacer() const;
	/**
	* @brief Methode qui indique si le personnage peut effectuer une quelconque action ou non.
	*
	* @return true ou false
	*/
	bool getTourFini() const;
	/**
	* @brief Methode qui indique si le personnage est mort ou non.
	*
	* @return true ou false
	*/
	bool estMort() const;
	/**
	* @brief Methode qui initialise la position du personnage en prenant des coordonnees x et y en parametres.
	*
	* @param x: position dans l'axe X
	* @param y: position dans l'axe Y
	*/
	void setPosition(const int x, const int y);
	/**
	* @brief Methode qui initialise la texture du sprite du personnage.
	*
	* @param texture: Une texture qui remplacera la texture actuelle
	*/
	void setSpriteTexture(const sf::Texture& texture);
	/**
	* @brief Methode qui initialise la position du sprite du personnage.
	*
	* @param position: Une position qui indiquera ou placer le sprite
	*/
	void setSpritePosition(const Position& position);
	/**
	* @brief Methode qui initialise la position du personnage en prenant une position en parametre.
	*
	* @param position: Une position (X,Y)
	*/
	void setPosition(const Position& position);
	/**
	* @brief Methode qui initialise les PV du personnage.
	*
	* @param pv: un nombre de PV
	*/
	void setPv(const int pv);
	/**
	* @brief Methode qui initialise la resistance physique du personnage.
	*
	* @param res_phy: une valeur de resistance physique
	*/
	void setResPhy(const int res_phy);
	/**
	* @brief Methode qui initialise la resistance magique du personnage.
	*
	* @param res_mag: une valeur de resistance magique
	*/
	void setResMag(const int res_m);
	/**
	* @brief Methode qui assigne le personnage a un joueur.
	*
	* @param joueur: Le joueur auquel appartient le personnage
	*/
	void setJoueur(char joueur);
	/**
	* @brief Methode qui indique si le personnage peut attaquer ou non.
	*
	* @param peut_attaquer: 
	*/
	void peutAttaquer(bool peut_attaquer);
	/**
	* @brief Methode qui indique si le personnage peut se deplacer ou non.
	*
	* @param peut_deplacer: 
	*/
	void peutDeplacer(bool peut_deplacer);
	/**
	* @brief Methode qui indique si le personnage peut effectuer une quelconque action ou non.
	*
	* @param tour_fini: 
	*/
	void tourFini(bool tour_fini);
	/**
	*
	*/
	void initialiser();
	/**
	* @brief Detruit un personnage.
	*/
	virtual ~Personnage();
	/**
	* @brief Methode qui retourne la stat de force du personnage.
	*
	* @return La force du personnage
	*/
	virtual int getForce() const = 0;
	/**
	* @brief Methode qui retourne la stat de magie du personnage.
	*
	* @return Retourne la magie du personnage
	*/
	virtual int getMagie() const = 0;
	/**
	* @brief Methode qui retourne le caractere representant le type du personnage.
	*
	* @return Retourne le type du personnage (exemple: 'M' pour "Mage")
	*/
	virtual char getType() const = 0;
	/**
	* @brief Methode qui retourne le type du personnage.
	*
	* @return Retourne le type du personnage
	*/
	virtual std::string getClasse() const = 0;
	/**
	* @brief Methode qui cree une liste contenant la liste des deplacements possible du personnage selectionne.
	*
	* @return Retourne la liste contenant les deplacements possibles du personnage
	*/
	virtual std::vector<Position> getDeplacementPossible(const Plateau& plateau) const = 0;
	/**
	* @brief Methode qui initialise la stat de force du personnage.
	*
	* @param force: La force du personnage
	*/
	virtual void setForce(const int force) = 0;
	/**
	* @brief Methode qui initialise la stat de magie du personnage.
	*
	* @param magie: La magie du personnage
	*/
	virtual void setMagie(const int magie) = 0;
	/**
	* @brief Methode qui procede au calcul des degats d'une attaque et qui soustrait les dommages subis aux PV du personnage attaque.
	*
	* @param ennemi: Le personnage ennemi devant subir l'attaque
	*/
	virtual void attaquer(Personnage& ennemi) = 0;
	/**
	* @brief Methode qui permet d'animer l'attaque du personnage.
	*/
	virtual void attaquerSprite(const Position& position,Plateau& plateau, Fenetre& window) = 0;
	/**
	* @brief Methode qui permet de deplacer le personnage
	*/
	// virtual void deplacer(const Position& to, Plateau& plateau) = 0;
	/**
	* @brief Methode qui permet de deplacer le sprite du personnage
	*/
	virtual void deplacerSprite(Fenetre& window, Position& to,Plateau &plateau) = 0;
	/**
	* @brief Methode qui permet d'afficher les caracteristiques d'un personnage.
	*/
	virtual void afficher() const = 0;
	/**
	* @brief Appel de la methode 'equals' correspondante au type du personnage. Indique si deux personnages sont identiques.
	*
	* @param autre: Un autre personnage
	*
	* @return Retourne true ou false
	*/
	bool operator==(const Personnage& autre) const;
	/**
	* @brief Appel de la methode 'equals' correspondante au type du personnage. Indique si deux personnages sont differents.
	*
	* @param autre: Un autre personnage
	*
	* @return Retourne true ou false
	*/
	bool operator!=(const Personnage& autre) const;

	void attaquer_deduire_pv (const Position &position_defenseur,Plateau &plateau);

	virtual std::vector <Position> getAttaquePossible(const Plateau& plateau) = 0;

	void perso_check_tour_fini();


protected:

	/**
	* @brief Indique si deux personnages sont identiques.
	*
	* @param autre: Un autre personnage
	*
	* @return Retourne true ou false
	*/
	virtual bool equals(const Personnage& autre) const = 0;

protected:

	sf::RectangleShape _sprite;
	sf::Texture _texture;
	Position _position;
	int _pv;
	int _force;
	int _magie;
	int	_res_phy;
	int	_res_mag;
	char _joueur;
	bool _peut_attaquer;
	bool _peut_deplacer;
	bool _tour_fini;
};

#endif // !__PERSONNAGE_H__