/*
Programme ; Jeu de l'equipage
But : jouer au jeu de l'equipage
Date de derniere modification : 21/10/23
Remarques : code conforme aux specifications internes donnee en cours
*/
#include "game-tools.h"
#include <iostream>
using namespace std;

int main(void)
{
    // VARIABLES
    unsigned int compteurLance;          // nombre de lancés réalisés au fur et à mesure de la partie
    string pseudoHum;                    // pseudo saisie par la personne qui joue contre la machine
    string equipHum = "NON_EQUIPE";      // équipement du joueur humain tout au long de la partie
    string equipMach = "NON_EQUIPE";     // équipement de la machine tout au long de la partie
    unsigned int scoreLancerCourant = 0; // Score de chaque lancer de l'humain ou de la machine
    unsigned int scoreJoueurHum = 0;     // Score de l'humain tout au long de la partie
    unsigned int scoreJoueurMach = 0;    // Score de la machine tout au long de la partie
    bool verifBateau = false;            // Vérifie si le bateau a déjà été tiré
    bool verifCapitaine = false;         // Vérifie si le capitaine a déjà été tiré
    bool verifEquipage = false;          // Vérifie si l’équipage a déjà été tiré
    bool continuer = false;              // Réponse du joueur pour savoir si il veut continuer à jouer
    char reponse;                        // Reponse du joueur pour savoir si il veut continuer
    string joueurActu;                   // Définit le joueur qui doit jouer
    unsigned short int nombreAlea;       // Nombre généré aléatoirement
    unsigned short int de;               // Valeur du dé
    string deTirer;                      // Liste de tout les dès tirers lors d'un lancer
    unsigned short int iterateur = 0;    // Itérateur pour une boucle for
    // TRAITEMENTS

    // INITIALISER LA PARTIE

    int PNT_BATEAU = 600;            // nombre de point qu'un bateau vaut dans la partie, les points sont donné lorsque un « 6 » est tiré
    int PNT_CAPITAINE = 500;         // nombre de point qu'un capitaine vaut dans la partie, les points sont donné lorsque un « 5 »est tiré
    int PNT_EQUIPAGE = 400;          // nombre de point qu'un equipage vaut dans la partie, les points sont donné lorsque un « 4 »est tiré
    unsigned int compteurManche = 0; // nombre de manches réalisés au fur et à mesure de la partie
    // MODIFIER LES PARAMETRES
    cout << "Voulez-vous modifier les parametres du jeu ? (O/N) " << endl;
    cin >> reponse;
    switch (reponse)
    {
    case 'O': // CAS OU LA REPONSE EST EN MAJUSCULE

        // CHANGER LES POINTS DE BATEAU
        cout << "Choisir le nombre de point que vaut un bateau " << endl;
        cin >> PNT_BATEAU;
        // CHANGER LES POINTS DU CAPITAINE
        cout << "Choisir le nombre de point que vaut un capitaine " << endl;
        cin >> PNT_CAPITAINE;
        // CHANGER LES POINTS DE L'EQUIPAGE
        cout << "Choisir le nombre de point que vaut un equipage " << endl;
        cin >> PNT_EQUIPAGE;
        break;

    case 'o': // CAS OU LA REPONSE EST EN MINISCULE

        // CHANGER LES POINTS DE BATEAU
        cout << "Choisir le nombre de point que vaut un bateau " << endl;
        cin >> PNT_BATEAU;
        // CHANGER LES POINTS DU CAPITAINE
        cout << "Choisir le nombre de point que vaut un capitaine " << endl;
        cin >> PNT_CAPITAINE;
        // CHANGER LES POINTS DE L'EQUIPAGE
        cout << "Choisir le nombre de point que vaut un equipage " << endl;
        cin >> PNT_EQUIPAGE;
        break;

    case 'N': // CAS AU CAS OU LA REPONSE EST EN MAJUSCULE
        break;

    case 'n':
        break;

    default:
        break;
    }
    // CHOISIR LE PSEUDO DE L'HUMAIN
    cout << "Quel pseudo voulez-vous choisir ? " << endl;
    cin >> pseudoHum;

    // JOUER LA PARTIE

    // DEFINIR LE JOUEUR
    joueurActu = "Humain";
    do
    {
        // JOUER LA MANCHE
        // REMETTRE LES VARIABLES A DES VALEURES DE BASES POUR UN BON FONCTIONNEMENT
        equipHum = "";
        equipMach = "";
        verifBateau = false;
        verifCapitaine = false;
        verifEquipage = false;
        cout << "Bilan partiel AVANT la nouvelle manche : " << endl;
        cout << "-score " << pseudoHum << " = " << scoreJoueurHum << endl;
        cout << "-score Machine = " << scoreJoueurMach << endl;
        // DETERMINER LE JOUEUR
        if (joueurActu == "Humain")
        {
            if (compteurManche < 5) // VERIFICATION QUE MOINS DE 5 MANCHES SE SONT PASSER
            {
                compteurManche += 1;
                cout << "Manche # " << compteurManche << " joueur " << pseudoHum << endl;
            }
            else
            {
                break;
            }
        }
        else
        {
            cout << "Manche # " << compteurManche << " joueur Machine " << endl;
        }
        compteurLance = 0;
        // JOUER LES LANCERS
        do
        {
            scoreLancerCourant = 0;
            compteurLance += 1;
            deTirer = ""; //
            // TIRER 5 NOMBRES ALEATOIRES
            for (iterateur = 1; iterateur <= 5; iterateur++)
            {
                // TIRER UN NOMBRE ALEATOIRE
                nombreAlea = random(1, 6);
                de = nombreAlea; // ASSIGNATION DU NOMBRE ALEATOIRE AU DE

                // AJOUT DES POINTS EN FONCTION DE LA VALEUR DU DE

                switch (de)
                {
                case 6:
                    deTirer += "6 ";
                    if (verifBateau == false && verifCapitaine == false && verifEquipage == false) // VERIFICATION QUE LE BATEAU N'A PAS DEJA ETE TIRE POUR AJOUTER LES POINTS D'UN BATEAU
                    {

                        verifBateau = true;
                        if (joueurActu == "Humain") // AJOUT DES POINTS AU SCORE DU LANCER EN FONCTION DU JOUEUR
                        {
                            equipHum = "Bateau";
                            scoreLancerCourant += PNT_BATEAU;
                        }
                        else
                        {
                            equipMach = "Bateau";
                            scoreLancerCourant += PNT_BATEAU;
                        }
                    }
                    if (verifBateau == true && verifCapitaine == true && verifEquipage == true) /*VERIFICATION QUE LE BATEAU, LE CAPITAINE ET L'EQUIPAGE ONT DEJA ETE TIRE
                                                                                                POUR NE PAS RAJOUTER LES POINTS D'UN BATEAU MAIS LES POINTS NORMAUX*/
                    {

                        scoreLancerCourant += 6;
                    }

                    break;
                case 5:
                    deTirer += "5 ";
                    if (verifBateau == true && verifCapitaine == false && verifEquipage == false) // VERIFICATION QUE LE CAPITAINE N'A PAS DEJA ETE TIRE POUR AJOUTER LES POINTS D'UN CAPITAINE
                    {

                        verifCapitaine = true;
                        if (joueurActu == "Humain") // AJOUT DES POINTS AU SCORE DU LANCER EN FONCTION DU JOUEUR
                        {
                            equipHum = "Bateau_Capitaine";
                            scoreLancerCourant += PNT_CAPITAINE;
                        }
                        else
                        {
                            equipMach = "Bateau_Capitaine";
                            scoreLancerCourant += PNT_CAPITAINE;
                        }
                    }
                    if (verifBateau == true && verifCapitaine == true && verifEquipage == true) /*VERIFICATION QUE LE BATEAU, LE CAPITAINE ET L'EQUIPAGE ONT DEJA ETE TIRE
                                                                                                POUR NE PAS RAJOUTER LES POINTS D'UN CAPITAINE MAIS LES POINTS NORMAUX*/
                    {

                        scoreLancerCourant += 5;
                    }
                    break;
                case 4:
                    if (verifBateau == true && verifCapitaine == true && verifEquipage == true) /*VERIFICATION QUE LE BATEAU, LE CAPITAINE ET L'EQUIPAGE ONT DEJA ETE TIRE
                                                                                                POUR NE PAS RAJOUTER LES POINTS D'UN EQUIPAGE MAIS LES POINTS NORMAUX*/
                    {

                        scoreLancerCourant += 4;
                    }
                    deTirer += "4 ";
                    if (verifBateau == true && verifCapitaine == true && verifEquipage == false) // VERIFICATION QUE LE EQUIPAGE N'A PAS DEJA ETE TIRE POUR AJOUTER LES POINTS D'UN EQUIPAGE
                    {

                        verifEquipage = true;
                        if (joueurActu == "Humain") // AJOUT DES POINTS AU SCORE DU LANCER EN FONCTION DU JOUEUR
                        {
                            equipHum = "Bateau_Capitaine_Equipage";
                            scoreLancerCourant += PNT_EQUIPAGE;
                        }
                        else
                        {
                            equipMach = "Bateau_Capitaine_Equipage";
                            scoreLancerCourant += PNT_EQUIPAGE;
                        }
                    }

                    break;
                case 3:
                    deTirer += "3 ";
                    if (verifBateau == true && verifCapitaine == true && verifEquipage == true) /*VERIFICATION QUE LE BATEAU, LE CAPITAINE ET L'EQUIPAGE
                                                                                                ON DEJA ETE TIRE POUR AJOUTER LES POINTS NORMAUX*/
                    {

                        scoreLancerCourant += 3;
                    }
                    break;
                case 2:
                    deTirer += "2 ";
                    if (verifBateau == true && verifCapitaine == true && verifEquipage == true) /*VERIFICATION QUE LE BATEAU, LE CAPITAINE ET L'EQUIPAGE
                                                                                                ON DEJA ETE TIRE POUR AJOUTER LES POINTS NORMAUX*/
                    {

                        scoreLancerCourant += 2;
                    }
                    break;
                case 1:
                    deTirer += "1 ";
                    if (verifBateau == true && verifCapitaine == true && verifEquipage == true) /*VERIFICATION QUE LE BATEAU, LE CAPITAINE ET L'EQUIPAGE
                                                                                                ON DEJA ETE TIRE POUR AJOUTER LES POINTS NORMAUX*/
                    {

                        scoreLancerCourant += 1;
                    }

                default:
                    break;
                }

                // AJOUT DES POINTS DU LANCER AU SCORE DU JOUEUR
            }

            // FIN DE CHAQUE LANCER
            if (joueurActu == "Humain") // AJOUT DES POINTS DU LANCER COURANTS AU SCORE DU JOUEUR ACTUEL
            {
                scoreJoueurHum += scoreLancerCourant; // AJOUT DES POINTS DU LANCER COURANTS AU SCORE DU JOUEUR HUMAIN
            }
            else
            {
                scoreJoueurMach += scoreLancerCourant; // AJOUT DES POINTS DU LANCER COURANTS AU SCORE DU JOUEUR MACHINE
            }
            if (joueurActu == "Humain")
            { // AFFICHER LE BILAN DU LANCER DU JOUEUR HUMAIN
                cout << "Lancer numero : " << compteurLance << endl;
                cout << "Contenu du lancer : " << deTirer << endl;
                cout << "-Bilan du lancer : " << endl;
                cout << "   -Equipement = " << equipHum << endl;
                cout << "   -Score du lancer = " << scoreLancerCourant << endl;
                cout << "   -Nouveau score pour " << pseudoHum << " = " << scoreJoueurHum << endl;
                cout << "Voulez-vous continuer (O/N) " << endl;
                cin >> reponse;

                switch (reponse)
                {
                case 'O':
                    continuer = true;
                    break;
                case 'o':
                    continuer = true;
                    break;
                case 'N':
                    continuer = false;
                    break;
                case 'n':
                    continuer = false;
                    break;

                default:
                    break;
                }
            }
            else
            { // AFFICHER LE BILAN DU LANCER DU JOUEUR MACHINE
                cout << "Lancer numero : " << compteurLance << endl;
                cout << "Contenu du lancer : " << deTirer << endl;
                cout << "Bilan du lancer : " << endl;
                cout << "   -Equipement = " << equipMach << endl;
                cout << "   -Score du lancer = " << scoreLancerCourant << endl;
                cout << "   -Nouveau score pour Machine = " << scoreJoueurMach << endl;
            }
            if (continuer == false)
            {
                cout << "Vous avez choisi d'abandonner par consequent le joueur Machine a gagne la partie" << endl;
                pause(5);
                break;
            }

        } while (compteurLance != 3); // BOUCLE POUR SAVOIR SI LES TROIS MANCHES
        // CHANGER DE JOUEUR
        if (joueurActu == "Humain")
        {
            joueurActu = "Machine";
        }
        else
        {
            joueurActu = "Humain";
        }

    } while (continuer != false);
    // FINALISER LA PARTIE
    if (continuer == false) // TEST POUR QUE QUAND LE JOUEUR HUMAIN ABANDONNE LE PROGRAMME N'AFFICHE PAS LA FIN DE PARTIE NORMAL
    {
    }
    else
    { // FIN DE PARTIE SI LE JOUEUR HUMAIN N'A PAS ABANDONNE
        if (scoreJoueurHum < scoreJoueurMach)
        {
            cout << "Dommage " << pseudoHum << " ! ton score : " << scoreJoueurHum << " < au score de la machine : " << scoreJoueurMach << endl; // AFFICHAGE DE FIN DE PARTIE SI LE JOUEUR HUMAIN A PERDU
        }
        else
        {
            cout << "Bravo " << pseudoHum << " ! ton score : " << scoreJoueurHum << " > au score de la machine : " << scoreJoueurMach << endl; // AFFICHAGE DE FIN DE PARTIE SI LE JOUEUR HUMAIN A GAGNE
        }
    }

    return 0;
}