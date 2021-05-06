#ifndef GAMEGENERATOR_H
#define GAMEGENERATOR_H
#include <iostream>
#include <vector>

using namespace std;

class GameGenerator {
     public:
        int number_of_words ;           //le nombre de mots que l'utilisateur va jouer.
        vector <std::string> Dic;       //le dictionnaire des mots.
        string * words_List;            //le tableau qui va contenir les mots choisis aleatoirement du dictionnaire Dic.
        int difficulte ;                 //difficulté du jeu.
        int tps_max;                    //le temps limite à ne pas depasser dans le jeu.


        GameGenerator(int diff,int lang);          //constructeur de classe GameGenerator.
        void dictionary(int lang);                //remplir le vector "Dic" par les mots du fichier dictionnaireFr ou dictionnaireAn .
        void generate_words  (int diff);          //choisir des mots aleatoirement du fichier vers le tableau "words_List"
        bool exist (int t[],int elem);           //chercher si un element "elem" figure deja dans un tableau
        void display_list(int lang);             //afficher la liste.
};


#endif // GAMEGENERATOR_H
