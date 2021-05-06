#ifndef JOUER_H
#define JOUER_H
#include <iostream>
#include<string>
#include "GameGenerator.h"
#include "grille.h"
using namespace std;

class jouer
{
   public:
        int num,x1,x2,y1,y2;//numero du mot dans la liste des mots, les coordonnées du mot choisi
        int x;// correct tries
        int y;//false tries
        jouer(int  num_max,int n,int m,int lang,int form);//un constructeur qui est défini pour le déroulement  du jeu
        jouer(int co_tries,int fa_tries);//un constructeur qui est défini pour le calcul du score
        jouer();//un 3eme constructeur pour l'affichage du score
        /************* fonctions de la forme losange ****/
        bool verifier(string *t,char** matrice_,int n);//verification du mot trouvé
        void grid_update(char**matrice_,int n);//marquer les positions des lettres du mot trouvé
        /************* fonctions de la forme rectangulaire ****/
         bool verifier_2(string *t,char** m);//verification du mot trouvé
        void grid_update_2(char**m);//marquer les positions des lettres du mot trouvé
        /*****************/
        string resultat(int number_of_words,int lang);//calcul du score
        void afficher_score();//affichage du score
};

#endif // JOUER_H
