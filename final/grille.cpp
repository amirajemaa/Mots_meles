#include "grille.h"
#include<iostream>
#include<string>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include "point.h"
#include <vector>


grille :: grille(int difficulte,int form)
{
          if ((difficulte==1)&&(form==2)){ n=15; }
          else if((difficulte==1)&&(form==1)){n=10;m=9;}
        else if ((difficulte==2)&&(form==1)){ n=17;m=14;}
         else if ((difficulte==2)&&(form==2)){ n=17;}
        else if((difficulte==3)&&(form==1)) { n=21;m=19;}
        else if((difficulte==3)&&(form==2)) { n=21;}

  if((difficulte==1)&&(form==2)||( ((difficulte==2)&&(form==2)))||((difficulte==3)&&(form==2))){     //char** matrice_;
        matrice_=new char*  [n];
        matrice=new char*  [n];
        int h =1;


            for(int i=0; i<n/2; i++)
            {

            matrice_[ i]=new char [h];
            matrice[ i]=new char [h];
            h+=2;

            }

             for(int i=n/2; i<n; i++)
            {

            matrice_[ i]=new char [h];
              matrice[ i]=new char [h];
            h-=2;
            }}


        //definir la matrice
else if(((difficulte==1)&&(form==1))|| ((difficulte==2)&&(form==1)) || ((difficulte==3)&&(form==1))){
       matrice_=new char*  [n];
        matrice=new char*  [n];
        for(int i=0; i<n; i++)
            {
            matrice_[ i]=new char [m];
            matrice[ i]=new char [m];
            }

       }}
void grille::initialiser_2()
{

        for (int i=0; i<n; i++) //on initialise les valeurs de la matrice à 0
        {
            for (int j=0; j<m; j++)
                {
                    (matrice_[ i][ j])= '0';
                    (matrice[ i][ j])= '0';

                }
        }}

void grille :: initialiser (){

           int h=1;
            for (int i=0; i<n; i++) //on initialise les valeurs de la matrice à 0
        {
            for (int j=0; j<h; j++)
                {
                    (matrice_[ i][ j])= '0'; // initialiser la matrice a 0
                    (matrice[ i][ j])= '0';

                }
                if (i<n/2){h+=2;}
                else h-=2;

        }

    }
  void grille :: afficher(){

     int k =3;
     int s=1 ;
     int h=0;
    for (int i=1 ; i<n/2 *4 +3; i++)
        {
            for (int j=n/2 *4 +3  ; j>i+1; j--)
            cout << " ";
            if (k==0)
            {
                if (h<9 )
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                    cout << h+1 << "   ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
                else
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                    cout << h+1 << "  ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
            }
            else
            {
                cout << "    ";
            }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout << "/" ;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

    if(k==2 )
        {
            for (int j=0 ; j<s-1; j++)
            {
                    if(j==0 )
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                        cout << "-----" ;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    }
                    else if (j==s-2)
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                        cout << "--";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    }
                    else
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                        cout << "|---" ;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    }
            }
        }


    else if (k==0)
    {
        for (int j=0 ; j<s; j++)
        {
                    if(j==0 )
                    {

                        if (matrice[h][j]=='*')
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                            cout << " "<<matrice_[ h][ j]<<" ";
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        }
                        else
                            cout << " "<<matrice_[ h][ j]<<" ";

                    }
                    else if(j==s-1)
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                        cout << "| " ;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        if (matrice[h][j]=='*')
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                            cout<<matrice_[ h][ j] <<" ";
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        }
                        else
                            cout<<matrice_[ h][ j] <<" ";
                    }
                    else
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                        cout << "| " ;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                         if (matrice[h][j]=='*')
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                            cout<<matrice_[ h][ j] <<" ";
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        }
                        else
                            cout<< matrice_[h][ j]<<" ";
                    }
        }
        s+=2;
        h++;
            }
    else {
            if (i==1) {cout << " ";}
            else{
                for (int j=0 ; j<s-2; j++){
                    if(j==0 && k==3 )
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                            cout << "  |   |";
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        }
                    if(j==0 && k==1 )
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                            cout << "    |";
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        }
                    else if (j==s-3 && k==1){cout << "    ";}
                    else if (j==s-3 && k==3){cout << "  ";}
                    else
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                            cout << "   |";
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        }
                            }
             }

        }
             if (k<3){k++;}
             else k-=3;
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
         cout << "\\" <<endl;
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

}
s-=2;

    for (int i=0 ; i<n/2 *4 +2; i++){

         for (int j=0 ; j<i; j++)
            cout << " ";
        if (k==0){
            if (h<9 )
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                    cout << h+1 << "   ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
            else {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                    cout << h+1 << "  ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
                }
        else cout << "    ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout   << "\\" ;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        if(k==2 ){

            if (i==n/2 *4 +1) {cout << " ";}
            else
                for (int j=0 ; j<s; j++){
                    if(j==0 )
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                            cout << "--|" ;
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        }
                    else if (j==s-1)
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                            cout << "--";
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        }
                    else
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                            cout << "---|" ;
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        } }}

            else if (k==0){
                s-=2;
                for (int j=0 ; j<s; j++){

                    if(j==0 )
                        {
                             if (matrice[h][j]=='*')
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                            cout << "  "<<matrice_[ h][ j]<<" ";
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        }
                            else
                                cout << "  "<<matrice_[ h][ j]<<" ";
                        }
                    else if(j==s-1)
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                            cout << "| ";
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                             if (matrice[h][j]=='*')
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                            cout<<matrice_[ h][ j]<<"  ";
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        }
                            else
                                cout<<matrice_[ h][ j]<<"  ";
                        }
                    else
                    {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                            cout << "| ";
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                              if (matrice[h][j]=='*')
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                            cout<<matrice_[ h][ j]<<" ";
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        }
                            else
                                cout<<matrice_[ h][ j]<<" ";

                    }}
                if (i==n/2 *4 -1 ) {cout << " ";}
                h++;
                }
            else {
                if (i==1) {cout << " ";}
                else{
                    if (i==n/2 *4 ) {cout << "   ";}
                    else
                        for (int j=0 ; j<s; j++){
                            if(j==0 && k==3 )
                                {
                                     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                                    cout << " |";
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                                }
                            if(j==0 && k==1 )
                                {
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                                    cout << "   |";
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                                }
                    //else if (j==s-2 ){cout << "   ";}
                            else if (j==s-1 && k==1)
                                {
                                    cout << "   ";
                                }
                            else if (j==s-1 && k==3){cout << "";}
                            else if (j==s-2 && k==3){cout << " ";}
                            else
                                {
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                                    cout << "   |";
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                                }
                            }
                    }

                }

             if (k<3){k++;}
             else k-=3;
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
         cout << "/" <<endl;
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
    }
    // verifier si le mot est inserable verticallement dans la position (i,j)
bool grille :: verifyVertical(int i,int j, int h,string ch){


     int t = ch.length();
     // le longuuer de mot dépasse la grille
     if(i + t > h){
        return false;
    }
    //si le mot est insérer avant et aprés le milieu de la grille
    if ((i+t)>(n/2))
       {
           int k =j ;
           //on augmente i et j jusqu'a le milieu
         for ( int e = i; e <=n/2 ;k++,e++)
            {
                if ( matrice_[e][k] != '0' && (matrice_[e][k]!=ch[e-i]) )
                {
                    return false;

                }
            }
            k-=2;

            //on augmente i et récule j a partir de la mlieu de la grille
         for ( int e =n/2 +1; e<i+t; e++, k--)
               {

                  if ( matrice_[e][k] != '0' && (matrice_[e][k]!=ch[e-i]) )
                {
                    return false;

                }

               }
        }
    //si la mot est inserer avant le milieu de la grille on augmente i et j uniquement au cours de la vérification
    else
    {

           for (int e = i, k=j; e <(i+t);k++ ,e++)
            {
                if ( matrice_[e][k] != '0' && (matrice_[e][k]!=ch[e-i]) )
                {
                    return false;
                }

            }
    }
    return true;


}
bool grille :: verifyHorizontal(int i,int j,int h,string ch){

    int t = ch.length();
    // le longuuer de mot dépasse la grille
    if(j + t > h){
        return false;
    }
            // la vérification se fait avec un seul incrimentation de j
         for ( int e = j; e<j+t;e++)
            {
                if ( matrice_[i][e] != '0' && (matrice_[i][e]!=ch[e-j]) )
                {
                    return false;

                }
            }


        return true;
}
bool grille :: verifyDiagonal(int i,int j, int h1,int h2,string ch){

    int t = ch.length();
    // le longuuer de mot dépasse la grille
     if(i + t  > n ){

        return false;
    }
    int h=h2;
    int k;
    //si le mot ne dépasse pas le milieu de la grille
    if ((i+t-1)<=(n/2)){

        k=j;
       // la vérification se fait en incrimentant le i par 1 et le j par 2
    for (int e =i;e<i+t;e++)
            {


                if( matrice_[e][k] != '0' && (matrice_[e][k]!=ch[e-i]) )
                {
                    return false;

                }
                k+=2;
            }
    }
    //si le mot  dépasse le milieu de la grille
    else{
            k=j;
             // la vérification jusqu'a milieu se fait en incrimentant le i par 1 et le j par 2
        for (int e=i;e<=n/2;e++)
            {


                if( matrice_[e][k] != '0' && (matrice_[e][k]!=ch[e-i]) )
                {
                    return false;

                }
                k+=2;
            }
            int e;
           if (i<=n/2){k-=2;  e =n/2 +1 ;}
           else { e =i ;}
            int h = n -2;
             // la vérification a partir du milieu se fait en incrimentant le i uniquement
          for(e;e<t+i;e++)
        {
            // si on sort du grille avec le k
            if(k >= h){

                    return false;
                }
            if( matrice_[e][k] != '0' && (matrice_[e][k]!=ch[e-i]) )
                {
                    return false;

                }
                h-=2;
        }
    }
    return true;
}
//insertion se fait avec le meme principe de la vérification
void grille :: insererVertical(point *p , string ch){
                    int t = p->x+ch.length();
                    if (t>(n/2))
                    {
                       int k = p->y ;
                        for ( int i = p->x; i <=n/2 ;k++,i++)
                        {
                            matrice_[i][k]=ch[i-p->x];


                        }
                        k-=2;
                        for ( int i =n/2 +1 ; i<t; i++, k--)
                           {
                              matrice_[i][k]=ch[i-p->x];

                           }
                    }

                    else
                    {
                        int k=p->y;
                       for (int i = p->x ; i <t;k++ ,i++)
                        {
                            matrice_[i][k]=ch[i-p->x];

                        }
                    }

}
void grille :: inseretHorizontal(point *p , string ch) {

    for (int j=p->y ; j<p->y+ch.length(); j++){
                        matrice_[p->x][j]=ch[j-p->y];
                    }
}
void grille :: insererDiagonal(point *p , string ch){
    if (p->x+ch.length()<=n/2){
                    for (int i=p->x , j=p->y ; i<p->x+ch.length(); i++ , j+=2){
                        matrice_[i][j]=ch[i-p->x];
                    }
                    }
                    else {
                            int j = p->y;
                        for (int i=p->x ; i<=n/2; i++ ){
                        matrice_[i][j]=ch[i-p->x];
                        j+=2;
                        }
                        int i;
                        if (p->x<=n/2){j-=2; i =n/2 +1 ;}
                        else { i = p->x ;}
                        for ( i ; i<p->x+ch.length(); i++ ){
                            matrice_[i][j]=ch[i-p->x];
                        }

                    }

}
bool grille :: insererMot (string ch){
    vector <point *> v1;
    vector <point *> v2;
    vector <point*> v3;
    int colonne =1; //nombrede colonne pour chaque ligne
    //consulter tous les cases de la matrice et vérifier si le mot est inserrable verticallement horizentallement  et diagonallement a partir de ces cases
    for (int i = 0; i < n; i++) {

            if (i<=n/2 && i>0) {colonne+=2;}
            else if (i>n/2) colonne-=2;
             int ligne  = n - colonne/2 *2 ; // nombre de ligne pour chaque colonne
        for (int j = 0; j < colonne; j++){

                if (j<=colonne/2&& j > 0){ligne+=2;}
                else if (j>colonne/2) ligne-=2;
                //si le mot est inserable verticallement dans la position (i,j) on l'ajoute au vecteur v1
                if(verifyVertical(i,j,ligne,ch)) {v1.push_back(new point(i,j)); }
                //si le mot est inserable horizentallement dans la position (i,j) on l'ajoute au vecteur v2
                if(verifyHorizontal(i,j,colonne,ch)) {v2.push_back(new point(i,j)); }
                //si le mot est inserable diagonallement dans la position (i,j) on l'ajoute au vecteur v3
                if(verifyDiagonal(i,j,ligne,colonne,ch)) {v3.push_back(new point(i,j)); }


        }

    }


    if (v1.size()==0 && v2.size()==0 && v3.size()==0){
        return false;
    }
    else {
        while (1){
            int x = rand()%3; //choisir aléatoirement la position d'insertion

            if (x==0 && v1.size()!=0 ) {
                    int y=rand()% v1.size();//choisir aléatoirement la position a partir des positions disponible dans le vecteur
                    point* p = v1[y];
                    insererVertical(p,ch);
                    return true;
        }
            if (x==1 && v2.size()!=0 ) {
                    int y=rand()% v2.size();//choisir aléatoirement la position a partir des positions disponible dans le vecteur
                    point* p = v2[y];
                   inseretHorizontal(p,ch);
                    return true;
            }
            if (x==2 && v3.size()!=0 ) {
                    int y=rand()% v3.size();//choisir aléatoirement la position a partir des positions disponible dans le vecteur

                    point* p = v3[y];
                    insererDiagonal(p,ch);
                    return true;
            }
    }
    }
}
     void grille :: remplir_grille(string * v , int nb)
  {
      bool exit = true;
      while (exit){
            initialiser();
          int i =0 ;
          while (i<nb && insererMot(v[i])) {
                i++;

          }
          if (i==nb) exit = false ; // si on a bien inserer les mots on sort du boucle


      }


  // remplir les cases restantes avec des lettre aléatoires

      string ch = "abcdefghijklmnopqrstuvwxyz";
        int colonne=1;
        for (int i = 0; i < n; i++) {
                if (i<=n/2 && i>0) {colonne+=2;}
                else if (i>n/2) colonne-=2;
                for (int j = 0; j < colonne; j++){
                    if (matrice_[i][j]=='0')
                    {
                        int b = rand()% (ch.length());
                        matrice_[i][j] = ch[b];
                    }
                }
             }
  }

/**************************************************************/
bool  grille :: verifyHorizontal_2(int i,int j, string ch){
    int t=ch.length();
    if(j + t > n){
       return false;
     }
     for (int e = j; e < j+t; e++){
        if ((matrice_[i][e] != '0') && (matrice_[i][e]!=ch[e-j])  ) {
            return false;
        }
     }
}
bool  grille :: verifyVertical_2(int i,int j,string ch){

    int t = ch.length();
     if(i + t > n){
        return false;
    }
    for (int e = i; e < i+t; e++){
         if ( matrice_[e][j] != '0' && (matrice_[e][j]!=ch[e-i]) ) {
            return false;
        }
    }
}
bool  grille :: verifyDiagonal_2(int i,int j, string ch){
     int t = ch.length();
     if(i + t > n || j + t > n)
     {
        return false;
     }
     int y = j -1;
     for (int e = i ; e < i+t ; e++ )
     {
        y++;
        if ( matrice_[e][y] != '0' && (matrice_[e][y]!=ch[e-i]) )
        {
            return false;

        }
     }
}

bool  grille :: insererMot_2(string ch){
    vector <point *> v1;
    vector <point *> v2;
    vector <point*> v3;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
                if(verifyVertical_2(i,j,ch)) v1.push_back(new point(i,j));
                if(verifyHorizontal_2(i,j,ch)) v2.push_back(new point(i,j));
                if(verifyDiagonal_2(i,j,ch)) v3.push_back(new point(i,j));


        }
    }
    if (v1.size()==0 && v2.size()==0 && v3.size()==0){
        return false;
    }
    else {
        while (1){
            int x = rand()%3;
            if (x==0 && v1.size()!=0 ) {
                    int y=rand()% v1.size();
                    point* p = v1[y];
                    for (int i=p->x ; i<p->x+ch.length(); i++){
                        matrice_[i][p->y]=ch[i-p->x];
                    }
                    return true;
            }
            if (x==1 && v2.size()!=0 ) {
                    int y=rand()% v2.size();
                    point* p = v2[y];
                    for (int j=p->y ; j<p->y+ch.length(); j++){
                        matrice_[p->x][j]=ch[j-p->y];
                    }
                    return true;
            }
            if (x==2 && v3.size()!=0 )
                {
                    int y=rand()% v3.size();
                    point* p = v3[y];
                    for (int i=p->x , j=p->y ; i<p->x+ch.length(); i++ , j++){
                        matrice_[i][j]=ch[i-p->x];
                    }
                    return true;
                }
    }
    }
}






  void  grille :: remplir_grille_2(string * v , int nb)
  {
      bool exit = true;
      while (exit){
          int i =0 ;
          initialiser_2();
          while (i<nb && insererMot_2(v[i])) {
                i++;
          }
          if (i==nb) exit = false ;
      }
      string ch = "abcdefghijklmnopqrstuvwxyz";
        for(int i = 0 ; i< n ; i++)
            {
                for(int j = 0 ; j< m ; j++)
                {
                    // on remplit aléatoirement les cases non utilisées
                    if (matrice_[i][j]=='0')
                {
                    int b = rand()% (ch.length());
                    matrice_[i][j] = ch[b];
                }
                }

            }
  }








 void grille :: afficher_2()
 {        cout <<"   ";
        for(int i = 0 ; i< m ; i++)
        {
            if(i<10)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                cout << "   "<<i+1 << "  " ;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                cout << "  " << i+1 << "  ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            }

        }
        cout << endl;
        cout <<"   ";
        for(int i = 0 ; i< m ; i++)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout << "______";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        }
        cout << endl ;
        for(int i = 0 ; i< n ; i++)
            {
                if (i<9)
                   {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                    cout<<i+1 ;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout<<"  | " ;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                   }
                else

                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                        cout<<i+1 ;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                        cout<<" | " ;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    }
                for(int j = 0 ; j< m ; j++)
                    {

                        if ((matrice[i][j])=='*') {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                        cout<< " " << (matrice_[i][j]) << " " ;}
                        else {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        cout<< " " << (matrice_[i][j]) << " " ; }
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                        cout << " | " ;
                    }

                cout << endl ;
                if (i<n-1)
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                        cout << "   |-----";
                        for(int k = 1 ; k< m ; k++){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); cout << "|-----";}
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                        cout<< "|" << endl;
                    }
                else
                    {

                        cout<<"   ";
                        for(int k = 0 ; k< m ; k++){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); cout << "|_____";}
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                        cout<< "|" << endl;
                    }

        }
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
 }





