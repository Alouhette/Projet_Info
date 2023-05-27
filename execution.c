#include "donnee.h"
#include "verification.h"
#include "display.h"
#include "fonction.h"

int game(int nb_j,Player *tab_j,Space board[7][7]){
    int winner=0;
    int bx , by; //pos de base des joueurs
    int xt , yt; //pos temporaire des joueurs dans le labyrinthe
    while(winner == 0){
        for(int i=0;i<nb_j;i++){
            by = tab_j[i].indice_y; 
            bx = tab_j[i].indice_x; 
            show_board(board);
            int alive = 1;
            int blocked = 0;
            printf("c'est au tour de %s\n",tab_j[i].name);    
            double time_spent = 0.0; // pour stocker le temps d'exécution du code
            clock_t begin = clock();
            while((alive==1 && blocked == 0)&&(winner == 0)){
                //tab_score(tab_j,nb_j); 
                int destination;
                tab_j[i].weapon = weapon_choice(tab_j[i]);  //choix de l'arme
                destination = movement();   //fct de mouvement du joueur
                if(destination==2){
                    xt = tab_j[i].indice_x;
                    yt = tab_j[i].indice_y+1;
                }
                if(destination==4){
                    yt = tab_j[i].indice_y;
                    xt = tab_j[i].indice_x-1;
                }
                if(destination==6){
                    yt = tab_j[i].indice_y;
                    xt = tab_j[i].indice_x+1;
                }
                if(destination==8){
                    xt = tab_j[i].indice_x;
                    yt = tab_j[i].indice_y-1;
                };
                if(xt<=0 || yt <= 0 || xt>=6 || yt>=6){
                    printf("vous vous perdez dans le dédales du labyrinthes (sortie du terrain)\n");
                    alive = 0;
                }
                else{
                    tab_j[i].indice_x=xt; 
                    tab_j[i].indice_y=yt; 
                    board[tab_j[i].indice_y][tab_j[i].indice_x].hidden=0;
                    show_board(board);
                    alive = space_effect(board[tab_j[i].indice_y][tab_j[i].indice_x], tab_j[i],board);    //effet de la case de destination
                    winner = victory(tab_j[i],i);  
                    blocked = other_space(board,tab_j[i].indice_y,tab_j[i].indice_x);//verif si le joueur peut bouger 
                }      
            }
            clock_t end = clock(); // calcule le temps écoulé en trouvant la différence (end - begin) et
                             // divisant la différence par CLOCKS_PER_SEC pour convertir en secondes
            time_spent += (double)(end - begin) / CLOCKS_PER_SEC; 
            printf("vous avez péris dans le labyrinthe, passage au héros suivant\n");
            printf("le temps écoulé pour le tour est de %f secondes\n", time_spent);
            tab_j[i].indice_x=bx;
            tab_j[i].indice_y=by;  
            tab_j[i].relic = 0;
            tab_j[i].treasure =0;
            if((alive==0)&&(winner != 0)){ //verification de si le joueurs à reussi à gagner en étant mort
                winner=0;
            }
            printf("le labyrinthe ce referme\n");
            for(int j=0;j<6;j++){ //on recache toutes les cases
                for(int h=0;h<6;h++){
                    board[h][j].hidden = 1;
                }
            }
        }
    }
    printf("and the winner is %s" ,tab_j[winner-1].name); // montrer le gagnant 
    for(int j=0;j<6;j++){
        for(int h=0;h<6;h++){
            board[h][j].hidden = 0; //afficher le tableau entier
            }
        }
    printf("révélation du plateau\n");
    show_board(board);
    return winner-1;
}

int play_game(){
    int player,winner;
    int character_tab[4]={1,1,1,1};
    printf("┬ ┬┌─┐┬ ┬  ┌┬┐┌─┐┌┐┌┬ ┬  ┌─┐┬  ┌─┐┬ ┬┌─┐┬─┐  ┌─┐\n");
    printf("├─┤│ ││││  │││├─┤│││└┬┘  ├─┘│  ├─┤└┬┘├┤ ├┬┘   ┌┘\n");
    printf("┴ ┴└─┘└┴┘  ┴ ┴┴ ┴┘└┘ ┴   ┴  ┴─┘┴ ┴ ┴ └─┘┴└─   o \n");
    player = type_int();
    while(player < 2 || player > 4){
        printf("ERREUR : nombre de joueurs compris entre 2 et 4, veuillez resaisir\n");
        player = type_int();
    }
    Player *tab=NULL;
    tab = malloc(player*sizeof(Player));
    if(tab==NULL){
        printf("erreur malloc");
        exit(10);
    }
    int i;
    for(i=0;i<player;i++){
        tab[i] = create_player(character_tab);
    }
    Space board[7][7];
    create_board(board);
    winner = game(player,tab,board);
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
  srand(time(NULL));
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
