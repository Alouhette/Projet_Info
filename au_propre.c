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


void show_symbol(Space x){
    if (x.monster != 0){
        //Quel monstre sera affiché
        switch(x.monster){
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
    else if (x.relic != 0){
        //Quelle relique sera affichée
        switch(x.relic){
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
    else if (x.treasure==1){
        //Afficher le trésor
        printf("?")
    }
    else if(x.totem==1){
        //Afficher le totem
        printf("?");
    }
    else if(x.portal==1){
        //Afficher le portail
        printf("?")
    }
}


void show_board(Space board[7][7]){
    for (int i=0;i<6;i++){
        for (int j=0;j<6;j++){
            if (board[i][j].hidden == 1){
                printf("?"); //La case est cachée
            }
            else{
                show_symbol(board[i][j]); //La case n'est pas cachée
            }
        }
        printf("\n");
    }
    printf("\n");
}


void show_availability(char character_available[4]){
    if(character_available[0] == 1){
        printf("1 - Mage\n");
    }
    if(character_available[1] == 1){
        printf("2 - Guerrier\n");
    }
    if(character_available[2] == 1){
        printf("3 - Ranger\n");
    }
    if (character_available[3] == 1){
        printf("4 - Voleur\n");
    }
}


//char character_available[4] //indice 0 = mage, 1 = guerrier, 2 = ranger, 3 = voleur
Joueur create_player(char character_available[4]){
    int character_chosen;
    Player user;
    printf("veuillez choisir un nom : ");
    scanf("%s",user.name);
    printf("Veuillez choisir le personnage que vous voulez jouer parmi les suivants :\n");
    show_availability(character_available);
    character_chosen = type_int();
    switch(character_chosen){
        case '1':
            if (character_available[0] == 0){
                printf("Personnage non disponible, veuillez en choisir un autre.\n");
                return create_player(character_available[]);
            }
            else{
                character_available[0] = 0;
                user.character = 'm';
                user.relic = 0;
                user.weapon = '?';
                user.indice_x = 0;
                user.indice_y = 2;
                return user;
            }
            break;
        case '2':
            if (character_available[1] == 0){
                printf("Personnage non disponible, veuillez en choisir un autre.\n");
                return create_player(character_available[]);
            }
            else{
                character_available[1] = 0;
                user.character = 'g';
                user.relic = 0;
                user.weapon = '?';
                user.indice_x = 2;
                user.indice_y = 6;
                return user;
            }
            break;
        case '3':
            if (character_available[2] == 0){
                printf("Personnage non disponible, veuillez en choisir un autre.\n");
                return create_player(character_available[]);
            }
            else{
                character_available[2] = 0;
                user.character = 'r';
                user.relic = 0;
                user.weapon = '?';
                user.indice_x = 4;
                user.indice_y = 0;
                return user;
            }
            break;
        case '4':
            if (character_available[3] == 0){
                printf("Personnage non disponible, veuillez en choisir un autre.\n");
                return create_player(character_available[]);
            }
            else{
                character_available[3] = 0;
                user.character = 'v';
                user.relic = 0;
                user.weapon = '?';
                user.indice_x = 6;
                user.indice_y = 4;
                return user;
            }
            break;
        default :
            printf("Saisie incorrecte, réessayez.\n");
            return create_player(character_available[]);
    }
}


int fight_monster(Player user, Space on_space){ //0 = mort, 1 = en vie
    switch(on_space.monstre){
        case '1':
            if (user.weapon != 1){
                return 0;
            }
            else{
                return 1;
            }
            break;
        case '2':
            if (user.weapon != 2){
                return 0;
            }
            else{
                return 1;
            }
            break;
        case '3':
            if (user.weapon != 3){
                return 0;
            }
            else{
                return 1;
            }
            break;
        case '4':
            if (user.weapon != 4){
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


void portal(Player user){
    int x;
    int y;
    printf("Vous venez de trouver un portail de téléportation ! Veuillez choisir sur quelle case non visité vous rendre.\n");
    
    printf("Sur quelle ligne souhaite-vous vous rendre : ");
    x = type_coord();
    printf("Sur quelle colonne souhaite-vous vous rendre : ");
    y = type_coord();
    
    user.indice_x = x;
    user.indice_y = y;
}


int transmutation(Player user, Space game_board[TAILLE]){ 
    //Fini le tour du joueur ! (à mettre juste avant l'appel de cette fonction)
    int x;
    int y;
    Space tmp;
    printf("Vous venez de trouver un totem de transmutation, vous allez échanger celui-ci avec une autre case.\n")
    
    printf("Quelle est la ligne de la case à échanger : ");
    x = type_coord();
    printf("Quelle est la colonne de la case à échanger : ");
    y = type_coord();
    
    //intervertir la case du totem avec la case choisie par l'utilisateur
    tmp = game_board[x][y]
    game_board[x][y] = game_board[user.indice_x][user.indice_y]
    game_board[user.indice_x][user.indice_y] = tmp
}
