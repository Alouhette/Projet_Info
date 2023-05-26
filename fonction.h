
int forbidden_space(Space **board, int x, int y ){ 
    if(board[x][y].treasure !=0 &&  board[x][y].monster!=0 && board[x][y].relic!=0){
        return 0;   
    };
    return 1;   
}

void create_board(Space **board{
    int i=0,j=0;
    for(i;i<6;i++){
        for(j;j<6;j++){
            //creer les elem case (caché et sans monstre tresor et arme)
            Space tile;
            tile.hidden = 1;
            tile.monster = 0;
            tile.relic = 0;
            tile.treasure = 0;
            board[7][7] = tile;            
        }
    }
   int x, y;    
   x=1 + rand()%6;
   y=1 + rand()%6;
   while(forbidden_space(board,x,y)){ 
        x=1 + rand()%5;
        y=1 + rand()%5;
   }
   board[x][y].treasure=1;
   for (i=1; i<5;i++){
        for(j=1 ; j<5 ; j++){
            while(forbidden_space(board,x,y)){ 
                x=1 + rand()%5;
                y=1 + rand()%5;
            }
            board[x][y].monster=i;
        }
   }
   x=1 + rand()%6;
   y=1 + rand()%6;
   for(i=1 ; i<5 ; j++){
       x=1 + rand()%6;
       y=1 + rand()%6;
       while(forbidden_space(board,x,y)){ 
             x=1 + rand()%5;
             y=1 + rand()%5;
       }
       board[x][y].relic=1;
   }
   x=1 + rand()%6;
   y=1 + rand()%6;
   while(forbidden_space(board,x,y)){ 
        x=1 + rand()%5;
        y=1 + rand()%5;
   }
   board[x][y].portal=1;
   x=1 + rand()%6;
   y=1 + rand()%6;
   for(i=1 ; i<3 ; j++){
       x=1 + rand()%6;
       y=1 + rand()%6;
       while(forbidden_space(board,x,y)){ 
             x=1 + rand()%5;
             y=1 + rand()%5;
       }
       board[x][y].totem=1;
   }
}

//char character_available[4] //indice 0 = mage, 1 = guerrier, 2 = ranger, 3 = voleur
Player create_player(char *character_available){
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
                return create_player(character_available);
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
                return create_player(character_available);
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
                return create_player(character_available);
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
                return create_player(character_available);
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
            return create_player(character_available);
    }
}


int weapon_choice(){
   int weapon;
   printf("veuillez choisir une arme (numéro):\n");
   printf("1 - La Torche\n");
   printf("2 - Le miroir\n");
   printf("3 - La Hache\n");
   printf("4 - L'Arc\n");
   scanf("%d",&weapon);
   if((weapon > 0) && (weapon <5)){
       return weapon;
   }
   else{
       printf("Erreur lors de la séléction d'arme !");
       weapon = weapon_choice();
       return weapon;
   }
}


int movement(){
    printf("Maintenant veuillez choisir une destination : \n");
    printf("            Haut           \n");
    printf("            [8]            \n");
    printf(" Gauche [4]     [6] Droite \n");
    printf("            [2]            \n");
    printf("            Bas            \n");
    int destination;
    destination = type_dest();
    return destination;
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


void get_relic(Player user, Case on_case){
    switch(on_case.relic){
        case 1 :
            if (user.character == 'm'){
                user.relic = 1;
            }
            break;
        case 2 :
            if (user.character == 'g'){
                user.relic = 1;
            }
            break;
        case 3 :
            if (user.character == 'r'){
                user.relic = 1;
            }
            break;
        case 4 :
            if (user.character == 'v'){
                user.relic = 1;
            }
            break;
    } 
}


int space_effect(Space x, Player user, Space game_board[TAILLE]){ //retourne 0 si mort, 1 si en vie
    if (x.monster != 0){
        return fight_monster(user, x);
    }
    else if (x.relic != 0){
        get_relic(user, x);
        return 1;
    }
    else if (x.treasure==1){
        X
    }
    else if(x.totem==1){
        transmutation(user,game_board);
        return 0;
    }
    else if(x.portal==1){
        portal(user);
        return 1;
    }
    else{
        printf("Erreur avec space_effect.\n");
        exit(10);
    }
}


int victory(Player j,int num_j){
    if(j.treasure == 1 && j.relic == 1){
        return num_j+1;
    }
    else{
        return 0;
    }    
}


int other_space(Space board[7][7],int x,int y){
    if((board[x+1][y].hidden == 1) && (board[x-1][y].hidden == 1) && (board[x][y+1].hidden == 1) && (board[x][y-1].hidden == 1)){
        printf("toutes les cases adjacentes sont révélés vous ne pouvez plus vous déplacer, passage au joueur suivant");
        return 1;
    }
    else{
        return 0;
    }
}
