<????>

void clear_buffer(){
  while (getchar()!='\n'){
  }
}
int type_int(){
  float n1;
  int verif;
  do{
    //printf("X\n"); //Printf ici inutile, à mettre avant l'appel de la fonction
    verif = scanf("%df",&n1);
    clear_buffer();
  }while(n1>4 || n1<0 || verif!=1); //Pour des saisies entre 0 et 4
return n1;
}
int type_coord(){
  float n1;
  int verif;
  do{
    //printf("X\n"); //Printf ici inutile, à mettre avant l'appel de la fonction
    verif = scanf("%df",&n1);
    clear_buffer();
  }while(n1>5 || n1<1 || verif!=1); //Pour des saisies entre 1 et 5
return n1;
}
