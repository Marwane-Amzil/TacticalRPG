#pragma once

#ifndef __FENETRE_H__
#define __FENETRE_H__

#include <Plateau.hpp>

class Fenetre : public sf::RenderWindow
{
public:

	/**
	* @brief Constructeur prenant en parametre le nom de la map a utiliser comme texture du terrain.
	* 
	* @param terrain: Nom du fichier a charger
	*/
	Fenetre(const std::string& terrain);
	/**
	* @brief Methode qui affiche graphiquement le plateau.
	* 
	* @param plateau: Le plateau de jeu
	*/
	void dessinePlateau(const Plateau& plateau);
	/**
	* @brief
	*/
	void detecterClic(Position& clic);
	/**
	* @brief
	*/
	void formaterTexte(sf::Text& texte_affichage, const std::string& texte, const sf::Font& font, unsigned int size, float x, float y) const;
	/**
	* @brief 
	*/
	void afficherMenuAction(const Plateau& plateau, const Position& clic);
	/**
	* @brief
	*/
	int effectuerActionClic(const Position& clic);

	void attendre_click(Plateau &plateau,Position &pos_click_depart);

	void afficherDeplacement(Plateau &plateau,const Position& position,Position &pos_arrivee);

	void afficherAttaque(Plateau &plateau,const Position& position,Position &pos_arrivee);

private:

	typedef sf::RenderWindow super;

private:

	sf::RectangleShape _terrain;
	sf::Texture _texture;
};

#endif // !__FENETRE_H__