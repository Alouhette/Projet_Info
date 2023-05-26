#include "fonction.h"
#include "donnee.h"
#include "display.h"
#include <stdio.h>
void create_board(Space board[7][7]);
int forbidden_space(Space board[7][7], int x, int y );
Joueur create_player(char character_available[4]);
int weapon_choice();
int movement();
int fight_monster(Player user, Space on_space);
void portal(Player user);
int transmutation(Player user, Space game_board[TAILLE]);
int space_effect(Space x, Player user);
void show_symbol(Space x);
int victory(Player j,int num_j);
int other_Space(Space board[7][7],int x,int y);
void title();
void tab_score(Player tab[], int nb_j);
void show_symbol(Space x);
void show_board(Space board[7][7]);
void show_availability(char character_available[4]);
