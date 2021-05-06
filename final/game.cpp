#include <iostream>
#include "GameGenerator.h"
#include "grille.h"
#include "jouer.h"
#include "game.h"
#include <vector>
#include <fstream>
#include <string>
#include<locale>
#include<chrono>
#include<unistd.h>
#include <thread>
#include<windows.h>
using namespace std;
game :: game() {
    setlocale(LC_CTYPE, "fra");
                                   //**************************************//
    int diff;//difficulte du jeu.
    int lang;//la langue choisie
    int choice;//choisir entre demarer le jeu ou consulter l'historique
    jouer score;
    int form;//choisir entre la forme rectangulaire et la forme losange


     do{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        cout<<"Choisissez la langue / Choose the language :"<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout<<"(1):English"<<endl<<"(2):Français"<<endl;

        cin>>lang;} while(lang!=1 && lang!=2 && lang!=0);

        if(lang==0) exit(404);
              //**************************************//


    if(lang==1){
    	 do
        {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);

                                     //**************************************//

            cout<<"                                     WELCOME IN THE MIXED WORDS               "<<endl<<endl;
            cout<<"Find the words proposed in the grid."<<endl<<"As soon as you find a word and give the coordinates, it is marked in the words list."<<endl<<endl;
             SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout<<"RULES OF THE GAME : "<<endl;
             SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            cout<<"You need to write successively the line of the first letter then its column , then the line of the last letter and finally its column."<<endl<<endl;
            cout<<"==> Press";
             SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout<<"(0)";
             SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            cout<<" to quit the game."<<endl<<endl;
                                     //**************************************//

             SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        cout<<"press ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        cout<<"(1) ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        cout<<"to check the history or any other key to start playing"<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cin>>choice;
            if (choice==1)
            {

                score.afficher_score();

            }
            if(choice==0) exit(404);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            cout<<"Choose the difficulty level:  "<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            cout<<" 1 : easy "<<endl<< " 2 : medium "<<endl<<" 3 : difficult " <<endl;
            cin>>diff;}while( diff!= 0 && diff!= 1 && diff!=2 && diff!=3);
            if(diff==0) exit(404); //**************************************//
	}

      if(lang==2){
 		do
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);

                                           //**************************************//
            cout<<"                                 BIENVENUE DANS LES MOTS MELES             "<<endl<<endl;
            cout<<"Trouvez dans la grille les mots proposés."<<endl<<"Dès que vous trouvez un mot et que vous donnez les coordonnées, il se marque dans la liste des mots."<<endl<<endl;
             SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout<<"REGLES DU JEU : "<<endl;
             SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            cout<<"Vous devez ecrire successivement la ligne de la 1ere lettre puis sa colonne , puis la ligne de la derniere lettre et sa colonne."<<endl<<endl;
            cout << "==> Appuyez sur ";
             SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout<<"(0)" ;
             SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            cout<<"pour quitter le jeu." << endl<<endl;
                                       //**************************************//

                                       //**************************************//
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        cout<<"cliquez sur ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        cout<<"(1) ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        cout<<"pour consulter l'historique ou cliquez sur autre touche quelconque pour commencer le jeu "<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cin>>choice;
            if (choice==1)
            {

                score.afficher_score();

            }
            if(choice==0) exit(404);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            cout<<"Choisir le niveau de difficulté: "<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            cout<<" 1 : facile "<<endl<< " 2 : moyen "<<endl<<" 3 : difficile " <<endl;
            cin>>diff;}while( diff!= 0 && diff!= 1 && diff!=2 && diff!=3);	}
            if(diff==0) exit(404); //**************************************//

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        if(lang==1){
            cout<<" press ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout<<"(1) ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout<<"to play the rectangle form ,press ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout<<"(2)";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout<<" to play the diamond form "<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);}
        else if(lang==2){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout<<" cliquez sur ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout<<"(1)";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout<<" pour choisir la forme rectangulaire , cliquez sur ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout<<"(2)";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout<<" pour choisir la forme losange"<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);}
            cin>>form;



    system("cls");                           //**************************************//

    GameGenerator start_game (diff,lang); //appel au constructeur de classe GameGenerator.

    grille grille (diff,form);

    start_game.dictionary(lang);

    start_game.generate_words (diff); //remplissage d'un tableau vide par des words_List du fichier aleatoirement.

    start_game.display_list(lang);


    if(form==2)
    {

        grille.remplir_grille(start_game.words_List,start_game.number_of_words);

        grille.afficher();


    }
    if(form==1)
        {

            grille.remplir_grille_2(start_game.words_List,start_game.number_of_words);


            grille.afficher_2();

        }//affichage de la grille}
   auto start=chrono::steady_clock::now();

    int x=0; //compte le nombre de mots trouvé.
    int y=0;//le nombre de faux essais
    int tps=0;

    thread th( [&](){
        this_thread::sleep_for( chrono::seconds(start_game.tps_max ));
       if(lang==1)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    cout<<"TIME'S UP"<<endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }

       if(lang==2)
				{
				    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				    cout<<"Votre temps est épuisé"<<endl;
				    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
        jouer scores(x,y);
        scores.resultat(start_game.number_of_words,lang);

        exit(-1);

        }     );




    while ( x<start_game.number_of_words )
        {
            if(form==2){
            jouer play(start_game.number_of_words,grille.n,grille.m,lang,form);
            if (play.verifier(start_game.words_List,grille.matrice_,grille.n))
            {
                    x++;
                    play. grid_update(grille.matrice,grille.n);
                    if(lang==1){start_game.words_List[play.num-1]="****FOUND WORD****";}
                    if(lang==2){start_game.words_List[play.num-1]="****Mot Trouvé****";}

                    auto end=chrono::steady_clock::now();

                    if(lang==1)
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                        cout<<"Elapsed time is : "<<chrono::duration_cast<chrono::seconds>(end-start).count()<<"seconds"<<endl;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    }
					if(lang==2)
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                        cout<<"Temps écoulé : "<<chrono::duration_cast<chrono::seconds>(end-start).count()<<"secondes"<<endl;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    }
                        tps+=chrono::duration_cast<chrono::seconds>(end-start).count();
            }
            else
            {
                    y++;
                    if(lang==1)
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                        cout<<"you entred the wrong word"<<endl;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    }
            		else if(lang==2)
                    {   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                        cout<<"le mot entré est faux" << endl;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    }
                    auto end=chrono::steady_clock::now();
                    if(lang==1)
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
						cout<<"Elapsed time is:  "<<chrono::duration_cast<chrono::seconds>(end-start).count()<<"seconds"<<endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    }
                    if(lang==2)
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    	cout<<"Temps écoulé :  "<<chrono::duration_cast<chrono::seconds>(end-start).count()<<"secondes"<<endl;
                    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    }
                    tps+=chrono::duration_cast<chrono::seconds>(end-start).count();
            }}
            else if(form==1)
            {
                jouer play(start_game.number_of_words,grille.n,grille.m,lang,form);
            if (play.verifier_2(start_game.words_List,grille.matrice_))//vérification du mot entré
            {
                    x++;
                    play. grid_update_2(grille.matrice);//mise à jour de la grille
                    if(lang==1){start_game.words_List[play.num-1]="****FOUND WORD****";}//mise à jour de la liste des mots à trouver
                    if(lang==2){start_game.words_List[play.num-1]="****Mot Trouvé****";}

                    auto end=chrono::steady_clock::now();

                    if(lang==1)
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                        cout<<"Elapsed time is : "<<chrono::duration_cast<chrono::seconds>(end-start).count()<<"seconds"<<endl;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    }
					if(lang==2)
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                        cout<<"Temps écoulé : "<<chrono::duration_cast<chrono::seconds>(end-start).count()<<"secondes"<<endl;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    }
                        tps+=chrono::duration_cast<chrono::seconds>(end-start).count();
            }
            else
            {
                    y++;
                    if(lang==1)
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                        cout<<"you entred the wrong word"<<endl;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    }
            		else if(lang==2)
                    {   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                        cout<<"le mot entré est faux" << endl;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    }
                    auto end=chrono::steady_clock::now();
                    if(lang==1)
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
						cout<<"Elapsed time is:  "<<chrono::duration_cast<chrono::seconds>(end-start).count()<<"seconds"<<endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    }
                    if(lang==2)
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    	cout<<"Temps écoulé :  "<<chrono::duration_cast<chrono::seconds>(end-start).count()<<"secondes"<<endl;
                    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    }
                    tps+=chrono::duration_cast<chrono::seconds>(end-start).count();
            }
            }

            thread t( [&](){
                this_thread::sleep_for( chrono::seconds(1));});
            t.join();

            system("cls");

            start_game.display_list(lang);

            if(form==2)
                grille.afficher();
            if(form==1)
                 grille.afficher_2();

        }

        system("cls");


    if(x == start_game.number_of_words)
        {

                jouer scores(x,y);
                scores.resultat(start_game.number_of_words,lang);
                scores.afficher_score();

               exit(0);

        }

   th.join();
}



