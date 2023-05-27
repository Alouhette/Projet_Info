#include "donnee.h"
#include "verification.h"
#include "display.h"
#include "fonction.h"
void clear_buffer();
int type_int();
int type_coord();
void title();
void tab_score(Player tab[], int nb_j);
void show_symbol(Space x);
void show_board(Space board[7][7]);
void show_availability(char character_available[4]);
void create_board(Space board[7][7]);
int forbidden_space(Space board[7][7], int x, int y );
Joueur create_player(char character_available[4]);
int weapon_choice();
int movement();
int fight_monster(Player user, Space on_space);
void portal(Player user);
int transmutation(Player user, Space game_board[TAILLE]);
int space_effect(Space x, Player user);
void show_symbol(Space x);
int victory(Player j,int num_j);
int other_Space(Space board[7][7],int x,int y);


void show_symbol(Space x){
  if (x.cleared == 0){
    if (x.monster != 0){
      //Quel monstre sera affiché
      switch(x.monster){
          case 1 :
              printf(" ☣ "); //zombie
              break;
          case 2 :
              printf(" ♾ ");//basilic
              break;
          case 3 :
              printf(" ⚉ ");//troll
              break;
          case 4 :
              printf(" ⚚ ");//harpie
              break;
       }
    }
    else if (x.relic != 0){
      //Quelle relique sera affichéet
      switch(x.relic){
          case 1 :
              printf(" 🕮 ");//grimoire
              break;
          case 2 :
              printf(" ⚔ ");//épée
              break;
          case 3 :
              printf(" ∫ ");//baton
              break;
          case 4 :
              printf(" ↗ ");//dague
              break;
      }
   }
   else if (x.treasure==1){
       //Afficher le trésor
       printf(" ⌧ "); 
   }
   else if(x.totem==1){
       //Afficher le totem
       printf(" ◮ ");
   }
   else if(x.portal==1){
       //Afficher le portail
       printf(" ֍ "); 
   }
  }
  else{
      printf(" ▢ ");
  }
}

void show_board(Space board[7][7]){
    for (int i=0;i<7;i++){
        for (int j=0;j<7;j++){
            if ((j==4&&i==0)||(j==0&&i==2)||(j==6&&i==4)||(j==2&&i==6)){
                printf(" ▨ ");
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

void show_symbol(Space x){
  if (x.cleared == 0){
    if (x.monster != 0){
      //Quel monstre sera affiché
      switch(x.monster){
          case 1 :
              printf(ANSI_COLOR_RED " z "ANSI_COLOR_RESET); //zombie
              break;
          case 2 :
              printf(ANSI_COLOR_RED " b "ANSI_COLOR_RESET);//basilic
              break;
          case 3 :
              printf(ANSI_COLOR_RED " t "ANSI_COLOR_RESET);//troll
              break;
          case 4 :
              printf(ANSI_COLOR_RED " h "ANSI_COLOR_RESET);//harpie
              break;
       }
    }
    else if (x.relic != 0){
      //Quelle relique sera affichéet
      switch(x.relic){
          case 1 :
              printf(ANSI_COLOR_BLUE    " G "    ANSI_COLOR_RESET );//grimoire
              break;
          case 2 :
              printf(ANSI_COLOR_YELLOW  " E "  ANSI_COLOR_RESET );//épée
              break;
          case 3 :
              printf(ANSI_COLOR_GREEN   " B "   ANSI_COLOR_RESET );//baton
              break;
          case 4 :
              printf(ANSI_COLOR_MAGENTA " D " ANSI_COLOR_RESET );//dague
              break;
      }
   }
   else if (x.treasure==1){
       //Afficher le trésor
       printf(ANSI_COLOR_YELLOW  " T "  ANSI_COLOR_RESET ); 
   }
   else if(x.totem==1){
       //Afficher le totem
       printf(ANSI_COLOR_YELLOW  " O "  ANSI_COLOR_RESET );
   }
   else if(x.portal==1){
       //Afficher le portail
       printf(ANSI_COLOR_CYAN    " P "    ANSI_COLOR_RESET); 
   }
  }
  else{
      printf(" V ");
  }
}

void show_board(Space board[7][7]){
    for (int i=0;i<7;i++){
        for (int j=0;j<7;j++){
            if (j==4&&i==0){
               printf(ANSI_COLOR_GREEN   " d "   ANSI_COLOR_RESET);
            }
            else if (j==0&&i==2){
               printf(ANSI_COLOR_BLUE " d " ANSI_COLOR_RESET);
            }
            else if(j==6&&i==4){
               printf(ANSI_COLOR_MAGENTA " d " ANSI_COLOR_RESET);
            }
            else if(j==2&&i==6){
               printf(ANSI_COLOR_YELLOW  " d "  ANSI_COLOR_RESET);
            }
            else{
                if((j<1||j>5)||(i<1||i>5)){
                    printf("   ");
                }
                else{
                    if (board[j][i].hidden == 1){
                        printf(" H "); //La case est cachée
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
