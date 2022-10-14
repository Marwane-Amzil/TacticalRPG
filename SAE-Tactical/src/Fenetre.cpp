#include <Fenetre.hpp>
#include <iostream>

Fenetre::Fenetre(const std::string& terrain)
	: super(sf::VideoMode(700, 900), "TacticalRPG"), _terrain(sf::Vector2f(700.0f, 700.0f)), _texture()
{
	setVerticalSyncEnabled(true);
    _texture.loadFromFile(terrain);
    _terrain.setPosition(0.0f, 0.0f);
    _terrain.setTexture(&_texture);
}

void Fenetre::dessinePlateau(const Plateau& plateau)
{
	draw(_terrain);

	for (size_t i = 0; i < lignes; i++)
	{
		for (size_t j = 0; j < colonnes; j++)
		{
			if (plateau(i, j))
			{
				draw(plateau(i, j)->getSprite());
			}
		}
	}
}

void Fenetre::detecterClic(Position& clic)
{
	sf::Event event{};
	while (waitEvent(event))
	{
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Right || event.mouseButton.button == sf::Mouse::Left)
			{
				clic.setX(event.mouseButton.x / 50);
				clic.setY(event.mouseButton.y / 50);
				effectuerActionClic(clic);
				std::cout << clic << std::endl;
				break;
			}
		}
	}
}

void Fenetre::formaterTexte(sf::Text& texte_affichage, const std::string& texte, const sf::Font& font, unsigned int size, float x, float y) const
{
	texte_affichage.setString(texte);
	texte_affichage.setFont(font);
	texte_affichage.setFillColor(sf::Color::White);
	texte_affichage.setStyle(sf::Text::Bold);
	texte_affichage.setCharacterSize(size);
	texte_affichage.setPosition(x, y);
}

void Fenetre::afficherMenuAction(const Plateau& plateau, const Position& position_perso)
{
	if (position_perso.getX() < lignes && position_perso.getY() < colonnes)
	{
		if (plateau(position_perso.getX(), position_perso.getY()))
		{
			sf::Text classe, pv, pouvoir, res_phy, res_mag, button_1, button_2, button_3;
			sf::Font font;
			font.loadFromFile("font/e.ttf");

			formaterTexte(classe, plateau(position_perso.getX(), position_perso.getY())->getClasse(), font, 22, 5.0f, 700.0f);
			formaterTexte(pv, "PV : " + std::to_string(plateau(position_perso.getX(), position_perso.getY())->getPv()), font, 22, 5.0f, 737.5f);
			if (dynamic_cast<const Guerrier*>(plateau(position_perso.getX(), position_perso.getY())))
			{
				formaterTexte(pouvoir, "Force : " + std::to_string(plateau(position_perso.getX(), position_perso.getY())->getForce()), font, 22, 5.0f, 775.0f);
			}
			else
			{
				formaterTexte(pouvoir, "Magie : " + std::to_string(plateau(position_perso.getX(), position_perso.getY())->getMagie()), font, 22, 5.0f, 775.0f);
			}
			formaterTexte(res_phy, "Res phy : " + std::to_string(plateau(position_perso.getX(), position_perso.getY())->getResPhy()), font, 22, 5.0f, 812.5f);
			formaterTexte(res_mag, "Res mag : " + std::to_string(plateau(position_perso.getX(), position_perso.getY())->getResMag()), font, 22, 5.0f, 850.0f);
			formaterTexte(button_1, " DEPLACER ", font, 22, 520.0f, 720.0f);
			formaterTexte(button_2, " ATTAQUER ", font, 22, 520.0f, 780.0f);
			formaterTexte(button_3, " PASSER TOUR ", font, 22, 520.0f, 840.0f);

			clear();
			dessinePlateau(plateau);
			draw(classe);
			draw(pv);
			draw(pouvoir);
			draw(res_phy);
			draw(res_mag);
			draw(button_1);
			draw(button_2);
			draw(button_3);
		}
		else
		{
			clear();
			dessinePlateau(plateau);
		}
	}
	else
	{
		clear();
		dessinePlateau(plateau);
	}
}

int Fenetre::effectuerActionClic(const Position& clic)
{
	if (clic.getX() >= 10 && clic.getX() <= 13)
	{
		if (clic.getY() == 14)
		{
			return 1;
		}
		else if (clic.getY() == 15)
		{
			return 2;
		}
		else if (clic.getY() == 16 || clic.getY() == 17)
		{
			return 3;
		}
		else
		{
			std::cout << "aucun bouton selectionne" << std::endl;
			return 0;
		}
		
	}
}

void Fenetre::attendre_click(Plateau &plateau,Position &pos_click_depart){
    sf::Clock clockt;
    sf::Vector2i localPosition;  
	sf::Event event;
    while (waitEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            close();
        }    
        else if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Right || event.mouseButton.button == sf::Mouse::Left)
            {
                break;
            }
        }
    }
    pos_click_depart.setY(event.mouseButton.y);
    pos_click_depart.setX(event.mouseButton.x);
    detecterClic(pos_click_depart);
}

void Fenetre::afficherDeplacement(Plateau &plateau,const Position &position,Position &pos_arrivee)
{
	std::vector<Position> vector_pos_deplacement;
	std::vector<sf::RectangleShape> vector_sprite_carre_1;
	vector_pos_deplacement=plateau(position)->getDeplacementPossible(plateau);
	sf::Clock clock;
	sf::Texture carre1,carre2,carre3;
	carre1.loadFromFile("images/carre_deplacement/carre_B_1.png");
	carre2.loadFromFile("images/carre_deplacement/carre_B_2.png");
	carre3.loadFromFile("images/carre_deplacement/carre_B_3.png");

	sf::Event event;
	bool fini=false;

	//on convertie les position de deplacement plateau en pixel
	for (size_t i = 0; i < vector_pos_deplacement.size(); i++)
	{
		vector_pos_deplacement[i].PositionToPx();
	}
	
	//on creer un vector de autant de sprite que de position de deplacement
	for (size_t i = 0; i < vector_pos_deplacement.size(); i++)
	{
		vector_sprite_carre_1.push_back((sf::RectangleShape (sf::Vector2f(30.0f,30.0f))));
	}

	//on accroche les positions en pixel convertie au début, pr chaqun des sprites du vector
	for (size_t i = 0; i < vector_pos_deplacement.size(); i++)
	{
		vector_sprite_carre_1[i].setPosition(vector_pos_deplacement[i].getX(),vector_pos_deplacement[i].getY());
	}
	
	//on affiche les sprites pr autant de position, sur la fenetre
	for (size_t i = 0; i < vector_pos_deplacement.size(); i++)
	{
		vector_sprite_carre_1[i].setTexture(&carre1);
	}

	while (waitEvent(event))
	{

		if (event.type == sf::Event::Closed)
        {
            close();
        }   
        else if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Right || event.mouseButton.button == sf::Mouse::Left)
            {
				pos_arrivee.setX(event.mouseButton.x / 50);
				pos_arrivee.setY(event.mouseButton.y / 50);
				effectuerActionClic(pos_arrivee);
				std::cout << pos_arrivee << std::endl;
				break;
				/*if (*find(vector_pos_deplacement.begin(), vector_pos_deplacement.end(), pos_arrivee) == pos_arrivee)
				{
					plateau(position)->deplacerSprite(_,pos_arrivee,plateau);
				} 
				else
				{

				}*/
            }
        }

		if (clock.getElapsedTime().asSeconds() > 0.2f)
		{
			for (size_t i = 0; i < vector_sprite_carre_1.size(); i++)
			{
				vector_sprite_carre_1[i].setTexture(&carre2);
			}
			
			if (clock.getElapsedTime().asSeconds() > 0.5f)
			{
				for (size_t i = 0; i < vector_sprite_carre_1.size(); i++)
				{
					vector_sprite_carre_1[i].setTexture(&carre3);
				}
				if (clock.getElapsedTime().asSeconds() > 0.8f)
				{
					clock.restart();
					
				}
			}
		}
		else
		{
			for (size_t i = 0; i < vector_sprite_carre_1.size(); i++)
			{
				vector_sprite_carre_1[i].setTexture(&carre3);
			}
		}


		dessinePlateau(plateau);
		afficherMenuAction(plateau,position);
		for (size_t i = 0; i < vector_sprite_carre_1.size(); i++)
		{
			draw(vector_sprite_carre_1[i]);
		}
		display();
		clear();
	}
}

void Fenetre::afficherAttaque(Plateau &plateau,const Position &position,Position &pos_arrivee)
{
	std::vector<Position> vector_pos_attaque;
	std::vector<sf::RectangleShape> vector_sprite_carre_1;
	vector_pos_attaque=plateau(position)->getAttaquePossible(plateau);
	sf::Clock clock;
	sf::Texture carre1,carre2,carre3;
	carre1.loadFromFile("images/carre_attaque/carre_attack_1.png");
	carre2.loadFromFile("images/carre_attaque/carre_attack_2.png");
	carre3.loadFromFile("images/carre_attaque/carre_attack_3.png");

	sf::Event event;
	bool fini=false;

	//on convertie les position de deplacement plateau en pixel
	for (size_t i = 0; i < vector_pos_attaque.size(); i++)
	{
		vector_pos_attaque[i].PositionToPx();
	}
	
	//on creer un vector de autant de sprite que de position de deplacement
	for (size_t i = 0; i < vector_pos_attaque.size(); i++)
	{
		vector_sprite_carre_1.push_back((sf::RectangleShape (sf::Vector2f(30.0f,30.0f))));
	}

	//on accroche les positions en pixel convertie au début, pr chaqun des sprites du vector
	for (size_t i = 0; i < vector_pos_attaque.size(); i++)
	{
		vector_sprite_carre_1[i].setPosition(vector_pos_attaque[i].getX(),vector_pos_attaque[i].getY());
	}
	
	//on affiche les sprites pr autant de position, sur la fenetre
	for (size_t i = 0; i < vector_pos_attaque.size(); i++)
	{
		vector_sprite_carre_1[i].setTexture(&carre1);
	}

	while (waitEvent(event))
	{

		if (event.type == sf::Event::Closed)
        {
            close();
        }   
        else if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Right || event.mouseButton.button == sf::Mouse::Left)
            {
				pos_arrivee.setX(event.mouseButton.x / 50);
				pos_arrivee.setY(event.mouseButton.y / 50);
				effectuerActionClic(pos_arrivee);
				std::cout << pos_arrivee << std::endl;
				break;
				/*if (*find(vector_pos_deplacement.begin(), vector_pos_deplacement.end(), pos_arrivee) == pos_arrivee)
				{
					plateau(position)->deplacerSprite(_,pos_arrivee,plateau);
				} 
				else
				{

				}*/
            }
        }

		if (clock.getElapsedTime().asSeconds() > 0.2f)
		{
			for (size_t i = 0; i < vector_sprite_carre_1.size(); i++)
			{
				vector_sprite_carre_1[i].setTexture(&carre2);
			}
			
			if (clock.getElapsedTime().asSeconds() > 0.5f)
			{
				for (size_t i = 0; i < vector_sprite_carre_1.size(); i++)
				{
					vector_sprite_carre_1[i].setTexture(&carre3);
				}
				if (clock.getElapsedTime().asSeconds() > 0.8f)
				{
					clock.restart();
					
				}
			}
		}
		else
		{
			for (size_t i = 0; i < vector_sprite_carre_1.size(); i++)
			{
				vector_sprite_carre_1[i].setTexture(&carre3);
			}
		}


		dessinePlateau(plateau);
		afficherMenuAction(plateau,position);
		for (size_t i = 0; i < vector_sprite_carre_1.size(); i++)
		{
			draw(vector_sprite_carre_1[i]);
		}
		display();
		clear();
		
	}


}
