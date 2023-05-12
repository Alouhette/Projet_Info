#include <stdio.h>
#include <bool.h>


int case_interdite(case plateau[7][7], int x, int y ){ 
    if(plateau [x][y].tresor !=0 &&  plateau [x][y].monstre!=0 && plateau [x][y].relique!=0){
        return 0;   
    };
    return 1;   
}

void creer_plateau(case plateau[7][7]){
    int i=0,j=0;
    for(i;i<6;i++){
        for(j;j<6;j++){
            //creer les elem case (caché et sans monstre tresor et arme)
            case tile;
            tile.cache = 1;
            tile.monstre = 0;
            tile.relique = 0;
            tile.tresor = 0;
            plateau[7][7] = tile;            
        }
    }
   int x, y;    
   x=1 + rand()%6;
   y=1 + rand()%6;
   while(case_interdite(plateau[x][y]){ 
        x=1 + rand()%5;
        y=1 + rand()%5;
   }
   plateau[x][y].tresor=1;
   for (i=1; i<5;i++){
        for(j=1 ; j<5,j++){
            while(case_interdite(plateau[x][y]){ 
                x=1 + rand()%5;
                y=1 + rand()%5;
            }
            plateau[x][y].monstre=i;
        }
   }
   x=1 + rand()%6;
   y=1 + rand()%6;
   for(i=1 ; i<5,j++){
       x=1 + rand()%6;
       y=1 + rand()%6;
       while(case_interdite(plateau[x][y]){ 
             x=1 + rand()%5;
             y=1 + rand()%5;
       }
       plateau[x][y].relique=1;
   }
   x=1 + rand()%6;
   y=1 + rand()%6;
   while(case_interdite(plateau[x][y]){ 
        x=1 + rand()%5;
        y=1 + rand()%5;
   }
   plateau[x][y].portail=1
   x=1 + rand()%6;
   y=1 + rand()%6;
   for(i=1 ; i<3,j++){
       x=1 + rand()%6;
       y=1 + rand()%6;
       while(case_interdite(plateau[x][y]){ 
             x=1 + rand()%5;
             y=1 + rand()%5;
       }
       plateau[x][y].totem=1;
   }
}
