#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//define des couleurs pour afficher le tableau
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

//structure pour le scores des joueurs
typedef struct{
    int space_number; //nombre de salle révélé
    int kill_count; //nombre de monstre tué
    int treasure_found; //nbr de trésor trouvé (non relique)
}Score;

//structure des infos relatifs aux joueurs
typedef struct{
    char name[100];
    char character; //perso choisi
    int weapon; //arme equipe pour ce tour
    int relic; //1 si relique obtenu, 0 sinon
    int treasure; // si 1 tresor obtenu , 0 sinon
    int indice_x; //position du perso
    int indice_y; //position du perso
    //Score stats; //score du perso
}Player;

//structure des cases du donjon et les element qui sont contenus
typedef struct{
    int hidden; // (1)== cache , (0)== visible
    int monster; // 0 pas de monstre , 1,2,3,4 pour un monstre spécifique
    int relic; // 0 pas relique , 1,2,3,4 pour une relique spécifique
    int portal; // 1 = portail , 0 = pas de portail
    int totem; // 1 = totem , 0 = pas de totem
    int treasure; // 1 = tresor , 0 = pas de tresor
    int cleared; //1 = case faite, 0 = pas faite
}Space;
