#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <bool.h>

typedef struct{
    char perso; //perso choisi
    int relique; //val pour indiquer si il a ou non la relique 0 = non obtenu
    char arme; //arme equipe pour ce tour
    int indice_x; 
    int indice_y;
}Joueurs;

typedef struct{
    bool cache; // (1)== cache , (0)== visible
    char monstre; // 0 pas de monstre , 1,2,3,4 monstre associé
    char relique; // 0 pas relique , 1,2,3,4 relique associé
    char portail; // 1 = portail , 0= pas de portail
    char totem; // 0 pas de totem , 1 = totem n'1 , 2 = totem n'2
    bool tresor; // (0) pas de tresor , (1) tresor present.
}Case;
