<?????>

void title(){
  printf("    __  ___           __            _      \n");
  printf("   /  |/  /_  _______/ /____  _____(_)___ _\n");
  printf("  / /|_/ / / / / ___/ __/ _ \/ ___/ / __ `/\n");
  printf(" / /  / / /_/ (__  ) /_/  __/ /  / / /_/ / \n");
  printf("/_/  /_/\__, /____/\__/\___/_/  /_/\__,_/  \n");
  printf("       /____/                              \n");
  printf("Press 1 to start in normal mode\n");
  printf("Press 2 to exit\n");
}



void show_symbol(Space x){
    if (x.monster != 0){
        //Quel monstre sera affiché
        switch(x.monster){
            case 1 :
                printf("☣"); //zombie
                break;
            case 2 :
                printf("♾");//basilic
                break;
            case 3 :
                printf("⚉");//troll
                break;
            case 4 :
                printf("⚚");//harpie
                break;
        }
    }
    else if (x.relic != 0){
        //Quelle relique sera affichée
        switch(x.relic){
            case 1 :
                printf("🕮");//grimoire
                break;
            case 2 :
                printf("⚔");//épée
                break;
            case 3 :
                printf("∫");//baton
                break;
            case 4 :
                printf("↗");//dague
                break;
        }
    }
    else if (x.treasure==1){
        //Afficher le trésor
        printf("⌧")
    }
    else if(x.totem==1){
        //Afficher le totem
        printf("◮");
    }
    else if(x.portal==1){
        //Afficher le portail
        printf("֍")
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
