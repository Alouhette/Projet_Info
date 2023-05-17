/.
int lancer_jeu(){
  int j = choix_nbr_j();
  for(int i=0;i<j;i++){
      choix_perso();
  }
  int v = jeu(j);
  return v;
}

int jeu(int nb_j){
  int vainqueur=0;
  while(vainqueur == 0){
    for(int i=0;i<nb_j;i++){
      int en_vie = 1;
      while(en_vie==1){
        case_adjacent(); /verif si le joueur peut bouger
        choix_arme();    /choix de l'arme
        deplacement();   /fct de mouvement du joueurs
        effet_case();    /effet de la case de destination
        victoire();      /test condition victoire
        
    }
  }
}
./

int main{
  lancer_jeu();
  return 0;
}
