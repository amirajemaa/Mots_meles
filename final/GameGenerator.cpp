#include "GameGenerator.h"
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include<cstdlib>
#include<windows.h>

using namespace std;

GameGenerator::GameGenerator(int diff,int lang)
{
    difficulte=diff;
    //controle de la longueur de liste des mots et le temps max du jeu selon la difficulte choisie par l'utilisateur.
    if (difficulte==1) {number_of_words=5;tps_max =120;}
    else if (difficulte==2) {number_of_words=10;tps_max =200;}
    else {number_of_words=20;tps_max =400;}

    words_List=new string[number_of_words];        //intialisation du tableau "words_List".


}

void GameGenerator::dictionary(int lang){
     string monFichier2("dictionnaireFr.TXT"); //le dictionnaire français.
     string monFichier1("dictionnaireAn.TXT"); //le dictionnaire anglais.
     string ligne;

	if(lang==1){    //si le joueur a choisi la langue anglaise.
	ifstream monFlux(monFichier1.c_str()); //lecture du fichier à travers un flux et mettre chaque ligne dans une case du tableau "Dic".
	  	if(monFlux){

         while(getline(monFlux, ligne))
         	{
             Dic.push_back(ligne);     //remplir le Dic par tous les mots contenus dans le dictionnaireFr.
        	}
		}
 		else
		{
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
         cout << "ERROR: PROBLEM OCCURED WHILE OPENING THE FILE." << endl;
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
 	}
    else if(lang==2){
	ifstream monFlux(monFichier2.c_str());
	if(monFlux){

         while(getline(monFlux, ligne))
         	{
             Dic.push_back(ligne);   //remplir le Dic par tous les mots contenus dans le dictionnaireAn.
        	}
		}
 		else
		{
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
         cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}}


}


void GameGenerator:: generate_words (int diff)   //Generer les mots a partir du Dic.
{    int i=Dic.size();
     int j=0;
     int nombre[number_of_words];       //ce tableau va contenir les positions auhasard choisis aleatoirement avec succes.
     int auHasard;
     if (difficulte==1) //niveau facile.
        {
            for (j=0;j<number_of_words;j++)
            {
                srand(time(0));
                auHasard = rand()%(i);     //generer une position auHasard inferieur au size du Dic.
                //verifier si cette position est deja pris ou le mot a une longueur superieur a 9.
                while ( exist(nombre, auHasard)|| (Dic[auHasard].size() > 9) )
                    {
                        auHasard = rand()%(i);  //generer une autre position.
                    }
                words_List[j]=Dic[auHasard];    //ajout du mot dans la liste avec succes.
                nombre[j]=auHasard;             //garder la trace de la position prise dans le tableau nombre.
            }
        }
     else if (difficulte==2)//niveau moyen.
        {
            for (j=0;j<number_of_words;j++)
            {
                srand(time(0));
                auHasard = rand()%(i);
                while ( exist(nombre, auHasard)|| (Dic[auHasard].size() > 14))
                {
                    auHasard = rand()%(i);
                }
                words_List[j]=Dic[auHasard];
                nombre[j]=auHasard;
            }
        }
    else if (difficulte==3) //niveau difficile.
        {
            for (j=0;j<number_of_words;j++)
            {
               srand(time(0));
               auHasard = rand()%(i);
               while ( exist(nombre, auHasard)|| (Dic[auHasard].size() > 19) )
               {
                   auHasard = rand()%(i);
               }
               words_List[j]=Dic[auHasard];
               nombre[j]=auHasard;
            }
        }
}

void GameGenerator::display_list(int lang){
	if(lang==1)
	 	{
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	 	    cout<<"Find these words :"<<endl;
	 	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	 	}
    if(lang==2)
		{
		    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		    cout<<"Trouvez les mots suivants : "<<endl;
		    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}

    for (int i=0;i<number_of_words;i++)
            {

                cout<<i+1<<"/ "<<words_List[i]<<endl;


            }
    cout<<endl;


}
 bool GameGenerator:: exist(int t[],int elem){
    bool chercher=false;
    int k=0;
    while ((k<number_of_words)&&(chercher==false)){
        if (t[k]==elem) chercher=true;
        k++;
    }
   return chercher ;
}
