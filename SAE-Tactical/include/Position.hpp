#pragma once

#ifndef __POSITION_H__
#define __POSITION_H__

#include <ostream>

class Position
{
public:

	/**
	* @brief Construit une position
	*/
	Position();
	/**
	* @brief Constructeur prenant en parametres 2 entiers x et y.
	* 
	* @param x: La position dans l'axe X
	* @param y: La position dans l'axe Y
	*/
	Position(const int x, const int y);
	/**
	* @brief Constructeur par copie.
	* 
	* @param autre: Une autre position
	*/
	Position(const Position& autre);
	/**
	* @brief Detruit une position
	*/
	~Position();
	/**
	* @brief Methode qui retourne la coordonnee X de la position.
	* 
	* @return La position dans l'axe X
	*/
    int getX() const;
	/**
	* @brief Methode qui retourne la coordonnee Y de la position.
	* 
	* @return La position dans l'axe Y
	*/
    int getY() const;
	/**
	* @brief Methode qui initialise la coordonnee X de la position.
	* 
	* @param x: La position dans l'axe X
	*/
	void setX(const int x);
	/**
	* @brief Methode qui initialise la coordonnee Y de la position.
	* 
	* @param y: La position dans l'axe Y
	*/
	void setY(const int y);
	/*
	* @brief Methode qui initialise une position en prenant 2 entiers.
	*
	* @param x: La position dans l'axe X
	* @param y: La position dans l'axe Y
	*/
	void setPosition(const int x, const int y);
	/*
	* @brief Methode qui convertit une position (X,Y) en coordonnees en pixels (X,Y).
	*/
	void PositionToPx();
	/**
	*
	*/
	void PxToPosition();
	/**
	* @brief Appel de la methode equals. Indique si deux positions sont identiques.
	* 
	* @param autre: Une autre position
	* 
	* @return Retourne true ou false
	*/
	bool operator==(const Position& autre) const;
	/**
	* @brief Appel de la methode equals. Indique si deux positions sont differentes.
	* 
	* @param autre: Une autre position
	*
	* @return Retourne true ou false
	*/
	bool operator!=(const Position& autre) const;
	/**
	* @brief Affiche la position.
	* 
	* @param ostream: stream qui contiendra la position a afficher
	* @param position: position a afficher
	* 
	* @return La position
	*/
	friend std::ostream& operator<<(std::ostream& ostream, const Position& position);

private:

	int _x, _y;
};

#endif // !__POSITION_H__