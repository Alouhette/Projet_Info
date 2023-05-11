#include <stdio.h>
#include <bool.h>

typedef struct{
    char perso; //perso choisi
    int relique; //val pour indiquer si il a ou non la relique 0 = non obtenu
    char arme; //arme equipe pour ce tour
    int indice_x; 
    int indice_y;
}Joueurs;

typedef struct{
    int mage;
    int guerrier; 
    int ranger;
    int voleur;
}Personnage_dispo;

typedef struct{
    bool cache; // (1)== cache , (0)== visible
    char monstre; // 0 pas de monstre , 1,2,3,4 monstre associé
    char relique; // 0 pas relique , 1,2,3,4 relique associé
    bool tresor; // (0) pas de tresor , (1) tresor present.
}Case;
