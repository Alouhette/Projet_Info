void title(){ //fonction affichant le titre du jeu
  printf("    __  ___         __          _     \n");
  printf("   /  |/  /_ _____ / /____ ____(_)__ _\n");
  printf("  / /__/ / // /_-</ __/ -_) __/ / _ `/\n");
  printf(" /_/  /_/__, /___/___/___/_/ /_/__,_/\n");
  printf("       /___/            \n");
  printf("Press 1 to start in normal mode\n");
  printf("Press 2 to exit\n");
}
/*
void tab_score(Player * tab, int nb_j){ //Fonction visant à afficher le score penant la partie
  printf("joueurs dans la partie:\n");
  for(int i=0;i<nb_j;i++){
      printf("%s : \n",tab[i].name);
      printf("%d cases révélé ,",tab[i].stats.space_number);
      printf("%d monstre_tué ,",tab[i].stats.kill_count);
      printf("%d trésor trouvé ,",tab[i].stats.treasure_found);
  }
}
*/  

void show_symbol(Space x){ //fonction qui vise à afficher les salles spécifique du donjon (quand notamment une case est visible)
  if (x.cleared == 0){
    if (x.monster != 0){
      //Quel monstre sera affiché
      switch(x.monster){
          case 1 :
              printf(ANSI_COLOR_RED " ☣ "ANSI_COLOR_RESET); //zombie
              break;
          case 2 :
              printf(ANSI_COLOR_RED " ♾ "ANSI_COLOR_RESET);//basilic
              break;
          case 3 :
              printf(ANSI_COLOR_RED " ⚉ "ANSI_COLOR_RESET);//troll
              break;
          case 4 :
              printf(ANSI_COLOR_RED " ⚚ "ANSI_COLOR_RESET);//harpie
              break;
       }
    }
    else if (x.relic != 0){
      //Quelle relique sera affichéet
      switch(x.relic){
          case 1 :
              printf(ANSI_COLOR_BLUE    " 🕮 "    ANSI_COLOR_RESET );//grimoire
              break;
          case 2 :
              printf(ANSI_COLOR_YELLOW  " ⚔ "  ANSI_COLOR_RESET );//épée
              break;
          case 3 :
              printf(ANSI_COLOR_GREEN   " ∫ "   ANSI_COLOR_RESET );//baton
              break;
          case 4 :
              printf(ANSI_COLOR_MAGENTA " ↗ " ANSI_COLOR_RESET );//dague
              break;
      }
   }
   else if (x.treasure==1){
       //Afficher le trésor
       printf(ANSI_COLOR_YELLOW  " ⌧ "  ANSI_COLOR_RESET ); 
   }
   else if(x.totem==1){
       //Afficher le totem
       printf(ANSI_COLOR_YELLOW  " ◮ "  ANSI_COLOR_RESET );
   }
   else if(x.portal==1){
       //Afficher le portail
       printf(ANSI_COLOR_CYAN    " ֍ "    ANSI_COLOR_RESET); 
   }
  }
  else{
      printf(" ▢ ");
  }
}

void show_board(Space board[7][7]){ //fonction qui affiche le donjon
    for (int i=0;i<7;i++){
        for (int j=0;j<7;j++){
            if (j==4&&i==0){
               printf(ANSI_COLOR_GREEN   " ▨ "   ANSI_COLOR_RESET);
            }
            else if (j==0&&i==2){
               printf(ANSI_COLOR_BLUE " ▨ " ANSI_COLOR_RESET);
            }
            else if(j==6&&i==4){
               printf(ANSI_COLOR_MAGENTA " ▨ " ANSI_COLOR_RESET);
            }
            else if(j==2&&i==6){
               printf(ANSI_COLOR_YELLOW  " ▨ "  ANSI_COLOR_RESET);
            }
            else{
                if((j<1||j>5)||(i<1||i>5)){
                    printf("   ");
                }
                else{
                    if (board[j][i].hidden == 1){
                        printf(" ▦ "); //La case est cachée
                    }
                    else{
                        show_symbol(board[j][i]);//La case n'est pas cachée
                    }
                }
            }                
        }
        printf("\n");
    }
}

void show_availability(int *character_available){ //sert à montrer quel perso sont disponibles
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
