void title(){
  printf("    __  ___         __          _     \n");
  printf("   /  |/  /_ _____ / /____ ____(_)__ _\n");
  printf("  / /__/ / // /_-</ __/ -_) __/ / _ `/\n");
  printf(" /_/  /_/__, /___/___/___/_/ /_/__,_/\n");
  printf("       /___/            n");
  printf("Press 1 to start in normal mode\n");
  printf("Press 2 to exit\n");
}

void tab_score(Player tab[], int nb_j){
  printf("joueurs dans la partie:\n");
  for(int i=0;i<nb_j;i++){
      printf("%s : \n",tab[i].nom);
      printf("%d cases révélé ,",tab[i].score.space_number);
      printf("%d monstre_tué ,",tab[i].score.kill_count);
      printf("%d trésor trouvé ,",tab[i].score.treasure_found);
  }
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
        printf("⌧"); 
    }
    else if(x.totem==1){
        //Afficher le totem
        printf("◮");
    }
    else if(x.portal==1){
        //Afficher le portail
        printf("֍"); 
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
