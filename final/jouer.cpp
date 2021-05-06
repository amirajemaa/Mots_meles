#include "jouer.h"
#include "GameGenerator.h"
#include "grille.h"
#include <iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include<windows.h>
using namespace std;

jouer:: jouer(int num_max , int n,int m, int lang,int form) // num_max:le nombre des mots avec lesquels vous allez jouer
            {	if(lang==1)
            	{

                do{
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
                        cout<<" number of the word :";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        cin>>num;} while(num<0 || num >num_max  ); // controle de saisie sur le numéro du mot entré

                        if(num==0) exit(404); //**************************************//

                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
                        cout<<" Enter the coordinates of the word :"<<endl;       //*******************//
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

                do{
                        cin>>x1;} while(x1<0 || x1> n );    //controle de saisie sur l'abscisse entrée

                        if(x1==0) exit(404);  //*******************//

              if(form==2)
                {
                    do{
                        cin>> y1;} while(y1<0 || y1> n ); }  //controle de saisie sur l'ordonnée entrée

            else{
                    do{
                        cin>> y1;} while(y1<0 || y1> m );   //controle de saisie sur l'ordonnée entrée

                }
                       if(y1==0) exit(404);  //*******************//
                do{
                        cin>>x2;} while(x2<0|| x2> n );

                        if (x2==0) exit(404); //*******************//

               if(form==2)
                {
                    do {

                        cin>>y2;} while(y2<0 || y2> n );
                }
                else
                {
                    do {

                        cin>>y2;} while(y2<0 || y2> m );
                }


                        if(y2==0) exit(404); //*******************//
            	}

            	else if(lang==2)
            	{

                do{
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
                        cout<<" numero de mot :";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        cin>>num;} while(num<0 || num >num_max ); // controle de saisie sur le numéro du mot entré
                        if(num==0) exit(404); //*******************//

                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
                        cout<<" Donner les coordonnées du mot :"<<endl; //*******************//
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

                do{
                        cin>>x1;} while(x1<0 || x1> n );    //controle de saisie sur l'abscisse entrée
                        if(x1==0) exit(404);  //*******************//

                if (form==2)
                {
                    do{
                        cin>> y1;} while(y1<0 || y1> n);}   // //controle de saisie sur l'ordonnée entrée
                else
                {
                    do{
                        cin>> y1;} while(y1<0 || y1> m);
                }
                        if(y1==0) exit(404);//*******************//
                do{

                        cin>>x2;} while(x2<0|| x2> n );
                        if(x2==0) exit(404);//*******************//

                if(form==2){
                do {
                        cin>>y2;} while(y2<0 || y2> n );}
                else
                    {
                        do {
                        cin>>y2;} while(y2<0 || y2> m );}
                    }

                        if(y2==0) exit(404);//*******************//
                   }

jouer::jouer(int co_tries,int fa_tries) // un deuxième constructeur pour le score
{
    x=co_tries;
    y=fa_tries;
}
jouer::jouer()//un 3eme constructeur pour l'affichage du score
{

}
 bool jouer:: verifier(string* t,char** matrice_,int n)
{
                int i;
                int j ;
                string ch,ch1,ch2;
                string mot =t[num-1];

                if (x1==x2) // cas le mot est placé horizontalement
                    {
                        for (i=y1-1;i<=y2-1;i++)// l'indice de ligne est fixé
                        {
                            ch+=matrice_[x1-1][i];
                        }
                        if (ch==mot)//verification du mot qu'on a trouvé avec le mot trouvé dans le tableau sous l'indice que tu as entré au debut
                            return true;
                        return false;
                    }


                else if ( ((x1-1)<n/2) && ((x2-1)>=n/2) && (y2==y1+n-x1-x2+1) ) // cas le mot est placé verticalement tout le long de la grille
                    {
                            for (i=x1-1,j=y1-1;i<=n/2;i++,j++)
                            {
                                ch1+=matrice_[i][j];
                            }

                            for (i=n/2 +1 ,j=y1-1-x1+n/2;i<=x2-1;i++,j--)
                            {
                                ch2+=matrice_[i][j];
                            }
                            if (ch1+ch2==mot)
                                return true;
                            return false;
                    }
                else if (((x1-1)>=n/2)&&(y2==y1-x2+x1))  // cas le mot est placé verticalement dans la moitié inférieure de la grille
                {
                           for (i=x1-1,j=y1-1;i<=x2-1;i++,j--)
                            {
                                ch+=matrice_[i][j];
                            }
                            if (ch==mot)
                                return true;
                            return false;
                }
                else if (((x1-1)<n/2)&&((x2-1)<=n/2)&&(y2==y1+x2-x1)) // cas le mot est placé verticalement dans la moitié supérieure de la grille
                {
                           for (i=x1-1, j=y1-1;i<=x2-1;i++,j++)
                            {
                                ch+=matrice_[i][j];
                            }
                            if (ch==mot)
                                return true;
                            return false;
                       }
                else if  ( ((x1-1)<n/2) && ((x2-1)>=n/2) && (y2==y1+2*(n/2 -x1 +1)) )  // cas le mot est placé diagonalement tout le long de la grille
                {
                        for (i=x1-1, j=y1-1;i<=n/2;i++ , j=j+2)
                        {
                            ch1+=matrice_[i][j];
                        }
                        for (i=n/2 + 1 ; i<=x2-1 ;i++ )
                        {
                            ch2+=matrice_[i][y2-1];
                        }

                        if (ch1+ch2==mot)
                            return true;
                        return false;
                    }
                else if ( ((x1-1)>=n/2)&&(y2==y1) ) // cas le mot est placé diagonalement dans la moitié inférieure de la grille
                    {
                        for (i=x1-1;i<=x2-1;i++)
                        {
                            ch+=matrice_[i][y1-1];
                        }
                        if (ch==mot)
                            return true;
                        return false;
                    }
                else if  ( ((x1-1)<n/2) && ((x2-1)<=n/2) && (y2==y1+2*(x2-x1)) )// cas le mot est placé diagonalement dans la moitié supérieure de la grille
                    {
                        for (i=x1-1, j=y1-1;i<=x2-1;i++ , j=j+2)
                        {
                            ch+=matrice_[i][j];
                        }
                        if (ch==mot)
                            return true;
                        return false;
                    }
                else return false;

            }
void jouer :: grid_update(char** matrice_,int n)
            {
                int i;
                int j ;
                if (x1==x2) // cas le mot est placé horizontalement
                    {
                        for (i=y1-1;i<=y2-1;i++)// l'indice de ligne est fixé
                        {
                            matrice_[x1-1][i]='*';
                        }
                    }


                else if ( ((x1-1)<n/2) && ((x2-1)>=n/2) && (y2==y1+n-x1-x2+1) ) // cas le mot est placé verticalement tout le long de la grille
                    {
                            for (i=x1-1,j=y1-1;i<=n/2;i++,j++)
                            {
                                matrice_[i][j]='*';
                            }

                            for (i=n/2 +1 ,j=y1-1-x1+n/2;i<=x2-1;i++,j--)
                            {
                                matrice_[i][j]='*';
                            }
                    }
                else if (((x1-1)>=n/2)&&(y2==y1-x2+x1))  // cas le mot est placé verticalement dans la moitié inférieure de la grille
                {
                           for (i=x1-1,j=y1-1;i<=x2-1;i++,j--)
                            {
                                matrice_[i][j]='*';
                            }
                }
                else if (((x1-1)<n/2)&&((x2-1)<=n/2)&&(y2==y1+x2-x1)) // cas le mot est placé verticalement dans la moitié supérieure de la grille
                {
                           for (i=x1-1, j=y1-1;i<=x2-1;i++,j++)
                            {
                                matrice_[i][j]='*';
                            }
                       }
                else if  ( ((x1-1)<n/2) && ((x2-1)>=n/2) && (y2==y1+2*(n/2 -x1 +1)) )  // cas le mot est placé diagonalement tout le long de la grille
                {
                        for (i=x1-1, j=y1-1;i<=n/2;i++ , j=j+2)
                        {
                            matrice_[i][j]='*';
                        }
                        for (i=n/2 + 1 ; i<=x2-1 ;i++ )
                        {
                           matrice_[i][y2-1]='*';
                        }
                    }
                else if ( ((x1-1)>=n/2)&&(y2==y1) ) // cas le mot est placé diagonalement dans la moitié inférieure de la grille
                    {
                        for (i=x1-1;i<=x2-1;i++)
                        {
                            matrice_[i][y1-1]='*';
                        }
                    }
                else if ( ((x1-1)<n/2) && ((x2-1)<=n/2) && (y2==y1+2*(x2-x1)) )// cas le mot est placé diagonalement dans la moitié supérieure de la grille
                    {
                        for (i=x1-1, j=y1-1;i<=x2-1;i++ , j=j+2)
                        {
                            matrice_[i][j]='*';
                        }
                    }
            }
            /**************************************/
            bool jouer:: verifier_2(string* t,char** m)
            {
                int i;
                int j ;
                string ch;
                if (x1==x2) // cas le mot est placé horizontalement
                    {
                        for (i=y1-1;i<=y2-1;i++)// l'indice de ligne est fixé
                        {
                            ch+=m[x1-1][i];
                        }
                        if (ch==t[num-1])//verification du mot qu'on a trouvé avec le mot trouvé dans le tableau sous l'indice que tu as entré au debut
                            return true;
                        return false;
                    }
                else if(y1==y2)    // cas le mot est placé verticalement
                    {
                        for (i=x1-1;i<=x2-1;i++) //l'indice de colonne est fixé
                        {
                            ch+=m[i][y1-1];
                        }
                        if (ch==t[num-1])
                            return true;
                        return false;
                    }
                else if (x1+t[num-1].length() -1==x2 && y1+t[num-1].length() -1==y2 )// cas le mot est placé diagonalement
                    {
                     for (i=x1-1, j=y1-1;i<=x2-1 , j<=y2-1 ;i++ , j++)
                        {
                            ch+=m[i][j];
                        }
                        if (ch==t[num-1])
                            return true;
                        return false;
                    }
                else return false;

            }
void jouer :: grid_update_2(char** m)
            {
              if (x1==x2) // cas le mot est placé horizontalement
                    {
                        for (int i=y1-1;i<=y2-1;i++)
                        {
                            m[x1-1][i]='*'; //chaque caractere du mot trouvé sera remplacé par une étoile
                        }

                    }
                else if (y1==y2) // cas le mot est placé verticalement
                    {
                        for (int k=x1-1;k<=x2-1;k++)
                        {
                            m[k][y1-1]='*';//chaque caractere du mot trouvé sera remplacé par une étoile
                        }


                    }
                    else // cas le mot est placé diagonalement
                    {
                            for (int k=x1-1 ,  j = y1-1 ;k<=x2-1 , j<=y2-1;k++ , j++)
                        {
                            m[k][j]='*';////chaque caractere du mot trouvé sera remplacé par une étoile
                        }



                    }
                }

    string jouer:: resultat(int number_of_words,int lang)
    {
        int score;
        float p;
        string res;
        res="score";
        ofstream f("score.txt",ios::app);
        if(! f.is_open())
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout<<"impossible d'ouvrir le fichier en mode ecriture"<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        }
        else
        {
           score=10*x-y;
        	if(score<0) score=0;
            p=((float)x/(float)number_of_words)*100;
            if(p<25)
                    {	if(lang==1)
                        {   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
                            cout<<"Oops,retry next time"<<endl<<"Your score is: "<<score<<"/"<<10*number_of_words<<endl;
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        }
                        if(lang==2)
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                            cout<<"Oops,ressayez la prochaine fois"<<endl<<"Votre score est: "<<score<<"/"<<10*number_of_words<<endl;
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        }
                        f<<score<<endl;
                    }
            else if(p<50)
                    {	if(lang==1)
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                            cout<<"Nice try! try harder the next time"<<endl<<"Your score is: "<<score<<"/"<<10*number_of_words<<endl;
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        }
                        if(lang==2)
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                            cout<<"Bien joué!Vous pouvez mieux faire!"<<endl<<"Votre score est: "<<score<<"/"<<10*number_of_words<<endl;
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        }
                        f<<score<<endl;
                    }
            else if(p<75)
                    {	if(lang==1)
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                            cout<<"Good!"<<endl<<"Your score is: "<<score<<"/"<<10*number_of_words<<endl;
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

                        }
                        if(lang==2)
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                            cout<<"BIEN!"<<endl<<"Votre score est: "<<score<<"/"<<10*number_of_words<<endl;
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        }
                        f<<score<<endl;
                    }
            else
                    { 	if(lang==1)
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                            cout<<"AWESOME!!"<<endl<<"Your score is: "<<score<<"/"<<10*number_of_words<<endl;
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        }
						if(lang==2)
						{
						    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
							cout<<"TRES BIEN!!"<<endl<<"Votre score est: "<<score<<"/"<<10*number_of_words<<endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
						}
                        f<<score<<endl;
                    };
            f.close();
    }return(res);
    }
void jouer::afficher_score()
       {    ifstream f("score.txt");
            vector< int > arr;//il contient le contenu de fichier score
            arr.push_back(0);
            arr.push_back(0);
            arr.push_back(0);
            arr.push_back(0);
            arr.push_back(0);
            int c;//un score dans le fichier
            while(f>>c)
            {   if (c==0) arr.push_back(c);
                else if(find(arr.begin(), arr.end(),c) == arr.end()&& c!=0)//verify if the elmnt dosent exist in vector
				arr.push_back(c);
            }
            sort(arr.begin(), arr.end(),greater<int>());//sort the vector (decroissant)
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            cout<<"TOP LAST SCORES :"<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

            for(int i=0;i<5;i++)
            {cout<<i+1<<"/"<<arr[i]<<endl;}
			f.close();
        }














