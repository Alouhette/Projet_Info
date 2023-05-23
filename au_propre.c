#include <stdio.h>
#include <bool.h>

typedef struct{
    bool cache; //Si la case est cachée (1) ou non (0)
    char monstre;// Quel monstre. 0 = aucun, 1,2,3,4 = monstre spécifique
    char relique; // Quelle arme. 0 = aucun, 1,2,3,4 = arme spécifique
    bool tresor; // Si la case possède un trésor (1) ou non(0)
    bool portail;
    bool totem_transmu;
}Case;


typedef struct{
    char perso; //perso choisi
    int relique; //1 si relique obtenu, 0 sinon
    char arme; //Arme equipée pour ce tour
    int indice_x; 
    int indice_y;
    char nom[100];
}Joueur;


void affiche_symbole(Case x){
    if (x.monstre != 0){
        //Quel monstre sera affiché
        switch(x.monstre){
            case 1 :
                printf("?");
                break;
            case 2 :
                printf("?");
                break;
            case 3 :
                printf("?");
                break;
            case 4 :
                printf("?");
                break;
        }
    }
    else if (x.relique != 0){
        //Quelle relique sera affichée
        switch(x.relique){
            case 1 :
                printf("?");
                break;
            case 2 :
                printf("?");
                break;
            case 3 :
                printf("?");
                break;
            case 4 :
                printf("?");
                break;
        }
    }
    else if (x.tresor==1){
        //Afficher le trésor
        printf("?")
    }
    else if(x.totem_transmu==1){
        //Afficher le totem
        printf("?");
    }
    else if(x.portail==1){
        //Afficher le portail
        printf("?")
    }
}


void afficher_plateau(Case plateau[7][7]){
    for (int i=0;i<6;i++){
        for (int j=0;j<6;j++){
            if (plateau[i][j].cache == 1){
                printf("?"); //La case est cachée
            }
            else{
                affiche_symbole(plateau[i][j]); //La case n'est pas cachée
            }
        }
        printf("\n");
    }
    printf("\n");
}


void afficher_dispo(Personnage_dispo *perso){
    if((*perso).mage == 1){
        printf("1 - Mage\n");
    }
    if((*perso).guerrier == 1){
        printf("2 - Guerrier\n");
    }
    if((*perso).ranger == 1){
        printf("3 - Ranger\n");
    }
    if ((*perso).voleur == 1){
        printf("4 - Voleur\n");
    }
}

//char personnage_dispo[4] //indice 0 = mage, 1 = guerrier, 2 = ranger, 3 = voleur

Joueur creer_joueurs(personnage_dispo[4]){
    Joueur personne;
    printf("veuillez choisir un nom");
    scanf("%s",personne.nom);
    char choix_perso;
    printf("Veuillez choisir le personnage que vous voulez jouez parmi les suivants :\n");
    afficher_dispo(*perso);

    choix_perso = getchar(); //à refaire avec scanf pour char

    switch(choix_perso){
        case '1':
            if (personnage_dispo[0] == 0){
                printf("Personnage non disponible, veuillez en choisir un autre.\n");
                return creer_joueurs(personnage_dispo[]);
            }
            else{
                personnage_dispo[0] = 0;
                personne.perso = 'm';
                personne.relique = 0;
                personne.arme = '?';
                personne.indice_x = 0;
                personne.indice_y = 2;
                return personne;
            }
            break;
        case '2':
            if (personnage_dispo[1] == 0){
                printf("Personnage non disponible, veuillez en choisir un autre.\n");
                return creer_joueurs(personnage_dispo[]);
            }
            else{
                personnage_dispo[1] = 0;
                personne.perso = 'g';
                personne.relique = 0;
                personne.arme = '?';
                personne.indice_x = 2;
                personne.indice_y = 6;
                return personne;
            }
            break;
        case '3':
            if (personnage_dispo[2] == 0){
                printf("Personnage non disponible, veuillez en choisir un autre.\n");
                return creer_joueurs(personnage_dispo[]);
            }
            else{
                personnage_dispo[2] = 0;
                personne.perso = 'r';
                personne.relique = 0;
                personne.arme = '?';
                personne.indice_x = 4;
                personne.indice_y = 0;
                return personne;
            }
            break;
        case '4':
            if (personnage_dispo[3] == 0){
                printf("Personnage non disponible, veuillez en choisir un autre.\n");
                return creer_joueurs(personnage_dispo[]);
            }
            else{
                personnage_dispo[3] = 0;
                personne.perso = 'v';
                personne.relique = 0;
                personne.arme = '?';
                personne.indice_x = 6;
                personne.indice_y = 4;
                return personne;
            }
            break;
        default :
            printf("Saisie incorrecte, réessayez.\n");
            return creer_joueurs(personnage_dispo[]);
    }
}


int combat_monstre(Joueur persos, Case case_dessus){ //0 = mort, 1 = en vie
    switch(case_dessus.monstre){
        case '1':
            if (persos.arme != 1){
                return 0;
            }
            else{
                return 1;
            }
            break;
        case '2':
            if (persos.arme != 2){
                return 0;
            }
            else{
                return 1;
            }
            break;
        case '3':
            if (persos.arme != 3){
                return 0;
            }
            else{
                return 1;
            }
            break;
        case '4':
            if (persos.arme != 4){
                return 0;
            }
            else{
                return 1;
            }
            break;
        default :
            exit(1);
    }
}

/*typedef struct{
    char perso; //perso choisi
    int relique; //1 si relique obtenu, 0 sinon
    char arme; //Arme equipée pour ce tour
    int indice_x; 
    int indice_y;
    char nom[100];
}Joueur;
typedef struct{
    bool cache; //Si la case est cachée (1) ou non (0)
    char monstre;// Quel monstre. 0 = aucun, 1,2,3,4 = monstre spécifique
    char relique; // Quelle arme. 0 = aucun, 1,2,3,4 = arme spécifique
    bool tresor; // Si la case possède un trésor (1) ou non(0)
    bool portail;
    bool totem_transmu;
}Case;*/

void portail(Joueur persos){
    int x;
    int y;
    
    printf("Sur quelle ligne souhaite-vous vous rendre : ");
    scanf(%d,&x); //verif à faire
    printf("Sur quelle colonne souhaite-vous vous rendre : ");
    scanf(%d,&y); //verif à faire
    
    persos.indice_x = x;
    persos.indice_y = y;
}


//PAS ENCORE TERMINE !!!!!!!!
int transmutation(Joueur persos, Case plateau_de_jeu[TAILLE]){
    //Fini le tour du joueur ! (à mettre juste avant l'appel de cette fonction)
    int x;
    int y;
    Case tmp;
    printf("Vous venez de trouver un totem de transmutation, vous allez échanger celui-ci avec une autre case.\n")
    
    printf("Quelle est la ligne de la case à échanger : ");
    scanf(%d,&x); //verif à faire
    printf("Quelle est la colonne de la case à échanger : ");
    scanf(%d,&y); //verif à faire
    
    //intervertir la case du totem avec la case choisie par l'utilisateur
    plateau_de_jeu[x][y] = plateau_de_jeu[][]
    plateau_de_jeu[][] = plateau_de_jeu[][]
    plateau_de_jeu[][] = plateau_de_jeu[][]
}
