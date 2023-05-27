void clear_buffer(){
  while (getchar()!='\n'){
  }
}

int type_int(){
  int n1;
  int verif;
  do{
    verif = scanf("%d",&n1);
    clear_buffer();
  }while(n1>4 || n1<0 || verif!=1); //Pour des saisies entre 0 et 4
return n1;
}

int type_coord(){
  int n1;
  int verif;
  do{
    verif = scanf("%d",&n1);
    printf("verif");
    clear_buffer();
  }while(n1>5 || n1<1 || verif!=1); //Pour des saisies entre 1 et 5
return n1;
}

int type_dest(){
  int n1;
  int verif;
  int verif2=0;
  do{
    verif2 = 0;
    verif = scanf("%d",&n1);
    clear_buffer();
    if (n1==2 || n1==4 || n1==6 || n1==8){
      verif2=1;
    }
  }while(verif2!=1 || verif!=1); //n1 doit être égal à 2,4,6 ou 8
return n1;
}
