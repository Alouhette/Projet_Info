int forbidden_space(Space board[7][7], int x, int y ){ //fonction qui communique si la case est déja attribué on non
    if(board[y][x].treasure != 0 || board[y][x].monster != 0 || board[y][x].relic != 0 || board[y][x].totem != 0 || board[y][x].portal  != 0){
        return 1;   
    };
    return 0;   
}

void adapt_indice(Space board[7][7], int *x, int *y) { //fonction qui aide à bien attribuer les cases du donjon
    while (forbidden_space(board, *x, *y)) { //si la case est deja remplir par une autre piece on doit modifier x et ou y
        if ((*x) < 5) { //tout d'abord on essaie de décaler à gauche si possible 
            (*x)++;
        } else if ((*x) == 5) { //sinon on remet tout à droite une ligne en dessous
            *x = 1;
            (*y)++;
        }
        if ((*y) > 5) { //si on est trop bas on remonte
            *y = 1;
        }
    }
}

void create_board(Space board[7][7]){ //fonction de création du donjon (aidé par forbidden_space et adapt_indice)
    int i,j;
    for(i=1;i<6;i++){
        for(j=1;j<6;j++){
            //creer les elem case (caché et sans monstre tresor et arme)(les cases de base)
            Space tile;
            tile.hidden = 1;
            tile.monster = 0;
            tile.relic = 0;
            tile.treasure = 0;
            tile.cleared =0;
            board[j][i] = tile;            
        }
    }
    int x, y;    //variable des position aléatoire
    for(i=1 ; i<3 ; i++){ //deux tresor donc boucle
       x=1 + rand()%5; //randomize les position
       y=1 + rand()%5;
       adapt_indice(board,&x,&y);
       board[y][x].treasure=1;
    }
    x=1 + rand()%5;
    y=1 + rand()%5;
    adapt_indice(board,&x,&y); //adaptation des indices pour obtenir une position correcte (qui n'écrase pas une salle déja placé);
    board[y][x].portal=1;  //remplissage de la case 
    //et on répéte le procédé pour chaque case.
    x=1 + rand()%5;
    y=1 + rand()%5;
    for(i=1; i<5;i++){ //boucle pour les différents monstres
        for(j=1 ; j<5 ; j++){ 
            x=1 + rand()%5;
            y=1 + rand()%5;
            adapt_indice(board,&x,&y);
            board[y][x].monster=i; 
        }
    }
    for(j=1 ; j<5 ; j++){ //4 relique donc boucle
        x=1 + rand()%5;
        y=1 + rand()%5;
        adapt_indice(board,&x,&y);
        board[y][x].relic=j; 
    }
    for(i=1 ; i<3 ; i++){ //deux totem donc boucle
       x=1 + rand()%5;
       y=1 + rand()%5;
       adapt_indice(board,&x,&y);
       board[y][x].totem=1;
    }
}
Player create_player(int *character_available){ //création des perso des joueurs
    int character_chosen;
    Player user; //création de la val de retour
    printf("veuillez choisir un nom : ");
    scanf("%s",user.name);
    user.stats.space_number = 0; //mise en plac des scores
    user.stats.kill_count = 0;
    user.stats.treasure_found = 0;
    printf("Veuillez choisir le personnage que vous voulez jouer parmi les suivants :\n");
    show_availability(character_available); //montre les perso dispo
    character_chosen = type_int(); //saisie du perso voulu
    //int character_available[4] //indice 0 = mage, 1 = guerrier, 2 = ranger, 3 = voleur
    switch(character_chosen){
        case 1:
            if (character_available[0] == 0){ //perso deja pris
                printf("Personnage non disponible, veuillez en choisir un autre.\n");
                return create_player(character_available);
            }
            else{ //création du mage
                character_available[0] = 0;
                user.character = 'm';
                user.relic = 0;
                user.weapon = 0;
                user.indice_x = 0;
                user.indice_y = 2;
                return user;
            }
            break;
        case 2:
            if (character_available[1] == 0){ //perso deja pris
                printf("Personnage non disponible, veuillez en choisir un autre.\n");
                return create_player(character_available);
            }
            else{ //création du guerrier
                character_available[1] = 0;
                user.character = 'g';
                user.relic = 0;
                user.weapon = 0;
                user.indice_x = 2;
                user.indice_y = 6;
                return user;
            }
            break;
        case 3:
            if (character_available[2] == 0){ //perso deja pris
                printf("Personnage non disponible, veuillez en choisir un autre.\n");
                return create_player(character_available);
            }
            else{ //création du ranger
                character_available[2] = 0;
                user.character = 'r';
                user.relic = 0;
                user.weapon = 0;
                user.indice_x = 4;
                user.indice_y = 0;
                return user;
            }
            break;
        case 4:
            if (character_available[3] == 0){ //perso deja pris
                printf("Personnage non disponible, veuillez en choisir un autre.\n");
                return create_player(character_available);
            }
            else{ //création du voleur
                character_available[3] = 0;
                user.character = 'v';
                user.relic = 0;
                user.weapon = 0;
                user.indice_x = 6;
                user.indice_y = 4;
                return user;
            }
            break;
        default : //valeur incorrect recréation du perso
            printf("Saisie incorrecte, réessayez.\n");
            return create_player(character_available);
    }
}


int weapon_choice(){ //choix des armes
   int weapon;
   printf("veuillez choisir une arme (numéro):\n");
   printf("1 - La Torche\n");
   printf("2 - Le miroir\n");
   printf("3 - La Hache\n");
   printf("4 - L'Arc\n");
   scanf("%d",&weapon); //la personne vérifie l'arme qu'il veut prendre
   if((weapon > 0) && (weapon <5)){ //verification si l'arme est valide
       return weapon;
   }
   else{ //si arme invalide on relance la fonction
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
    switch(on_space.monster){
        case '1':
            printf("Vous tombez nez à nez avec un zombie...!\n");
            if (user.weapon != 1){
                printf("N'étant pas équipé de la torche vous périssez...\n");
                return 0;
            }
            else{
                printf("Ayant équipé le bon outil, vous terrassez la créature !\n");
                user.stats.kill_count++;
                return 1;
            }
            break;
        case '2':
            printf("Vous tombez nez à nez avec un basilic...!\n");
            if (user.weapon != 2){
                printf("N'étant pas équipé du miroir vous périssez...\n");
                return 0;
            }
            else{
                printf("Ayant équipé le bon outil, vous terrassez la créature !\n");
                user.stats.kill_count++;
                return 1;
            }
            break;
        case '3':
            printf("Vous tombez nez à nez avec un troll...!\n");
            if (user.weapon != 3){
                printf("N'étant pas équipé de la hache vous périssez...\n");
                return 0;
            }
            else{
                printf("Ayant équipé le bon outil, vous terrassez la créature !\n");
                user.stats.kill_count++;
                return 1;
            }
            break;
        case '4':
            printf("Vous tombez nez à nez avec une harpie...!\n");
            if (user.weapon != 4){
                printf("N'étant pas équipé de l'arc vous périssez\n");
                return 0;
            }
            else{
                printf("Ayant équipé le bon outil, vous terrassez la créature !\n");
                user.stats.kill_count++;
                return 1;
            }
            break;
        default :
            exit(1);
    }
}

void portal(Player user,Space board[7][7]){
    int x;
    int y;
    printf("Vous venez de trouver un portail de téléportation ! Veuillez choisir sur quelle case non visité vous rendre.\n");
    
    printf("Sur quelle ligne souhaite-vous vous rendre : ");
    x = type_coord();
    printf("Sur quelle colonne souhaite-vous vous rendre : ");
    y = type_coord();
    board[y][x].hidden =0;
    user.indice_x = x;
    user.indice_y = y;
    show_board(board);
}


void transmutation(Player user, Space game_board[7][7]){ 
    //Fini le tour du joueur ! (à mettre juste avant l'appel de cette fonction)
    int x;
    int y;
    Space tmp;
    printf("Vous venez de trouver un totem de transmutation, vous allez échanger celui-ci avec une autre case.\n");
    
    printf("Quelle est la ligne de la case à échanger : ");
    x = type_coord();
    printf("Quelle est la colonne de la case à échanger : ");
    y = type_coord();
    //intervertir la case du totem avec la case choisie par l'utilisateur
    while(x<=0 || y <= 0 || x>=6 || y>=6){
                    printf("vous ne pouvez pas transmutter des cases inxexistantes\n");
                    printf("Quelle est la ligne de la case à échanger : ");
                    x = type_coord();
                    printf("Quelle est la colonne de la case à échanger : ");
                    y = type_coord();
    }
    tmp = game_board[x][y];
    game_board[x][y] = game_board[user.indice_x][user.indice_y];
    game_board[user.indice_x][user.indice_y] = tmp;
}


void get_relic(Player user, Space on_case){
    switch(on_case.relic){
        case 1 :
            if (user.character == 'm'){
                printf("Vous avez trouvé votre relique ! Vous l'avez donc récupéré pour ce tour.\n");
                user.relic = 1;
            }
            else{
                printf("Vous avez trouvé une relique, mais pas celle que vous recherchez, dommage !\n");
            }
            break;
        case 2 :
            if (user.character == 'g'){
                printf("Vous avez trouvé votre relique ! Vous l'avez donc récupéré pour ce tour.\n");
                user.relic = 1;
            }
            else{
                printf("Vous avez trouvé une relique, mais pas celle que vous recherchez, dommage !\n");
            }
            break;
        case 3 :
            if (user.character == 'r'){
                printf("Vous avez trouvé votre relique ! Vous l'avez donc récupéré pour ce tour.\n");
                user.relic = 1;
            }
            else{
                printf("Vous avez trouvé une relique, mais pas celle que vous recherchez, dommage !\n");
            }
            break;
        case 4 :
            if (user.character == 'v'){
                printf("Vous avez trouvé votre relique ! Vous l'avez donc récupéré pour ce tour.\n");
                user.relic = 1;
            }
            else{
                printf("Vous avez trouvé une relique, mais pas celle que vous recherchez, dommage !\n");
            }
            break;
    } 
}


int space_effect(Space x, Player user, Space game_board[7][7]){ //retourne 0 si mort, 1 si en vie
    if (x.monster != 0){
        return fight_monster(user, x);
    }
    else if (x.relic != 0){
        get_relic(user, x);
        return 1;
    }
    else if (x.treasure==1){
        user.treasure = 1;
        user.stats.treasure_found++;
        return 1;
    }
    else if(x.totem==1){
        transmutation(user,game_board);
        return 0;
    }
    else if(x.portal==1){
        portal(user, game_board);
        if(user.indice_x<=0 || user.indice_y <= 0 || user.indice_x>=6 || user.indice_y>=6){
                    printf("Après téléportation vous vous retrouvez dans les backrooms, (vous etes mort)\n");
                    return 0;
        }
        return space_effect(game_board[user.indice_y][user.indice_x],user,game_board);
    }
    else{
        printf("Erreur avec space_effect.\n");
        exit(10);
    }
}


int victory(Player j,int num_j){
    if((j.treasure == 1) && (j.relic == 1)){
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
