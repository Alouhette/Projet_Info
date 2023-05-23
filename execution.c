#include "fonction.c"

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

int play_game(){
  int player;
  printf("┬ ┬┌─┐┬ ┬  ┌┬┐┌─┐┌┐┌┬ ┬  ┌─┐┬  ┌─┐┬ ┬┌─┐┬─┐  ┌─┐\n");
  printf("├─┤│ ││││  │││├─┤│││└┬┘  ├─┘│  ├─┤└┬┘├┤ ├┬┘   ┌┘\n");
  printf("┴ ┴└─┘└┴┘  ┴ ┴┴ ┴┘└┘ ┴   ┴  ┴─┘┴ ┴ ┴ └─┘┴└─   o \n");
  scanf(%d,&player);
  while(player < 1 && player > 4){
    printf("ERREUR : nombre de joueurs compris entre 2 et 4, veuillez resaisir\n");
    scanf(%d,&player);
  }
  Player *tab;
  tab = malloc(player*sizeof(Player));
  for(int i=0;i<player;i++){
      tab[i] = create_player();
  }
  game(player,tab[i]);
}

int game(int nb_j,Player tab_j,Space board[7][7]){
  int winner=0;
  while(winner == 0){
    for(int i=0;i<nb_j;i++){
      int alive = 1;
      int blocked = 0;
      while((alive==1 && blocked = 0)&&(winner == 0)){
        destination = 0;
        tab_j[i].weapon = weapon_choice(tab_j[i]);  //choix de l'arme
        destination = movement();   //fct de mouvement du joueur
        if(destination==2){
          xt=(*x)-1;
          yt = y:
        }
        if(destination==4){
          yt=(*y)-1;
          xt = x;
        }
        if(destination==6){
          yt=(*y)+1;
          xt = x;
        }
        if(destination==8){
          xt=(*x)+1;
          yt = y;
        }
        if(xt==0 || yt == 0 || xt==6 || yt==6){
            en_vie = 0
        }
        Space_effect();    //effet de la case de destination
        winner = victory(tab_j[i],i);  
        blocked = other_space(board,tab_j[i].indice_x,tab_j[i].indice_y); //verif si le joueur peut bouger        
      }
      if((alive==0)&&(winner =! 0)){
        winner=0;
      }
      for(int j=0;j<6;j++){
        for(int h=0;h<6;h++){
          tab
      }
    }
  }
  printf("and the winner is player %d",victory);
}

int main{
  title();
  int choice;
  scanf("%d",&choice);
  //faire la verif scanf
  while(choice<1 && choice>2){
    printf("valeur rentré incorrect veuillez resaisir");
    //faire la verif scanf
  }
  if(choice == 1){
    //musique
    play_game();
  else if(choice == 2){
    printf("you decided to leave");
  }
  return 0;
}
