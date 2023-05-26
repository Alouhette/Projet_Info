#include "donnee.h"
#include "verification.h"
#include "dislay.h"
#include "fonction.h"

int game(int nb_j,Player tab_j,Space board[7][7]){
  int winner=0;
  while(winner == 0){
    for(int i=0;i<nb_j;i++){
      double time_spent = 0.0; // pour stocker le temps d'exécution du code
      clock_t begin = clock();
      printf("au tour de %s\n",tab_j[i].name);
      show_board(board);
      int alive = 1;
      int blocked = 0;
      while((alive==1 && blocked = 0)&&(winner == 0)){
        destination = 0;
        tab_j[i].weapon = weapon_choice(tab_j[i]);  //choix de l'arme
        destination = movement();   //fct de mouvement du joueur
        if(destination==2){
          xt=(*x)-1;
          yt = y;
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
            en_vie = 0;
        }
        afficher_plateau(board);
        alive = space_effect();    //effet de la case de destination
        winner = victory(tab_j[i],i);  
        blocked = other_space(board,tab_j[i].indice_x,tab_j[i].indice_y); //verif si le joueur peut bouger        
      }
      clock_t end = clock(); // calcule le temps écoulé en trouvant la différence (end - begin) et
                             // divisant la différence par CLOCKS_PER_SEC pour convertir en secondes
      time_spent += (double)(end - begin) / CLOCKS_PER_SEC; 
      printf("Tle temps écoulé pour le tour est de %f secondes", time_spent);
      if((alive==0)&&(winner =! 0)){ //verification de si le joueurs à reussi à gagner en étant mort
        winner=0;
      }
      for(int j=0;j<6;j++){ //on recache toutes les cases
        for(int h=0;h<6;h++){
          board[j][h].hidden = 1;
      }
    }
  }
  printf("and the winner is %s" ,tab_j[winner-1].name); // montrer le gagnant 
  for(int j=0;j<6;j++){
        for(int h=0;h<6;h++){
          board[j][h].hidden = 0; //afficher le tableau entier
  printf("révélation du plateau\n");
  affiche_plateau(board);
  return tab_j[winner-1].name;
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
  Space board[7][7];
  create_board(board);
  char winner[100] =game(player,tab[i]);
  //ajouter 1 au nbr victoires de winner
  printf("voulez vous rejouer ? (1=oui , 0=non) \n");
  int choice;
  scanf("%d",&choice);
  if(choice){
    play_game();
  }
  else{
    printf("merci d'avoir joué");
  }
}

int main{
  title();
  int choice;
  scanf("%d",&choice);
  //faire la verif scanf
  while(choice<1 && choice>2){
    printf("valeur rentré incorrect veuillez resaisir");
    scanf("%d",&choice);
    //faire la verif scanf
  }
  if(choice == 1){
    //musique
    //to do musique victoire évent secret : https://www.youtube.com/watch?v=Tt7bzxurJ1I
    play_game();
  }
  else if(choice == 2){
    printf("you decided to leave");
  }
  return 0;
}
