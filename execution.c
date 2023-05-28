#include "donnee.h"
#include "verification.h"
#include "display.h"
#include "fonction.h"

//fonction qui fait tourner le jeu
int game(int nb_j,Player *tab_j,Space board[7][7]){
    int winner=0; //variable qui note le numéro du gagnant
    int bx , by; //pos de base des joueurs
    int xt , yt; //pos temporaire des joueurs dans le labyrinthe
    while(winner == 0){
        for(int i=0;i<nb_j;i++){
            tab_score(tab_j,nb_j); //affichage du score de tout les joueurs
            by = tab_j[i].indice_y;  //on sauvegarde les pos de bases des joueurs
            bx = tab_j[i].indice_x;  //on sauvegarde les pos de bases des joueurs
            show_board(board);
            int alive = 1; //variable de si le joueurs est vivant ou non
            int blocked = 0; //variable de si le joueurs est bloqué ou non
            printf("c'est au tour de %s\n",tab_j[i].name);    
            double time_spent = 0.0; // pour stocker le temps d'exécution du code
            clock_t begin = clock(); //clock pour mesurer le temps du tour
            while((alive==1 && blocked == 0)&&(winner == 0)){ //boucle tourne tant que le joueurs est vivant et pas bloqué ou qu'il est pas encore gagné
                //tab_score(tab_j,nb_j); 
                int destination; //variable stockant le retour de la fonction mouvement
                tab_j[i].weapon = weapon_choice(tab_j[i]);  //choix de l'arme
                destination = movement();   //fct de mouvement du joueur
                if(destination==2){ //modification des indices selon le retour de mouvement
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
                user.stats.space_number++; //le joueurs franchis une case en plus donc on ajoute son score
                if(xt<=0 || yt <= 0 || xt>=6 || yt>=6){ //si le déplacement le fait sortir du terrain il meurt direct
                    printf("vous vous perdez dans le dédales du labyrinthes (sortie du terrain)\n");
                    alive = 0;
                }
                else{ //sinon il applique les modification du déplacement et joue la case
                    tab_j[i].indice_x=xt; 
                    tab_j[i].indice_y=yt; 
                    board[tab_j[i].indice_y][tab_j[i].indice_x].hidden=0;
                    show_board(board);
                    alive = space_effect(board[tab_j[i].indice_y][tab_j[i].indice_x], tab_j[i],board);    //effet de la case de destination
                    winner = victory(tab_j[i],i);  
                    blocked = other_space(board,tab_j[i].indice_y,tab_j[i].indice_x);// verif si le joueur peut bouger au prochain tour
                }      
            }
            clock_t end = clock(); // calcule le temps écoulé en trouvant la différence (end - begin) et
                             // divisant la différence par CLOCKS_PER_SEC pour convertir en secondes
            time_spent += (double)(end - begin) / CLOCKS_PER_SEC; 
            printf("vous avez péris dans le labyrinthe, passage au héros suivant\n");
            printf("le temps écoulé pour le tour est de %f secondes\n", time_spent);
            tab_j[i].indice_x=bx; //reinitialisation des pos du joueurs à sa mort
            tab_j[i].indice_y=by;  
            tab_j[i].relic = 0;
            tab_j[i].treasure =0;
            if((alive==0)&&(winner != 0)){ //verification de si le joueurs à reussi à gagner en étant mort
                winner=0;
            }
            printf("le labyrinthe ce referme\n"); 
            for(int j=0;j<6;j++){ //on recache toutes les cases car fin du tour
                for(int h=0;h<6;h++){
                    board[h][j].hidden = 1;
                }
            }
        }
    }
    printf("and the winner is %s" ,tab_j[winner-1].name); // montrer le gagnant
    printf("score final des joueurs");
    tab_score(tab_j,nb_j); 
    for(int j=0;j<6;j++){
        for(int h=0;h<6;h++){
            board[h][j].hidden = 0; //afficher le tableau entier
            }
        }
    printf("révélation du plateau\n");
    show_board(board);
    return winner-1;
}

int play_game(){ //initialise la partie
    int player,winner;
    int character_tab[4]={1,1,1,1}; //tab pour les perso dispo
    player = type_int();
    while(player < 2 || player > 4){ //verification nombre de joueurs correct
        printf("ERREUR : nombre de joueurs compris entre 2 et 4, veuillez resaisir\n");
        player = type_int();
    }
    Player tab[player]; //tab de joueurs
    int i;
    for(i=0;i<player;i++){
        tab[i] = create_player(character_tab); //création des perso
    }
    Space board[7][7];
    create_board(board); //création du terrain
    winner = game(player,tab,board); //modification de winner qui sera renvoyé par game donnant l'indice du joueurs gagnant
    //ajouter 1 au nbr victoires de winner
    printf("voulez vous rejouer ? (1=oui , 0=non) \n"); 
    int choice;
    choice = type_int();
    while(choice < 0 || choice > 1){ //verif que le choix soit 1 ou 0
        printf("Saisie incorrecte, réessayez.\n");
        choice = type_int();
    }  
    if(choice){ //si choix = 1 on rejoue
        play_game();
    }
    else{ //sinon c'est fini
        printf("merci d'avoir joué");
    }
}

int main(){ 
  srand(time(NULL));
  title(); //affichage du titre et menu de départ
  int choice; //choix de si vous voulez jouer ou non
  choice = type_int();
  while(choice<1 || choice>2){ 
    printf("valeur rentré incorrecte veuillez resaisir");
    choice = type_int();
  }
  if(choice == 1){
    printf("┬ ┬┌─┐┬ ┬  ┌┬┐┌─┐┌┐┌┬ ┬  ┌─┐┬  ┌─┐┬ ┬┌─┐┬─┐  ┌─┐\n");
    printf("├─┤│ ││││  │││├─┤│││└┬┘  ├─┘│  ├─┤└┬┘├┤ ├┬┘   ┌┘\n");
    printf("┴ ┴└─┘└┴┘  ┴ ┴┴ ┴┘└┘ ┴   ┴  ┴─┘┴ ┴ ┴ └─┘┴└─   o \n");
    //musique
    //to do : musique victoire évent secret : https://www.youtube.com/watch?v=Tt7bzxurJ1I
    const char* musiqueURL = "https://youtu.be/B7Uy-EWTEIA";  // Lien vers la vidéo de la musique
    const char* browser = "xdg-open";  // Commande pour ouvrir l'URL avec le navigateur par défaut sur Linux
    execlp(browser, browser, musiqueURL, NULL); // Lancement du navigateur avec l'URL de la musique
    play_game(); //lancement de l'initialisateur de partie
  }
  else if(choice == 2){
    printf("you decided to leave");
  }
  return 0;
}
