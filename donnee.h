#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    char name[100];
    char character; //perso choisi
    char weapon; //arme equipe pour ce tour
    int relic; //1 si relique obtenu, 0 sinon
    int indice_x; 
    int indice_y;
    Score stats;
}Player;

typedef struct{
    int hidden; // (1)== cache , (0)== visible
    char monster; // 0 pas de monstre , 1,2,3,4 pour un monstre spécifique
    char relic; // 0 pas relique , 1,2,3,4 pour une relique spécifique
    char portal; // 1 = portail , 0 = pas de portail
    char totem; // 1 = totem , 0 = pas de totem
    int treasure; // 1 = tresor , 0 = pas de tresor
}Space;

typedef struct{
    int space_number;
    int kill_count;
    int treasure_found;
}Score;
