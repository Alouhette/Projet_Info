#include "fonction.c"

void affiche_titre(){
  printf("    __  ___           __            _      \n");
  printf("   /  |/  /_  _______/ /____  _____(_)___ _\n");
  printf("  / /|_/ / / / / ___/ __/ _ \/ ___/ / __ `/\n");
  printf(" / /  / / /_/ (__  ) /_/  __/ /  / / /_/ / \n");
  printf("/_/  /_/\__, /____/\__/\___/_/  /_/\__,_/  \n");
  printf("       /____/                              \n");
  printf("Press 1 to start in normal mode\n");
  printf("Press 2 to start in troll mode\n");
  printf("Press 3 to exit\n");
}

int lancer_jeu(){
  int j = choix_nbr_j();
  for(int i=0;i<j;i++){
      choix_perso();
  }
  int v = jeu(j);
  return v;
}

int jeu(int nb_j,Joueurs tab_j){
  int vainqueur=0;
  while(vainqueur == 0){
    for(int i=0;i<nb_j;i++){
      int en_vie = 1;
      int bloquer = 0;
      while(en_vie==1 && bloquer = 0){
        destination = 0;
        tab_j[i].arme = choix_arme(tab_j[i]);  //choix de l'arme
        destination = deplacement();   //fct de mouvement du joueur
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
        effet_case();    //effet de la case de destination
        victoire();      //test condition victoire
        case_adjacent(); //verif si le joueur peut bouger        
      }
    
  }
}

int main{
  affiche_titre();
  int choix;
  scanf("%d",&choix);
  //faire la verif scanf
  if(choix == 1){
    //musique
    lancer_jeu();
  }
  else if(choix == 2){
    //musique 2
    lancer_jeu();
  }
  else if(choix == 3){
    //a faire
  }
  else{
    
  }
  return 0;
}
