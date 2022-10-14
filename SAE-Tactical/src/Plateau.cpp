#include <Plateau.hpp>
#include <iostream>

Plateau::Plateau() : _grille() {}

std::vector<Position> Plateau::getPersonnageBleu() const
{
	std::vector<Position> bleu;

	for (int i = 0; i < lignes; i++)
	{
		for (int j = 0; j < colonnes; j++)
		{
			if (_grille[i][j] != nullptr)
			{
				if (_grille[i][j]->getJoueur() == 'B')
				{
					bleu.push_back(_grille[i][j]->getPosition());
				}
			}
		}
	}

	return bleu;
}

std::vector<Position> Plateau::getPersonnageRouge() const
{
	std::vector<Position> rouge;

	for (int i = 0; i < lignes; i++)
	{
		for (int j = 0; j < colonnes; j++)
		{
			if (_grille[i][j] != nullptr)
			{
				if (_grille[i][j]->getJoueur() == 'R')
				{
					rouge.push_back(_grille[i][j]->getPosition());
				}
			}
		}
	}

	return rouge;
}

void Plateau::deplacer(const Position& from, const Position& to)
{
    std::swap(_grille[from.getX()][from.getY()], _grille[to.getX()][to.getY()]);
    _grille[to.getX()][to.getY()]->setPosition(to);
}

void Plateau::ajoutePersonnage(Personnage* personnage)
{
	const int i = personnage->getPosition().getX();
	const int j = personnage->getPosition().getY();
	_grille[i][j] = personnage;
}

bool Plateau::tourFini(const char joueur) const
{
	for (size_t i = 0; i < lignes; i++)
	{
		for (size_t j = 0; j < colonnes; j++)
		{
			if (_grille[i][j])
			{
				if (_grille[i][j]->getJoueur() == joueur)
				{
					if (!_grille[i][j]->getTourFini())
					{
						return false;
					}
				}
			}
		}
	}

	return true;
}

void Plateau::initTour() const
{
	for (size_t i = 0; i < lignes; i++)
	{
		for (size_t j = 0; j < colonnes; j++)
		{
			if (_grille[i][j])
			{
				_grille[i][j]->initialiser();
			}
		}
	}
}

void Plateau::afficher() const
{
	for (int i = 0; i < lignes; i++)
	{
		std::cout << "   ---------------------------------------------------------\n";

		if (i < 10)
		{
			std::cout << ' ' << i << " |";
		}
		else
		{
			std::cout << i << " |";
		}

		for (int j = 0; j < colonnes; j++) 
		{
			if (_grille[i][j])
			{
				std::cout << ' ' << _grille[i][j]->getType() << " |";
			}
			else
			{
				std::cout << "   |";
			}
		}

		std::cout << "\n";
	}

	std::cout << "   ---------------------------------------------------------\n";
}

const Personnage* Plateau::operator()(const unsigned int& i, const unsigned int& j) const
{
	return _grille[i][j];
}

Personnage* Plateau::operator()(const unsigned int& i, const unsigned int& j)
{
	return _grille[i][j];
}

const Personnage* Plateau::operator()(const Position &position) const
{
	return _grille[position.getX()][position.getY()];
}

Personnage* Plateau::operator()(const Position &position)
{
	return _grille[position.getX()][position.getY()];
}

void Plateau::verif_mort(const Position &position)
{
	if (_grille[position.getX()][position.getY()]->getPv()<=0)
	{
		_grille[position.getX()][position.getY()]=nullptr;
	}
}

