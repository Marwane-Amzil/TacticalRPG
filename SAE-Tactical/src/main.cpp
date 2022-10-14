/*
#if _WIN32
    #pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif // !_WIN32
*/

#include <Fenetre.hpp>
#include <iostream>
/**
 * @brief Permet de savoir si une position est présente dans un vector de position
 * 
 * @return true 
 * @return false 
 */
bool verif_pos_dans_vector(const std::vector <Position> &vector_pos,const Position &pos)
{
    for (size_t i = 0; i < vector_pos.size(); i++)
    {
        if (vector_pos[i]==pos)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    Plateau plateau;
    Fenetre fenetre("images/plateau_14x.png");
    char joueur='B';
    Position pos_click_depart,pos_click_button,pos_click_TO;

    plateau.ajoutePersonnage(new Guerrier(0, 0, 'B'));
    plateau.ajoutePersonnage(new Guerrier(4, 4, 'B'));
    plateau.ajoutePersonnage(new Guerrier(4, 5, 'B'));
    plateau.ajoutePersonnage(new Guerrier(12, 13, 'B'));
    plateau.ajoutePersonnage(new Guerrier(13, 5, 'R'));
    plateau.ajoutePersonnage(new Guerrier(10, 4, 'R'));
    plateau.ajoutePersonnage(new Guerrier(4, 9, 'R'));
    plateau.ajoutePersonnage(new Guerrier(3, 7, 'R'));

    plateau.afficher();

    while (fenetre.isOpen())
    {
        sf::Event event;
        if (fenetre.pollEvent(event))
        {
            if (joueur == 'B')
            {
                std::cout << " au joueur bleu de jouer" << std::endl;
            }
            else
            {
                std::cout << " au joueur rouge de jouer" << std::endl;
            }

            fenetre.dessinePlateau(plateau);
            fenetre.display();

            //1. ----- on attend un click du joueur
            std::cout << "selectionner un personnage" << std::endl;
            fenetre.detecterClic(pos_click_depart);//on enregistre la position du click
            std::cout << "pos_click_depart -->" << pos_click_depart << std::endl;

            // si le click est sur un personnage , on affiche le menu des actions du personnage selectionné
            if (plateau(pos_click_depart) != nullptr && plateau(pos_click_depart)->getJoueur() == joueur)
            {
                Personnage* perso_selectionne = plateau(pos_click_depart);

                fenetre.afficherMenuAction(plateau, pos_click_depart);
                fenetre.display();

                //on attend un nouveau clique, pour savoir quelle action du menu est selectionné
                fenetre.detecterClic(pos_click_button);

                //click sur bouton deplacer
                if (fenetre.effectuerActionClic(pos_click_button) == 1 && perso_selectionne->getPeutDeplacer() == true)
                {
                    std::cout << "selectionner un deplacement" << std::endl;
                    fenetre.afficherDeplacement(plateau, pos_click_depart, pos_click_TO);
                    std::cout << "pos_click_arrivee -->" << std::endl, std::cout << pos_click_TO << std::endl;
                    std::vector <Position> vector_position_deplacement_possible = perso_selectionne->getDeplacementPossible(plateau);

                    //on verifie sur le click pos_TO correspond bien à une psoition de getDeplacement possible
                    if (verif_pos_dans_vector(vector_position_deplacement_possible, pos_click_TO) == true)
                    {
                        perso_selectionne->deplacerSprite(fenetre, pos_click_TO, plateau);
                        perso_selectionne->perso_check_tour_fini();
                        plateau.afficher();
                    }
                    else
                    {
                        std::cout << "deplacement impossible, car le click pos_TO n'est pas sur une position de deplacement du perso " << std::endl;
                    }
                }
                //click sur bouton attaquer
                else if (fenetre.effectuerActionClic(pos_click_button) == 2 && perso_selectionne->getPeutAttaquer() == true)
                {
                    fenetre.afficherAttaque(plateau, pos_click_depart, pos_click_TO);
                    std::vector <Position> vector_position_attaquer_possible = plateau(pos_click_depart)->getAttaquePossible(plateau);
                    if (verif_pos_dans_vector(vector_position_attaquer_possible, pos_click_TO) == true)
                    {
                        plateau(pos_click_depart)->attaquerSprite(pos_click_TO, plateau, fenetre);
                        plateau(pos_click_depart)->perso_check_tour_fini();
                    }
                }
                //click sur bouton passer tour
                else if (fenetre.effectuerActionClic(pos_click_button) == 3 && plateau(pos_click_depart)->getTourFini() == false)
                {
                    plateau(pos_click_depart)->tourFini(true);
                }
                
                if (plateau.tourFini(joueur))
                {
                    plateau.initTour();

                    if (joueur == 'B')
                    {
                        joueur = 'R';
                    }
                    else
                    {
                        joueur = 'B';
                    }
                }
            }
            else
            {
                std::cout << "Vous ne pouvez pas utiliser ce personnage." << std::endl;
            }
        }
    }

    return 0;
}