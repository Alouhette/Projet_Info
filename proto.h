#include "fonction.c"
#include "donnee.h"
#include <stdio.h>
int case_interdite(case plateau[7][7], int x, int y );
int deplacement();
int choix_arme(Joueurs j);
void creer_plateau(case plateau[7][7]);
void affiche_titre();
int lancer_jeu();
int jeu(int nb_j,Joueurs tab_j);
