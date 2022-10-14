#include <Personnage/Guerrier.hpp>
#include <Plateau.hpp>
#include <Fenetre.hpp>
#include <vector>
#include <iostream>


Guerrier::Guerrier(const int x, const int y, const char joueur)
	: super(x, y, 60, 40, 0, 20, 20, joueur) 
{
	_joueur == 'R' ? _texture.loadFromFile("images/paladin_rouge/paladin.png") : _texture.loadFromFile("images/soldat_bleu/soldat_B.png");
	_sprite.setTexture(&_texture);
}

Guerrier::~Guerrier() {}

int Guerrier::getForce() const
{
	return _force;
}

int Guerrier::getMagie() const
{
	return _magie;
}

char Guerrier::getType() const
{
	return _type;
}

std::string Guerrier::getClasse() const
{
	if (_joueur == 'B')
	{
		return "Classe: Guerrier Bleu";
	}
	
	return "Classe: Guerrier Rouge";
}

std::vector<Position> Guerrier::getDeplacementPossible(const Plateau& plateau) const
{
	Position pos_perso = getPosition();
	std::vector <Position> liste_position;
	bool modulo = false;
	int compteur = 0;

	// ----- colonne horizontale vers la gauche

	for (size_t i = 1; i < 5; i++)
	{
		if (pos_perso.getX() - i < colonnes && plateau(pos_perso.getX() - i, pos_perso.getY()) == nullptr)
		{
			liste_position.push_back(Position(pos_perso.getX() - i, pos_perso.getY()));
		}
		else
		{
			break;
		}
	}
	// ----- colonne horizontale vers la droite

	for (size_t i = 1; i < 5; i++)
	{
		// colonne horizontale vers la gauche
		if (pos_perso.getX() + i < colonnes && plateau(pos_perso.getX() + i, pos_perso.getY()) == nullptr)
		{
			liste_position.push_back(Position(pos_perso.getX() + i, pos_perso.getY()));
		}
		else
		{
			break;
		}
	}
	// ----- colonne verticale vers le bas

	for (size_t i = 1; i < 5; i++)
	{
		// colonne horizontale vers la gauche
		if (pos_perso.getY() + i < colonnes && plateau(pos_perso.getX(), pos_perso.getY() + i) == nullptr)
		{
			liste_position.push_back(Position(pos_perso.getX(), pos_perso.getY() + i));
		}
		else
		{
			break;
		}
	}

	// ----- colonne verticale vers le haut

	for (size_t i = 1; i < 5; i++)
	{
		// colonne horizontale vers la gauche
		if (pos_perso.getY() - i < colonnes && plateau(pos_perso.getX(), pos_perso.getY() - i) == nullptr)
		{
			liste_position.push_back(Position(pos_perso.getX(), pos_perso.getY() - i));
		}
		else
		{
			break;
		}
	}

	// ----- 1er vecticale vers bas gauche 

	for (size_t i = 0; i < 4; i++)
	{
		if (modulo == false)
		{
			if (plateau(pos_perso.getX(), pos_perso.getY() + 1) == nullptr && pos_perso.getY() + 1 < colonnes)
			{
				liste_position.push_back(Position(pos_perso.getX(), pos_perso.getY() + 1));
				pos_perso.setPosition(pos_perso.getX(), pos_perso.getY() + 1);
			}
			else
			{
				break;
			}
			modulo = true;
		}
		else
		{
			if (pos_perso.getX() - 1 >= 0 && plateau(pos_perso.getX() - 1, pos_perso.getY()) == nullptr)
			{
				liste_position.push_back(Position(pos_perso.getX() - 1, pos_perso.getY()));
				pos_perso.setPosition(pos_perso.getX() - 1, pos_perso.getY());
			}
			else
			{
				break;
			}
			modulo = false;
		}
	}

	pos_perso.setPosition(getPosition().getX(), getPosition().getY()); //on renitilise les variables pr changer de diagonale
	modulo = false;

	// ----- 2eme vecticale vers haut droite 

	for (size_t i = 0; i < 4; i++)
	{
		if (modulo == false)
		{
			if (pos_perso.getY() - 1 >= 0 && plateau(pos_perso.getX(), pos_perso.getY() - 1) == nullptr)
			{
				liste_position.push_back(Position(pos_perso.getX(), pos_perso.getY() - 1));
				pos_perso.setPosition(pos_perso.getX(), pos_perso.getY() - 1);
			}
			else
			{
				break;
			}
			modulo = true;
		}
		else
		{
			if (plateau(pos_perso.getX() + 1, pos_perso.getY()) == nullptr && pos_perso.getX() + 1 < colonnes)
			{
				liste_position.push_back(Position(pos_perso.getX() + 1, pos_perso.getY()));
				pos_perso.setPosition(pos_perso.getX() + 1, pos_perso.getY());
			}
			else
			{
				break;
			}
			modulo = false;
		}
	}

	pos_perso.setPosition(getPosition().getX(), getPosition().getY()); //on renitilise la variable pr changer de diagonale
	modulo = false;

	// ----- 3eme vecticale vers bas droite

	for (size_t i = 0; i < 4; i++)
	{
		if (modulo == false)
		{
			if (plateau(pos_perso.getX(), pos_perso.getY() + 1) == nullptr && pos_perso.getY() + 1 < colonnes)
			{
				liste_position.push_back(Position(pos_perso.getX(), pos_perso.getY() + 1));
				pos_perso.setPosition(pos_perso.getX(), pos_perso.getY() + 1);
			}
			else
			{
				break;
			}
			modulo = true;
		}
		else
		{
			if (plateau(pos_perso.getX() + 1, pos_perso.getY()) == nullptr && pos_perso.getX() + 1 < colonnes)
			{
				liste_position.push_back(Position(pos_perso.getX() + 1, pos_perso.getY()));
				pos_perso.setPosition(pos_perso.getX() + 1, pos_perso.getY());
			}
			else
			{
				break;
			}
			modulo = false;
		}
	}

	pos_perso.setPosition(getPosition().getX(), getPosition().getY()); //on renitilise la variable pr changer de diagonale
	modulo = false;

	// ----- 4eme vecticale vers bas haut gauche

	for (size_t i = 0; i < 4; i++)
	{
		if (modulo == false)
		{
			if (pos_perso.getY() - 1 >= 0 && plateau(pos_perso.getX(), pos_perso.getY() - 1) == nullptr)
			{
				liste_position.push_back(Position(pos_perso.getX(), pos_perso.getY() - 1));
				pos_perso.setPosition(pos_perso.getX(), pos_perso.getY() - 1);
			}
			else
			{
				break;
			}
			modulo = true;
		}
		else
		{
			if (pos_perso.getX() - 1 >= 0 && plateau(pos_perso.getX() - 1, pos_perso.getY()) == nullptr)
			{
				liste_position.push_back(Position(pos_perso.getX() - 1, pos_perso.getY()));
				pos_perso.setPosition(pos_perso.getX() - 1, pos_perso.getY());
			}
			else
			{
				break;
			}
			modulo = false;
		}
	}

	pos_perso.setPosition(getPosition().getX(), getPosition().getY()); //on renitilise la variable pr changer de diagonale
	modulo = false;

	// ----- 5eme vecticale vers gauche haut

	for (size_t i = 0; i < 4; i++)
	{
		if (modulo == false)
		{
			if (pos_perso.getX() - 1 >= 0 && plateau(pos_perso.getX() - 1, pos_perso.getY()) == nullptr)
			{
				liste_position.push_back(Position(pos_perso.getX() - 1, pos_perso.getY()));
				pos_perso.setPosition(pos_perso.getX() - 1, pos_perso.getY());
			}
			else
			{
				break;
			}
			modulo = true;
		}
		else
		{
			if (pos_perso.getY() - 1 >= 0 && plateau(pos_perso.getX(), pos_perso.getY() - 1) == nullptr)
			{
				liste_position.push_back(Position(pos_perso.getX(), pos_perso.getY() - 1));
				pos_perso.setPosition(pos_perso.getX(), pos_perso.getY() - 1);
			}
			else
			{
				break;
			}
			modulo = false;
		}
	}

	pos_perso.setPosition(getPosition().getX(), getPosition().getY()); //on renitilise la variable pr changer de diagonale
	modulo = false;

	// ----- 6 eme vecticale vers droite haut

	for (size_t i = 0; i < 4; i++)
	{
		if (modulo == false)
		{
			if (plateau(pos_perso.getX() + 1, pos_perso.getY()) == nullptr && pos_perso.getX() + 1 < colonnes)
			{
				liste_position.push_back(Position(pos_perso.getX() + 1, pos_perso.getY()));
				pos_perso.setPosition(pos_perso.getX() + 1, pos_perso.getY());
			}
			else
			{
				break;
			}
			modulo = true;
		}
		else
		{
			if (pos_perso.getY() - 1 >= 0 && plateau(pos_perso.getX(), pos_perso.getY() - 1) == nullptr)
			{
				liste_position.push_back(Position(pos_perso.getX(), pos_perso.getY() - 1));
				pos_perso.setPosition(pos_perso.getX(), pos_perso.getY() - 1);
			}
			else
			{
				break;
			}
			modulo = false;
		}
	}

	pos_perso.setPosition(getPosition().getX(), getPosition().getY()); //on renitilise la variable pr changer de diagonale
	modulo = false;

	// ----- 7 eme vecticale vers gauche bas

	for (size_t i = 0; i < 4; i++)
	{
		if (modulo == false)
		{
			if (pos_perso.getX() - 1 >= 0 && plateau(pos_perso.getX() - 1, pos_perso.getY()) == nullptr)
			{
				liste_position.push_back(Position(pos_perso.getX() - 1, pos_perso.getY()));
				pos_perso.setPosition(pos_perso.getX() - 1, pos_perso.getY());
			}
			else
			{
				break;
			}
			modulo = true;
		}
		else
		{
			if (plateau(pos_perso.getX(), pos_perso.getY() + 1) == nullptr && pos_perso.getY() + 1 < colonnes)
			{
				liste_position.push_back(Position(pos_perso.getX(), pos_perso.getY() + 1));
				pos_perso.setPosition(pos_perso.getX(), pos_perso.getY() + 1);
			}
			else
			{
				break;
			}
			modulo = false;
		}
	}

	pos_perso.setPosition(getPosition().getX(), getPosition().getY()); //on renitilise la variable pr changer de diagonale
	modulo = false;

	// ----- 8 eme vecticale vers droite bas

	for (size_t i = 0; i < 4; i++)
	{
		if (modulo == false)
		{
			if (plateau(pos_perso.getX() + 1, pos_perso.getY()) == nullptr && pos_perso.getX() + 1 < colonnes)
			{
				liste_position.push_back(Position(pos_perso.getX() + 1, pos_perso.getY()));
				pos_perso.setPosition(pos_perso.getX() + 1, pos_perso.getY());
			}
			else
			{
				break;
			}
			modulo = true;
		}
		else
		{
			if (plateau(pos_perso.getX(), pos_perso.getY() + 1) == nullptr && pos_perso.getY() + 1 < colonnes)
			{
				liste_position.push_back(Position(pos_perso.getX(), pos_perso.getY() + 1));
				pos_perso.setPosition(pos_perso.getX(), pos_perso.getY() + 1);
			}
			else
			{
				break;
			}
			modulo = false;
		}
	}

	pos_perso.setPosition(getPosition().getX(), getPosition().getY()); //on renitilise la variable pr changer de diagonale
	modulo = false;

	// ----- 9 eme vertiale bas droit et gauche

	for (size_t i = 0; i < 4; i++)
	{
		// 3 en dessous
		if (compteur < 3)
		{
			if (plateau(pos_perso.getX(), pos_perso.getY() + 1) == nullptr && pos_perso.getY() + 1 < colonnes)
			{
				liste_position.push_back(Position(pos_perso.getX(), pos_perso.getY() + 1));
				pos_perso.setPosition(pos_perso.getX(), pos_perso.getY() + 1);
				compteur++;
			}
			else
			{
				break;
			}
		}
		else
		{
			//3 en dessous + 1 droite
			if (plateau(pos_perso.getX() + 1, pos_perso.getY()) == nullptr && pos_perso.getX() + 1 < colonnes)
			{
				liste_position.push_back(Position(pos_perso.getX() + 1, pos_perso.getY()));
			}
			//3 en dessous + 1 gauche
			if (pos_perso.getX() - 1 >= 0 && plateau(pos_perso.getX() - 1, pos_perso.getY()) == nullptr)
			{
				liste_position.push_back(Position(pos_perso.getX() - 1, pos_perso.getY()));
				break;
			}
			else
			{
				break;
			}

		}
	}

	pos_perso.setPosition(getPosition().getX(), getPosition().getY()); //on renitilise la variable pr changer de diagonale
	compteur = 0;

	// ----- 10 eme vertiale haut droit et gauche

	for (size_t i = 0; i < 4; i++)
	{
		// 3 en haut
		if (compteur < 3)
		{
			if (pos_perso.getY() - 1 >= 0 && plateau(pos_perso.getX(), pos_perso.getY() - 1) == nullptr)
			{
				liste_position.push_back(Position(pos_perso.getX(), pos_perso.getY() - 1));
				pos_perso.setPosition(pos_perso.getX(), pos_perso.getY() - 1);
				compteur++;
			}
			else
			{
				break;
			}
		}
		else
		{
			//3 en haut + 1 droite
			if (plateau(pos_perso.getX() + 1, pos_perso.getY()) == nullptr && pos_perso.getX() + 1 < colonnes)
			{
				liste_position.push_back(Position(pos_perso.getX() + 1, pos_perso.getY()));
			}
			//3 en haut + 1 gauche
			if (pos_perso.getX() - 1 >= 0 && plateau(pos_perso.getX() - 1, pos_perso.getY()) == nullptr)
			{
				liste_position.push_back(Position(pos_perso.getX() - 1, pos_perso.getY()));
				break;
			}
			else
			{
				break;
			}

		}
	}

	pos_perso.setPosition(getPosition().getX(), getPosition().getY()); //on renitilise la variable pr changer de diagonale
	compteur = 0;

	// ----- 11 eme 3 horizontal gauche + 1 haut et 1 bas

	for (size_t i = 0; i < 4; i++)
	{
		// 3 à gauche
		if (compteur < 3)
		{
			if (pos_perso.getX() - 1 >= 0 && plateau(pos_perso.getX() - 1, pos_perso.getY()) == nullptr)
			{
				liste_position.push_back(Position(pos_perso.getX() - 1, pos_perso.getY()));
				pos_perso.setPosition(pos_perso.getX() - 1, pos_perso.getY());
				compteur++;
			}
			else
			{
				break;
			}
		}
		else
		{
			//3 à gauche + 1 haut
			if (plateau(pos_perso.getX(), pos_perso.getY() + 1) == nullptr && pos_perso.getY() + 1 < colonnes)
			{
				liste_position.push_back(Position(pos_perso.getX(), pos_perso.getY() + 1));
			}
			//3 à gauche + 1 bas
			if (pos_perso.getY() - 1 >= 0 && plateau(pos_perso.getX(), pos_perso.getY() - 1) == nullptr)
			{
				liste_position.push_back(Position(pos_perso.getX(), pos_perso.getY() - 1));
				break;
			}
			else
			{
				break;
			}

		}
	}

	pos_perso.setPosition(getPosition().getX(), getPosition().getY()); //on renitilise la variable pr changer de diagonale
	compteur = 0;

	// ----- 12 eme 3 horizontal droite + 1 haut et 1 bas

	for (size_t i = 0; i < 4; i++)
	{
		// 3 à droite
		if (compteur < 3)
		{
			if (plateau(pos_perso.getX() + 1, pos_perso.getY()) == nullptr && pos_perso.getX() + 1 < colonnes)
			{
				liste_position.push_back(Position(pos_perso.getX() + 1, pos_perso.getY()));
				pos_perso.setPosition(pos_perso.getX() + 1, pos_perso.getY());
				compteur++;
			}
			else
			{
				break;
			}
		}
		else
		{
			//3 à droite + 1 haut
			if (plateau(pos_perso.getX(), pos_perso.getY() + 1) == nullptr && pos_perso.getY() + 1 < colonnes)
			{
				liste_position.push_back(Position(pos_perso.getX(), pos_perso.getY() + 1));
			}
			//3 à droite + 1 bas
			if (pos_perso.getY() - 1 >= 0 && plateau(pos_perso.getX(), pos_perso.getY() - 1) == nullptr)
			{
				liste_position.push_back(Position(pos_perso.getX(), pos_perso.getY() - 1));
				break;
			}
			else
			{
				break;
			}

		}
	}

	return liste_position;
}

void Guerrier::attaquer(Personnage& ennemi)
{
	if (ennemi.getJoueur() == getJoueur())
	{
		std::cout << "Vous ne pouvez pas attaquer vos allies." << std::endl;
	}
	else
	{
		if (ennemi.getResPhy() >= getForce())
		{
			std::cout << "Attaque inefficace !" << std::endl;
		}
		else
		{
			ennemi.setPv(ennemi.getPv() - (getForce() - ennemi.getResPhy()));
			std::cout << "L'ennemi a perdu " << (getForce() - ennemi.getResPhy()) << " PV." << std::endl;
			std::cout << "Pv restants: " << ennemi.getPv() << std::endl;
		}

		_peut_attaquer = false;
	}
}

void Guerrier::deplacerSprite(Fenetre &window,Position &to,Plateau &plateau)
{
	if (_peut_deplacer)
	{
		to.PositionToPx();
		sf::Clock clock;
		const sf::Texture* texture_1 = _sprite.getTexture();
		sf::Texture texture_move_1, texture_move_2;
		if (_joueur == 'R')
		{
			texture_move_1.loadFromFile("images/paladin_rouge/paladin_move1.png");
			texture_move_2.loadFromFile("images/paladin_rouge/paladin_move2.png");
		}
		else
		{
			texture_move_1.loadFromFile("images/soldat_bleu/soldat_B_move1.png");
			texture_move_2.loadFromFile("images/soldat_bleu/soldat_B_move2.png");
		}



		while (true)
		{
			std::cout << _sprite.getPosition().x << "," << _sprite.getPosition().y << std::endl;
			//mouvement haut gauche
			if (_sprite.getPosition().x >= to.getX() && _sprite.getPosition().y >= to.getY())
			{
				// Le sprite parcoure les X de sa destination
				while (_sprite.getPosition().x >= to.getX())
				{
					window.clear();
					if (clock.getElapsedTime().asSeconds() > 0.2f)
					{
						_sprite.setTexture(&texture_move_1);
						if (clock.getElapsedTime().asSeconds() > 0.5f)
						{
							_sprite.setTexture(&texture_move_2);
							if (clock.getElapsedTime().asSeconds() > 0.8f)
							{
								clock.restart();
							}
						}
					}
					else
					{
						_sprite.setTexture(texture_1);
					}
					_sprite.move(-1, 0);
					window.dessinePlateau(plateau);
					window.draw(_sprite);
					window.display();
				}
				// Le sprite parcoure les Y de sa destination
				while (_sprite.getPosition().y >= to.getY())
				{
					window.clear();
					if (clock.getElapsedTime().asSeconds() > 0.2f)
					{
						_sprite.setTexture(&texture_move_1);
						if (clock.getElapsedTime().asSeconds() > 0.5f)
						{
							_sprite.setTexture(&texture_move_2);
							if (clock.getElapsedTime().asSeconds() > 0.8f)
							{
								clock.restart();
							}
						}
					}
					else
					{
						_sprite.setTexture(texture_1);
					}
					_sprite.move(0, -1);
					window.dessinePlateau(plateau);
					window.draw(_sprite);
					window.display();
				}
				//break; // le sprite � fini son d�placement
			}
			//mouvement haut droite
			else if (_sprite.getPosition().x <= to.getX() && _sprite.getPosition().y >= to.getY())
			{
				// Le sprite parcoure les X de sa destination
				while (_sprite.getPosition().x <= to.getX())
				{
					window.clear();
					if (clock.getElapsedTime().asSeconds() > 0.2f)
					{
						_sprite.setTexture(&texture_move_1);
						if (clock.getElapsedTime().asSeconds() > 0.5f)
						{
							_sprite.setTexture(&texture_move_2);
							if (clock.getElapsedTime().asSeconds() > 0.8f)
							{
								clock.restart();
							}
						}
					}
					else
					{
						_sprite.setTexture(texture_1);
					}
					_sprite.move(1, 0);
					window.dessinePlateau(plateau);
					window.draw(_sprite);
					window.display();
				}
				// Le sprite parcoure les Y de sa destination
				while (_sprite.getPosition().y >= to.getY())
				{
					window.clear();
					if (clock.getElapsedTime().asSeconds() > 0.2f)
					{
						_sprite.setTexture(&texture_move_1);
						if (clock.getElapsedTime().asSeconds() > 0.5f)
						{
							_sprite.setTexture(&texture_move_2);
							if (clock.getElapsedTime().asSeconds() > 0.8f)
							{
								clock.restart();
							}
						}
					}
					else
					{
						_sprite.setTexture(texture_1);
					}
					_sprite.move(0, -1);
					window.dessinePlateau(plateau);
					window.draw(_sprite);
					window.display();
				}
				//break; // le sprite � fini son d�placement
			}
			//mouvement bas gauche du sprite
			else if (_sprite.getPosition().x >= to.getX() && _sprite.getPosition().y <= to.getY())
			{
				// Le sprite parcoure les X de sa destination
				while (_sprite.getPosition().x >= to.getX())
				{
					window.clear();
					if (clock.getElapsedTime().asSeconds() > 0.2f)
					{
						_sprite.setTexture(&texture_move_1);
						if (clock.getElapsedTime().asSeconds() > 0.5f)
						{
							_sprite.setTexture(&texture_move_2);
							if (clock.getElapsedTime().asSeconds() > 0.8f)
							{
								clock.restart();
							}
						}
					}
					else
					{
						_sprite.setTexture(texture_1);
					}
					_sprite.move(-1, 0);
					window.dessinePlateau(plateau);
					window.draw(_sprite);
					window.display();
				}
				// Le sprite parcoure les Y de sa destination
				while (_sprite.getPosition().y <= to.getY())
				{
					window.clear();
					if (clock.getElapsedTime().asSeconds() > 0.2f)
					{
						_sprite.setTexture(&texture_move_1);
						if (clock.getElapsedTime().asSeconds() > 0.5f)
						{
							_sprite.setTexture(&texture_move_2);
							if (clock.getElapsedTime().asSeconds() > 0.8f)
							{
								clock.restart();
							}
						}
					}
					else
					{
						_sprite.setTexture(texture_1);
					}
					_sprite.move(0, 1);
					window.dessinePlateau(plateau);
					window.draw(_sprite);
					window.display();
				}
				//break; // le sprite � fini son d�placement
			}
			//mouvement haut droite
			else if (_sprite.getPosition().x <= to.getX() && _sprite.getPosition().y >= to.getY())
			{
				// Le sprite parcoure les X de sa destination
				while (_sprite.getPosition().x <= to.getX())
				{
					window.clear();
					if (clock.getElapsedTime().asSeconds() > 0.2f)
					{
						_sprite.setTexture(&texture_move_1);
						if (clock.getElapsedTime().asSeconds() > 0.5f)
						{
							_sprite.setTexture(&texture_move_2);
							if (clock.getElapsedTime().asSeconds() > 0.8f)
							{
								clock.restart();
							}
						}
					}
					else
					{
						_sprite.setTexture(texture_1);
					}
					_sprite.move(0, 0.5);
					window.dessinePlateau(plateau);
					window.draw(_sprite);
					window.display();
				}
				// Le sprite parcoure les Y de sa destination
				while (_sprite.getPosition().y >= to.getY())
				{
					window.clear();
					if (clock.getElapsedTime().asSeconds() > 0.2f)
					{
						_sprite.setTexture(&texture_move_1);
						if (clock.getElapsedTime().asSeconds() > 0.5f)
						{
							_sprite.setTexture(&texture_move_2);
							if (clock.getElapsedTime().asSeconds() > 0.8f)
							{
								clock.restart();
							}
						}
					}
					else
					{
						_sprite.setTexture(texture_1);
					}
					_sprite.move(0, -1);
					window.dessinePlateau(plateau);
					window.draw(_sprite);
					window.display();
				}
				//break; // le sprite � fini son d�placement
			}
			//mouvement bas droite du sprite
			//else if(_sprite.getPosition().x <= to.getX() && _sprite.getPosition().y <= to.getY())
			else
			{
				// Le sprite parcoure les X de sa destination
				while (_sprite.getPosition().x <= to.getX())
				{
					window.clear();
					if (clock.getElapsedTime().asSeconds() > 0.2f)
					{
						_sprite.setTexture(&texture_move_1);
						if (clock.getElapsedTime().asSeconds() > 0.5f)
						{
							_sprite.setTexture(&texture_move_2);
							if (clock.getElapsedTime().asSeconds() > 0.8f)
							{
								clock.restart();
							}
						}
					}
					else
					{
						_sprite.setTexture(texture_1);
					}
					_sprite.move(1, 0);
					window.dessinePlateau(plateau);
					window.draw(_sprite);
					window.display();
				}
				// Le sprite parcoure les Y de sa destination
				while (_sprite.getPosition().y <= to.getY())
				{
					window.clear();
					if (clock.getElapsedTime().asSeconds() > 0.2f)
					{
						_sprite.setTexture(&texture_move_1);
						if (clock.getElapsedTime().asSeconds() > 0.5f)
						{
							_sprite.setTexture(&texture_move_2);
							if (clock.getElapsedTime().asSeconds() > 0.8f)
							{
								clock.restart();
							}
						}
					}
					else
					{
						_sprite.setTexture(texture_1);
					}
					_sprite.move(0, 1);
					window.dessinePlateau(plateau);
					window.draw(_sprite);
					window.display();
				}
				//break; // le sprite � fini son d�placement
			}

			to.PxToPosition();
			plateau.deplacer(getPosition(), to);
			//setPosition(to_plateau);
			_peut_deplacer = false;
			break;
		}
	}
	else
	{
		std::cout << "Ce personnage s'est deja deplace" << std::endl;
	}
}

void Guerrier::attaquerSprite(const Position& position,Plateau& plateau,Fenetre& window)
{
	if (_peut_attaquer)
	{
		sf::Clock clock; //demarage du temps pr l'?v?nement et le changement de texture du sprite
		//textures pour le sprite selon la classe
		const sf::Texture* texture_base = _sprite.getTexture();
		sf::Texture texture_soldat_R_attack_1, texture_soldat_R_attack_2, texture_soldat_R_attack_3, texture_soldat_R_attack_4, texture_soldat_R_attack_5, texture_soldat_R_attack_6, texture_soldat_R_attack_7, texture_soldat_B_attack1, texture_soldat_B_attack2, texture_soldat_B_attack3;// textures des guerriers R et B
		texture_soldat_R_attack_1.loadFromFile("images/paladin_rouge/paladin_attack_1.png");
		texture_soldat_R_attack_2.loadFromFile("images/paladin_rouge/paladin_attack_2.png");
		texture_soldat_R_attack_3.loadFromFile("images/paladin_rouge/paladin_attack_3.png");
		texture_soldat_R_attack_4.loadFromFile("images/paladin_rouge/paladin_attack_4.png");
		texture_soldat_R_attack_5.loadFromFile("images/paladin_rouge/paladin_attack_5.png");
		texture_soldat_R_attack_6.loadFromFile("images/paladin_rouge/paladin_attack_6.png");
		texture_soldat_R_attack_7.loadFromFile("images/paladin_rouge/paladin_attack_7.png");
		texture_soldat_B_attack1.loadFromFile("images/soldat_bleu/soldat_B_attack1.png");
		texture_soldat_B_attack2.loadFromFile("images/soldat_bleu/soldat_B_attack2.png");
		texture_soldat_B_attack3.loadFromFile("images/soldat_bleu/soldat_B_attack3.png");

		while (true)
		{
			//si guerrier rouge, il y a 7 sprites � changer
			if (_joueur == 'R')
			{
				if (clock.getElapsedTime().asSeconds() > 0.2f)
				{
					_sprite.setTexture(&texture_soldat_R_attack_1);
					if (clock.getElapsedTime().asSeconds() > 0.5f)
					{
						_sprite.setTexture(&texture_soldat_R_attack_2);
						if (clock.getElapsedTime().asSeconds() > 0.8f)
						{
							_sprite.setTexture(&texture_soldat_R_attack_3);
							if (clock.getElapsedTime().asSeconds() > 1.2f)
							{
								_sprite.setTexture(&texture_soldat_R_attack_4);
								if (clock.getElapsedTime().asSeconds() > 1.5f)
								{
									_sprite.setTexture(&texture_soldat_R_attack_5);
									if (clock.getElapsedTime().asSeconds() > 1.8f)
									{
										if (clock.getElapsedTime().asSeconds() > 2.1f)
										{
											_sprite.setTexture(&texture_soldat_R_attack_6);
											if (clock.getElapsedTime().asSeconds() > 2.4f)
											{
												_sprite.setTexture(texture_base);
												break;
											}
										}
									}
								}
							}
						}
					}
				}
				else
				{
					_sprite.setTexture(texture_base);
				}
				window.dessinePlateau(plateau);
				window.afficherMenuAction(plateau,getPosition());
				window.display();
				window.clear();
			}
			//si guerrier bleue attaque, il y a 3 sprites cons�cutifs
			else
			{
				if (clock.getElapsedTime().asSeconds() > 0.2f)
				{
					_sprite.setTexture(&texture_soldat_B_attack1);

					if (clock.getElapsedTime().asSeconds() > 0.5f)
					{
						_sprite.setTexture(&texture_soldat_B_attack2);

						if (clock.getElapsedTime().asSeconds() > 0.8f)
						{
							_sprite.setTexture(&texture_soldat_B_attack3);

							if (clock.getElapsedTime().asSeconds() > 0.12f)
							{
								_sprite.setTexture(texture_base);
								break;
							}
						}
					}
				}
				else
				{
					_sprite.setTexture(texture_base);
				}
				window.dessinePlateau(plateau);
				window.afficherMenuAction(plateau,getPosition());
				window.display();
				window.clear();
			}
		}
		attaquer_deduire_pv(position, plateau);

		_peut_attaquer = false;
	}
	else
	{
		std::cout << "Ce personnage a deja attaque" << std::endl;
	}
}


void Guerrier::setForce(const int force)
{
	_force = force;
}

void Guerrier::setMagie(const int magie)
{
	_magie = magie - magie;
}

bool Guerrier::equals(const Personnage& personnage) const
{
	if (_type == personnage.getType())
	{
		return _pv == personnage.getPv() && _force == personnage.getForce() &&
			_res_phy == personnage.getResPhy() && _res_mag == personnage.getResMag();
	}

	return false;
}

void Guerrier::afficher() const
{
	std::cout << "Joueur: " << _joueur
		<< "\nPosition: " << _position
		<< "\nPv: " << _pv
		<< "\nForce: " << _force
		<< "\nRes phy: " << _res_phy
		<< "\nRes mag: " << _res_mag
		<< "\nType: " << _type << std::endl;
}

std::vector <Position> Guerrier::getAttaquePossible(const Plateau& plateau)
{
	std::vector<Position> vector_pos_attaque;

	if (getPosition().getX() + 1 < colonnes && plateau(getPosition().getX() + 1, getPosition().getY()) != nullptr)
	{
		vector_pos_attaque.push_back(Position(getPosition().getX() + 1, getPosition().getY()));
	}
	if (getPosition().getX() - 1 >= 0 && plateau(getPosition().getX() - 1, getPosition().getY()) != nullptr)
	{
		vector_pos_attaque.push_back(Position(getPosition().getX() - 1, getPosition().getY()));
	}
	if (getPosition().getY() - 1 >= 0 && plateau(getPosition().getX(), getPosition().getY() - 1) != nullptr)
	{
		vector_pos_attaque.push_back(Position(getPosition().getX(), getPosition().getY() - 1));
	}
	if (getPosition().getY() + 1 < colonnes && plateau(getPosition().getX(), getPosition().getY() + 1) != nullptr)
	{
		vector_pos_attaque.push_back(Position(getPosition().getX(), getPosition().getY() + 1));
	}
	return vector_pos_attaque;
}