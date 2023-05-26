int forbidden_space(Space board[7][7], int x, int y ){ 
    if(board[x][y].treasure !=0 &&  board[x][y].monster!=0 && board[x][y].relic!=0){
        return 1;   
    };
    return 0;   
}
