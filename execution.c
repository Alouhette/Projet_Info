#include "donnee.h"
#include "verification.h"
#include "display.h"
#include "fonction.h"

int game(int nb_j,Player *tab_j,Space **board){
  int winner=0;
  while(winner == 0){
    for(int i=0;i<nb_j;i++){
      show_board(board);
      int alive = 1;
      int blocked = 0;
      printf("au tour de %s\n",tab_j[i].name);
      double time_spent = 0.0; // pour stocker le temps d'exécution du code
      clock_t begin = clock();
      while((alive==1 && blocked == 0)&&(winner == 0)){
        tab_score(tab_j,nb_j);
        } 
        int destination;
        tab_j[i].weapon = weapon_choice(tab_j[i]);  //choix de l'arme
        destination = movement();   //fct de mouvement du joueur
        int xt,yt;
        if(destination==2){
          xt=tab_j[i].indice_x-1;
          yt = tab_j[i].indice_y;
        }type_int()
        if(destination==4){
          yt=tab_j[i].indice_y-1;
          xt = tab_j[i].indice_x;
        }
        if(destination==6){
          yt=tab_j[i].indice_y+1;
          xt = tab_j[i].indice_x;
        }
        if(destination==8){
          xt=tab_j[i].indice_x+1;
          yt = tab_j[i].indice_y;
        }
        if(xt==0 || yt == 0 || xt==6 || yt==6){
            en_vie = 0;
        }
        show_board(board);
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
      tab_j[i].relic = 0;
      tab_j[i].treasure =0;
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
  show_board(board);
  return tab_j[winner-1].name;
}

int play_game(){
  int player;
  int character_tab[4]={1};
  printf("┬ ┬┌─┐┬ ┬  ┌┬┐┌─┐┌┐┌┬ ┬  ┌─┐┬  ┌─┐┬ ┬┌─┐┬─┐  ┌─┐\n");
  printf("├─┤│ ││││  │││├─┤│││└┬┘  ├─┘│  ├─┤└┬┘├┤ ├┬┘   ┌┘\n");
  printf("┴ ┴└─┘└┴┘  ┴ ┴┴ ┴┘└┘ ┴   ┴  ┴─┘┴ ┴ ┴ └─┘┴└─   o \n");
  player = type_int();
  while(player < 1 || player > 4){
    printf("ERREUR : nombre de joueurs compris entre 2 et 4, veuillez resaisir\n");
    player = type_int();
  }
  Player *tab;
  tab = malloc(player*sizeof(Player));
  for(int i=0;i<player;i++){
      tab[i] = create_player(character_tab);
  }
  Space board[7][7];
  create_board(board);
  char winner[100] =game(player,tab[i]);
  //ajouter 1 au nbr victoires de winner
  printf("voulez vous rejouer ? (1=oui , 0=non) \n");
  int choice;
  choice = type_int();
   while(choice < 0 || choice > 1){
    printf("Saisie incorrecte, réessayez.\n");
    choice = type_int();
  }
  
  if(choice){
    play_game();
  }
  else{
    printf("merci d'avoir joué");
  }
}

int main(){
  title();
  int choice;
  choice = type_int();
  while(choice<1 || choice>2){
    printf("valeur rentré incorrecte veuillez resaisir");
    choice = type_int();
  }
  if(choice == 1){
    //musique
    //to do : musique victoire évent secret : https://www.youtube.com/watch?v=Tt7bzxurJ1I
    play_game();
  }
  else if(choice == 2){
    printf("you decided to leave");
  }
  return 0;
}
