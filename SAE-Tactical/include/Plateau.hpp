#pragma once

#ifndef __PLATEAU_H__
#define __PLATEAU_H__

#include <Personnage/Guerrier.hpp>

constexpr int lignes   = 14;
constexpr int colonnes = 14;

class Plateau
{
public:

	/**
	* @brief Construit une grille.
	*/
	Plateau();
	/**
	* @brief Constructeur par copie.
	* 
	* @param autre: Un autre plateau
	*/
	Plateau(const Plateau& autre) = delete;
	/**
	* @brief Methode qui retourne les personnages de couleur bleue.
	* 
	* @return Retourne une liste de positions des personnages dont le joueur est le joueur bleu
	*/
	std::vector<Position> getPersonnageBleu() const;
	/**
	* @brief Methode qui retourne les personnages de couleur rouge.
	* 
	* @return Retourne une liste de positions des personnages dont le joueur est le joueur rouge
	*/
	std::vector<Position> getPersonnageRouge() const;
	/**
	* @brief Methode qui ajoute un personnage dans le plateau.
	* 
	* @param personnage: le personnage a ajouter
	*/
	void ajoutePersonnage(Personnage* personnage);
	/**
	*
	*/
	bool tourFini(const char joueur) const;
	/**
	*
	*/
	void initTour() const;
	/**
	* @brief Methode qui affiche le plateau.
	*/
	void afficher() const;
	/**
	* @brief Accede a un element du tableau.
	*
	* @param i: Indice i du tableau
	* @param j: Indice j du tableau
	*
	* @return Retourne le personnage a l'indice demande
	*
	* @throw out_of_range: Exception levee lors d'une tentavive d'acces a un element hors du tableau.
	*/
	const Personnage* operator()(const unsigned int& i, const unsigned int& j) const;
	/**
	* @brief Accede a un element du tableau.
	*
	* @param i: Indice i du tableau
	* @param j: Indice j du tableau
	*
	* @return Retourne le personnage a l'indice demande
	*
	* @throw out_of_range: Exception levee lors d'une tentavive d'acces a un element hors du tableau.
	*/
	Personnage* operator()(const unsigned int& i, const unsigned int& j);

	const Personnage* operator()(const Position &position) const;

	Personnage* operator()(const Position &position);

	void verif_mort(const Position &position);

	void deplacer(const Position& from, const Position& to);



private:

	Personnage* _grille[lignes][colonnes];
};

#endif // !__PLATEAU_H__