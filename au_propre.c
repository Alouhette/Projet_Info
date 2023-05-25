#include <stdio.h>
#include <bool.h>

typedef struct{
    char name[100];
    char character; //perso choisi
    char weapon; //arme equipe pour ce tour
    int relic; //1 si relique obtenu, 0 sinon
    int indice_x; 
    int indice_y;
}Player;

typedef struct{
    bool hidden; // (1)== cache , (0)== visible
    char monster; // 0 pas de monstre , 1,2,3,4 pour un monstre spécifique
    char relic; // 0 pas relique , 1,2,3,4 pour une relique spécifique
    char portal; // 1 = portail , 0 = pas de portail
    char totem; // 1 = totem , 0 = pas de totem
    bool treasure; // 1 = tresor , 0 = pas de tresor
}Space;


void clear_buffer(){
  while (getchar()!='\n'){
  }
}
int type_int(){
  float n1;
  int verif;
  do{
    //printf("X\n"); //Printf ici inutile, à mettre avant l'appel de la fonction
    verif = scanf("%df",&n1);
    clear_buffer();
  }while(n1>4 || n1<0 || verif!=1); //Pour des saisies entre 0 et 4
return n1;
}
int type_coord(){
  float n1;
  int verif;
  do{
    //printf("X\n"); //Printf ici inutile, à mettre avant l'appel de la fonction
    verif = scanf("%df",&n1);
    clear_buffer();
  }while(n1>5 || n1<1 || verif!=1); //Pour des saisies entre 1 et 5
return n1;
}


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


void afficher_dispo(char personnage_dispo[4]){
    if(personnage_dispo[0] == 1){
        printf("1 - Mage\n");
    }
    if(personnage_dispo[1] == 1){
        printf("2 - Guerrier\n");
    }
    if(personnage_dispo[2] == 1){
        printf("3 - Ranger\n");
    }
    if (personnage_dispo[3] == 1){
        printf("4 - Voleur\n");
    }
}


//char personnage_dispo[4] //indice 0 = mage, 1 = guerrier, 2 = ranger, 3 = voleur
Joueur creer_joueurs(char personnage_dispo[4]){
    int choix_perso;
    Joueur personne;
    printf("veuillez choisir un nom : ");
    scanf("%s",personne.nom);
    printf("Veuillez choisir le personnage que vous voulez jouer parmi les suivants :\n");
    afficher_dispo(personnage_dispo);
    choix_perso = type_int();
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


void portail(Joueur persos){
    int x;
    int y;
    printf("Vous venez de trouver un portail de téléportation ! Veuillez choisir sur quelle case non visité vous rendre.\n");
    
    printf("Sur quelle ligne souhaite-vous vous rendre : ");
    x = type_coord();
    printf("Sur quelle colonne souhaite-vous vous rendre : ");
    y = type_coord();
    
    persos.indice_x = x;
    persos.indice_y = y;
}


int transmutation(Joueur persos, Case plateau_de_jeu[TAILLE]){ 
    //Fini le tour du joueur ! (à mettre juste avant l'appel de cette fonction)
    int x;
    int y;
    Case tmp;
    printf("Vous venez de trouver un totem de transmutation, vous allez échanger celui-ci avec une autre case.\n")
    
    printf("Quelle est la ligne de la case à échanger : ");
    x = type_coord();
    printf("Quelle est la colonne de la case à échanger : ");
    y = type_coord();
    
    //intervertir la case du totem avec la case choisie par l'utilisateur
    tmp = plateau_de_jeu[x][y]
    plateau_de_jeu[x][y] = plateau_de_jeu[persos.indice_x][persos.indice_y]
    plateau_de_jeu[persos.indice_x][persos.indice_y] = tmp
}
