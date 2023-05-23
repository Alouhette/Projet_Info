#include "donnee.h"

int forbidden_space(Space board[7][7], int x, int y ){ 
    if(board[x][y].treasure !=0 &&  board[x][y].monster!=0 && board[x][y].relic!=0){
        return 0;   
    };
    return 1;   
}

int movement(){
    printf("Maintenant veuillez choisir une destination : \n");
    printf("            Haut           \n");
    printf("            [8]            \n");
    printf(" Gauche [4]     [6] Droite \n");
    printf("            [2]            \n");
    printf("            Bas            \n");
    scanf("%d",&destination);
    return destination;
}

int weapon_choice(){
   int weapon;
   printf("veuillez choisir une arme (numéro):\n");
   printf("1 - La Torche\n");
   printf("2 - Le Bouclier\n");
   printf("3 - La Hache\n");
   printf("4 - L'Arc\n");
   scanf(%d,&weapon);
   if((weapon > 0) && (weapon <5)){
       return weapon;
   }
   else{
       printf("Erreur lors de la séléction d'arme !");
       weapon = weapon_choice(j);
       return weapon;
   }
}

int victory(Player j,int num_j){
    if(j.tresor == 1 && j.relique == 1){
        return num_j+1;
    }
    else{
        return 0;
    }
        
}

int other_Space(Space board[7][7],int x,int y){
    if((board[x+1][y].hidden == 1) && (board[x-1][y].hidden == 1) && (board[x][y+1].hidden == 1) && (board[x][y-1].hidden == 1)){
        printf("toutes les cases adjacentes sont révélés vous ne pouvez plus vous déplacer, passage au joueur suivant");
        return 1;
    }
    else{
        return 0;
    }
}

void create_board(Space board[7][7]){
    int i=0,j=0;
    for(i;i<6;i++){
        for(j;j<6;j++){
            //creer les elem case (caché et sans monstre tresor et arme)
            case tile;
            tile.hidden = 1;
            tile.monster = 0;
            tile.relic = 0;
            tile.treasure = 0;
            plateau[7][7] = tile;            
        }
    }
   int x, y;    
   x=1 + rand()%6;
   y=1 + rand()%6;
   while(forbidden_space(board[x][y]){ 
        x=1 + rand()%5;
        y=1 + rand()%5;
   }
   board[x][y].treasure=1;
   for (i=1; i<5;i++){
        for(j=1 ; j<5,j++){
            while(forbidden_space(board[x][y]){ 
                x=1 + rand()%5;
                y=1 + rand()%5;
            }
            board[x][y].monster=i;
        }
   }
   x=1 + rand()%6;
   y=1 + rand()%6;
   for(i=1 ; i<5,j++){
       x=1 + rand()%6;
       y=1 + rand()%6;
       while(forbidden_space(board[x][y]){ 
             x=1 + rand()%5;
             y=1 + rand()%5;
       }
       board[x][y].relic=1;
   }
   x=1 + rand()%6;
   y=1 + rand()%6;
   while(forbidden_space(board[x][y]){ 
        x=1 + rand()%5;
        y=1 + rand()%5;
   }
   board[x][y].portal=1
   x=1 + rand()%6;
   y=1 + rand()%6;
   for(i=1 ; i<3,j++){
       x=1 + rand()%6;
       y=1 + rand()%6;
       while(case_interdite(plateau[x][y]){ 
             x=1 + rand()%5;
             y=1 + rand()%5;
       }
       board[x][y].totem=1;
   }
}
