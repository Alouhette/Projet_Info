void e(int board[7][7],int *x,int *y){
    while(board[*y][*x]!=0){
        if(*x<5){
           *x++;
        }
        else{
            *x=1;
            *y++;
        }
        if(*y>5){
            *y=1;
        }
    }
}    

int main()
{
    srand(time(NULL));
    int tab[7][7];
    int i=0,j=0;
    for(i;i<6;i++){
        for(j;j<6;j++){
            tab[j][i]==0;
        }
    }
    int* x, * y;
    *x=1 + rand()%5;
    *y=1 + rand()%5;
    tab[*y][*x]==1;
    for(i=1;i<4;i++){
        if(tab[*y][*x]!=0){
            e(tab,x,y);
        } 
        tab[*y][*x]==i;
    }
}

//ancien
void create_board(Space board[7][7]){
    int i=0,j=0;
    for(i;i<6;i++){
        for(j;j<6;j++){
            //creer les elem case (caché et sans monstre tresor et arme)
            Space tile;
            tile.hidden = 1;
            tile.monster = 0;
            tile.relic = 0;
            tile.treasure = 0;
            board[j][i] = tile;            
        }
    }
   int x, y;    
   x=1 + rand()%5;
   y=1 + rand()%5;
   while(forbidden_space(board,x,y)){ 
        x=1 + rand()%5;
        y=1 + rand()%5;
   }
   board[y][x].treasure=1;
   for (i=1; i<5;i++){
        for(j=1 ; j<5 ; j++){
            while(forbidden_space(board,x,y)){ 
                x=1 + rand()%5;
                y=1 + rand()%5;
            }
            board[y][x].monster=i;
        }
   }
   x=1 + rand()%5;
   y=1 + rand()%5;
   for(i=1 ; i<5 ; j++){
       x=1 + rand()%5;
       y=1 + rand()%5;
       while(forbidden_space(board,x,y)){ 
             x=1 + rand()%5;
             y=1 + rand()%5;
       }
       board[y][x].relic=i;
   }
   x=1 + rand()%5;
   y=1 + rand()%5;
   while(forbidden_space(board,x,y)){ 
        x=1 + rand()%5;
        y=1 + rand()%5;
   }
   board[y][x].portal=1;
   x=1 + rand()%5;
   y=1 + rand()%5;
   for(i=1 ; i<3 ; j++){
       x=1 + rand()%5;
       y=1 + rand()%5;
       while(forbidden_space(board,x,y)){ 
             x=1 + rand()%5;
             y=1 + rand()%5;
       }
       board[y][x].totem=1;
   }
}
  
