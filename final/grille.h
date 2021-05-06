#ifndef GRILLE_H
#define GRILLE_H
#include<string>
#include "point.h"

using namespace std;
class grille {
public:
     int n;
     int m;
     char** matrice_;
     char** matrice;
     grille(int difficulte,int form);

      void initialiser ();
      void  afficher();
      bool  verifyVertical(int i,int j, int h,string ch);
      bool  verifyHorizontal(int i,int j,int h,string ch);
      bool verifyDiagonal(int i,int j, int h1,int h2,string ch);
      void insererVertical(point *p , string ch);
      void inseretHorizontal(point *p , string ch);
      void insererDiagonal(point *p , string ch);
      bool insererMot (string ch);
      void  remplir_grille(string * v , int nb);

/****************************/
       void initialiser_2();
       bool verifyHorizontal_2(int i,int j, string ch);
       bool verifyVertical_2(int i,int j,string ch);
       bool verifyDiagonal_2(int i,int j, string ch);
       bool insererMot_2(string ch);
       void remplir_grille_2(string * v , int nb );
       void afficher_2();


};

#endif // GRILLE_H
