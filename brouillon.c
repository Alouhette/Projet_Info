#include <stdio.h>
typedef struct{
    char perso; //perso choisi
    int relique; //val pour indiquer si il a ou non la relique 0 = non obtenu
    char arme; //arme equipe pour ce tour
    int indice_x; 
    int indice_y;
}joueurs;

typedef struct{
    int mage;
    int guerrier; 
    int ranger;
    int voleur;
}personnage_dispo;

char** vide_terrain(char terrain[7][7]){
    int x=0,y=0;
    for(y=0;y<7;y++){
        for(x=0;x<7;x++){
            if ((x==4&&y==0)||(x==0&&y==2)||(x==6&&y==4)||(x==2&&y==6)){
                terrain[x][y]='D';
            }
            else if((x>0&&y>0)&&(x<6&&y<6)){
                terrain[x][y]='#';
            }
            else{
                terrain[x][y]=' ';
            }
        }
    }
    return (char**) terrain;
}

joueurs creer_joueurs(personnage_dispo * perso){
    joueurs personne;
    char choix_perso;
    printf("Veuillez choisir le personnage que vous voulez jouez parmi les suivants (sans majuscules) :\n");
    if((*perso).mage == 1){
        printf("- Mage\n");
    }
    if((*perso).guerrier == 1){
        printf("- Guerrier\n");
    }
    if((*perso).ranger == 1){
        printf("- Ranger\n");
    }
    if ((*perso).voleur == 1){
        printf("- Voleur\n");
    }
    choix_perso = getchar();
    switch(choix_perso){
    case 'm':
            if ((*perso).mage == 0){
                printf("personnage non disponible, veuillez en choisir un autre\n");
                return creer_joueurs(perso);
            }
            else{
                (*perso).mage=0;
                personne.perso = 'm';
                personne.relique = 0 ;
                personne.arme = '?';
                personne.indice_x = 0;
                personne.indice_y = 2;
                return personne;
            }
        case 'g':
            if ((*perso).guerrier == 0){
                printf("personnage non disponible, veuillez en choisir un autre\n");
                return creer_joueurs(perso);
            }
            else{
                (*perso).guerrier=0;
                personne.perso = 'g';
                personne.relique = 0 ;
                personne.arme = '?';
                personne.indice_x = 2;
                personne.indice_y = 6;
                return personne;
            }
        case 'r':
            if ((*perso).ranger == 0){
                printf("personnage non disponible, veuillez en choisir un autre\n");
                return creer_joueurs(perso);
            }
            else{
                (*perso).ranger=0;
                personne.perso = 'r';
                personne.relique = 0 ;
                personne.arme = '?';
                personne.indice_x = 4 ;
                personne.indice_y = 0 ;
                return personne;
            }
        case 'v':
            if ((*perso).voleur == 0){
                printf("personnage non disponible, veuillez en choisir un autre\n");
                return creer_joueurs(perso);
            }
            else{
                (*perso).voleur=0;
                personne.perso = 'v';
                personne.relique = 0 ;
                personne.arme = '?';
                personne.indice_x = 6 ;
                personne.indice_y = 4 ;
                return personne;
            }
        default :
            printf("nom de personnage incorrect veuillez resaisir merci\n");
            return creer_joueurs(perso);
        }
}

// la fct tour réalise le déroulement du tour d'un joueurs
// creer_joueur va créer les données du joueurs
/*
int lancer_partie(int nb_joueurs){
    char display[7][7], terrain_memoire[7][7]; //display = donjon affiché au joueurs
                                               //terrain_memoire = tout le donjon
    int x,y;
    vide_terrain(display);
    generer_terrain(terrain_memoire[7][7])
    int win=1,i;
    char gagnant;
    for(i=0;i<nb_joueurs;i++){
        //creer_joueurs
    }
    while(win==1){
        for(i=0;i<nb_joueurs;i++){
            //tour();
        }
    }
    printf("%s",gagnant);
}
*/
int main(){
    personnage_dispo liste;
    joueurs a,b,c,d;
    liste.mage = 1;
    liste.guerrier = 1;
    liste.ranger = 1;
    liste.voleur = 1;
    a=creer_joueurs(&liste);
    b=creer_joueurs(&liste);
    c=creer_joueurs(&liste);
    d=creer_joueurs(&liste);
    return 0;
}