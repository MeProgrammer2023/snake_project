#ifndef LEVEL_H
#define LEVEL_H

const int width = 9;
const int length = 9;

#include <windows.h>
#include <iostream>

#include "snake.h"
#include "player.h"
#include "score.h"


using namespace std;


class Level
{


    private:

        bool gameon = true;
        const int start_pos_i = 4;
        const int start_pos_j = 4;
        int snake_head_pos_i = 4;
        int snake_head_pos_j = 4;
        int player_head_pos_i = 4;
        int player_head_pos_j = 4;

        
        

    public:
        bool snake_phase = true;
        int currentlevel = 1 ;
        int snake_moves = currentlevel + 2;
        int player_moves = currentlevel + 2;
        int max_lvl = 1;
        int temp_i,temp_j;
        char board[width][length];
        char snakelastmove;
        void makelevel(); // with console
        void makesnake(Snake snake); // with console
        void makeplayer(Player plyer,RenderWindow &window,bool running); // with console
        void resetlevel();
        void resetgame();
        void completion();
        char setlastmove(char a);


};


void Level::makelevel(){ //set all arrays to NULL


    for (int i = 0; i < width; i++)
    {
         for (int j = 0; j < length; j++)
         {

            if(i == start_pos_i && j == start_pos_j){
            board[start_pos_i][start_pos_j] = 'O';
            }
            
            else{
             board[i][j] = '\0';
            }

         }
    }


    
}


char Level::setlastmove(char a){

    snakelastmove = a;

}


void Level::makesnake(Snake snake){ //draw snake on console


    
if(snake.dir == 'u'){ 
    if(snake_head_pos_i == 0){ //check if snake hits upper boarder
        snake.random_dir(); //choose a random dir if hits boarder
        makesnake(snake); // draw the new random dir
        system("cls");
        
    }
    else{
    snake_head_pos_i = snake_head_pos_i -1;
    if(board[snake_head_pos_i][snake_head_pos_j] == 'O'){ //if snake body alredy exist
        snake_head_pos_i = snake_head_pos_i +1; //reset location to its last
        snake.random_dir(); // and choose a random dir again
        makesnake(snake);
        return ;
    }
    else {
        setlastmove('u');
    board[snake_head_pos_i][snake_head_pos_j] = 'O';
        temp_i = snake_head_pos_i;
        temp_j = snake_head_pos_j;
        
    }
    }
}
else if(snake.dir == 'd'){ //check if snake hits lower boarder
    if(snake_head_pos_i == 8){
        snake.random_dir();
        makesnake(snake);
        system("cls");
        
    }
    else{
    snake_head_pos_i = snake_head_pos_i +1;
    if(board[snake_head_pos_i][snake_head_pos_j] == 'O'){
        snake_head_pos_i = snake_head_pos_i -1;
        snake.random_dir();
        makesnake(snake);
        return ;
                    
    }
    else {
        setlastmove('d');
        board[snake_head_pos_i][snake_head_pos_j] = 'O';    
        temp_i = snake_head_pos_i;
        temp_j = snake_head_pos_j;
    }
    }
}
else if(snake.dir == 'l'){
    if(snake_head_pos_j == 0){
        snake.random_dir();
        makesnake(snake);
        system("cls");
        
    }
    else{
    snake_head_pos_j = snake_head_pos_j-1 ;
    if(board[snake_head_pos_i][snake_head_pos_j] == 'O'){
        snake_head_pos_j = snake_head_pos_j +1;
        snake.random_dir();
        makesnake(snake);
        return ;
                    
    }
    else {
        setlastmove('l');
        board[snake_head_pos_i][snake_head_pos_j] = 'O';   
        temp_i = snake_head_pos_i;
        temp_j = snake_head_pos_j;
    }
    }
}
else if(snake.dir =='r'){
    if(snake_head_pos_j == 8){
        snake.random_dir();
        makesnake(snake);
        system("cls");
    
    }
    else{
    snake_head_pos_j = snake_head_pos_j +1;
    if(board[snake_head_pos_i][snake_head_pos_j] == 'O'){
        snake_head_pos_j = snake_head_pos_j -1;
        snake.random_dir();
        makesnake(snake);
        return ;
                    
    }
    else {
        setlastmove('r');
        board[snake_head_pos_i][snake_head_pos_j] = 'O';    
        temp_i = snake_head_pos_i;
        temp_j = snake_head_pos_j;
    }
    }
}





}


void Level::makeplayer(Player plyer,RenderWindow &window,bool running){ //draw player on console



if(plyer.dir == 'u'){
    player_head_pos_i = player_head_pos_i -1;
    if(board[player_head_pos_i][player_head_pos_j] == 'O'){
        player_head_pos_i = player_head_pos_i +1;
        player_moves -= 1;
        plyer.input(window,running);
        makeplayer(plyer,window,running);
        return;
    }
    else {
        setlastmove('u');
        board[player_head_pos_i][player_head_pos_j] = 'O';    
        temp_i = player_head_pos_i;
        temp_j = player_head_pos_j;
    }
}
else if(plyer.dir == 'd'){
    player_head_pos_i = player_head_pos_i +1;
    if(board[player_head_pos_i][player_head_pos_j] == 'O'){
        player_head_pos_i = player_head_pos_i -1;
        player_moves -= 1;
        plyer.input(window,running);
        makeplayer(plyer,window,running);
        return ;
                    
    }
    else {
        setlastmove('d');
        board[player_head_pos_i][player_head_pos_j] = 'O';    
        temp_i = player_head_pos_i;
        temp_j = player_head_pos_j;
    }
}
else if(plyer.dir == 'l'){
    player_head_pos_j = player_head_pos_j-1 ;
    if(board[player_head_pos_i][player_head_pos_j] == 'O'){
        player_head_pos_j = player_head_pos_j +1;
        player_moves -= 1;
        plyer.input(window,running);
        makeplayer(plyer,window,running);
        return ;
                    
    }
    else {
        setlastmove('l');
        board[player_head_pos_i][player_head_pos_j] = 'O';   
        temp_i = player_head_pos_i;
        temp_j = player_head_pos_j;
    }
}
else if(plyer.dir =='r'){
    player_head_pos_j = player_head_pos_j +1;
    if(board[player_head_pos_i][player_head_pos_j] == 'O'){
        player_moves -= 1;
        player_head_pos_j = player_head_pos_j -1;
        plyer.input(window,running);
        makeplayer(plyer,window,running);
        return ;
                    
    }
    else {
        setlastmove('r');
        board[player_head_pos_i][player_head_pos_j] = 'O';    
        temp_i = player_head_pos_i;
        temp_j = player_head_pos_j;
    }
}




}


void Level::resetlevel(){//reset vars of level

    snake_head_pos_i = 4;
    snake_head_pos_j = 4;
    player_head_pos_i = 4;
    player_head_pos_j = 4;
    makelevel();


}


void Level::resetgame(){ //go to lvl 1

    currentlevel = 1 ;
    snake_moves = currentlevel + 2;
    player_moves = currentlevel + 2;

}


void Level::completion(){ //if max level is reached

if(currentlevel == 30){ 
    gameon = false;

}

}













#endif 