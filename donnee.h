#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <bool.h>

typedef struct{
    char character; //perso choisi
    int relic; //val pour indiquer si il a ou non la relique 0 = non obtenu
    char weapon; //arme equipe pour ce tour
    int indice_x; 
    int indice_y;
}Player;

typedef struct{
    bool hidden; // (1)== cache , (0)== visible
    char monster; // 0 pas de monstre , 1,2,3,4 monstre associé
    char relic; // 0 pas relique , 1,2,3,4 relique associé
    char portal; // 1 = portail , 0= pas de portail
    char totem; // 0 pas de totem , 1 = totem n'1 , 2 = totem n'2
    bool treasure; // (0) pas de tresor , (1) tresor present.
}Space;
