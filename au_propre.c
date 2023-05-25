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
