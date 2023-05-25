#include "fonction.h"
#include "donnee.h"
#include <stdio.h>
int forbidden_space(Space board[7][7], int x, int y );
int movement();
int weapon_choice();
int victory(Player j,int num_j);
int other_Space(Space board[7][7],int x,int y);
void create_board(Space board[7][7]);
