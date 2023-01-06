#ifndef LEVEL_H
#define LEVEL_H

#include <windows.h>
#include <iostream>
#include <vector>

#include "snake.h"
#include "player.h"
#include "score.h"

using namespace std;



class Level
{

   
    private:
        const int start_pos_i = 4;
        const int start_pos_j = 4;
        int snake_head_pos_i = 4;
        int snake_head_pos_j = 4;
        int player_head_pos_i = 4;
        int player_head_pos_j = 4;
        int currentlevel = 1 ;
        int snake_moves = currentlevel + 2;
        int player_moves = currentlevel + 2;
        int temp_i,temp_j;
        
        


    public:
        char board[9][9];
        void makelevel(Player plyer); // with console
        void drawsnake(Snake snake); // with console
        void drawplayer(Player plyer); // with cosole 
        Level();



};


void Level::makelevel(Player plyer){ //set all arrays to NULL


    for (int i = 0; i < 9; i++)
    {
         for (int j = 0; j < 9; j++)
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


void Level::drawsnake(Snake snake){ //draw level on console


    
if(snake.dir == 'u'){
    snake_head_pos_i = snake_head_pos_i -1;
    if(board[snake_head_pos_i][snake_head_pos_j] == 'O'){
        snake_head_pos_i = snake_head_pos_i +1;
        snake.random_dir();
        drawsnake(snake);
        return ;
    }
    else {
    board[snake_head_pos_i][snake_head_pos_j] = 'O';
        temp_i = snake_head_pos_i;
        temp_j = snake_head_pos_j;
        
    }
}
else if(snake.dir == 'd'){
    snake_head_pos_i = snake_head_pos_i +1;
    if(board[snake_head_pos_i][snake_head_pos_j] == 'O'){
        snake_head_pos_i = snake_head_pos_i -1;
        snake.random_dir();
        drawsnake(snake);
        return ;
                    
    }
    else {
        board[snake_head_pos_i][snake_head_pos_j] = 'O';    
        temp_i = snake_head_pos_i;
        temp_j = snake_head_pos_j;
    }
}
else if(snake.dir == 'l'){
    snake_head_pos_j = snake_head_pos_j-1 ;
    if(board[snake_head_pos_i][snake_head_pos_j] == 'O'){
        snake_head_pos_j = snake_head_pos_j +1;
        snake.random_dir();
        drawsnake(snake);
        return ;
                    
    }
    else {
        board[snake_head_pos_i][snake_head_pos_j] = 'O';   
        temp_i = snake_head_pos_i;
        temp_j = snake_head_pos_j;
    }
}
else if(snake.dir =='r'){
    snake_head_pos_j = snake_head_pos_j +1;
    if(board[snake_head_pos_i][snake_head_pos_j] == 'O'){
        snake_head_pos_j = snake_head_pos_j -1;
        snake.random_dir();
        drawsnake(snake);
        return ;
                    
    }
    else {
        board[snake_head_pos_i][snake_head_pos_j] = 'O';    
        temp_i = snake_head_pos_i;
        temp_j = snake_head_pos_j;
    }
}




cout<<"____________________"<<endl;
for (int i = 0; i < 9; i++)
{
    cout<<"|";
    for (int j = 0; j < 9; j++)
    {
        // if(board[i][j]=='O'){cout<<" ";}
        if(board[i][j] == '\0'){cout<<"_";}
        cout<<board[i][j]<<"|";
        
    }
    
    cout<<endl;
}







}


void Level::drawplayer(Player plyer){ //draw player on console




if(plyer.dir == 'u'){
    player_head_pos_i = player_head_pos_i -1;
    if(board[player_head_pos_i][player_head_pos_j] == 'O'){
        player_head_pos_i = player_head_pos_i +1;
        player_moves -= 1;
        plyer.input();
        drawplayer(plyer);
        return;
    }
    else {
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
        plyer.input();
        drawplayer(plyer);
        return ;
                    
    }
    else {
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
        cout<<"wrong input";
        plyer.input();
        drawplayer(plyer);
        return ;
                    
    }
    else {
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
        plyer.input();
        drawplayer(plyer);
        return ;
                    
    }
    else {
        board[player_head_pos_i][player_head_pos_j] = 'O';    
        temp_i = player_head_pos_i;
        temp_j = player_head_pos_j;
    }
}



cout<<"____________________"<<endl;
for (int i = 0; i < 9; i++)
{
    cout<<"|";
    for (int j = 0; j < 9; j++)
    {
        // if(board[i][j]=='O'){cout<<" ";}
        if(board[i][j] == '\0'){cout<<"_";}
        cout<<board[i][j]<<"|";
        
    }
    
    cout<<endl;
}



}




Level::Level(){  //construct lvl


Player plyer;
Score score;
Snake snake;


makelevel(plyer);


    cout<<"MEMORIZE THE PATTERN"<<endl;
    Sleep(2000);

for(int i=0; i<snake_moves; i++){ //show snake pattern

    Sleep(700);
	system("cls"); //system("clear");
    

    snake.random_dir();
    drawsnake(snake);
    score.update_snake_pattern(temp_i,temp_j);

}

Sleep(1000);
system("cls"); //system("clear");


cout<<"YOUR TURN"<<endl;

makelevel(plyer); //remake the board


for (int i = 0; i<player_moves; i++) //show players board
{

    Sleep(700);
    plyer.input();
    system("cls"); //system("clear");
	drawplayer(plyer);
    
    
    
    score.update_player_pattern(temp_i,temp_j);

}

score.compare(snake_moves,currentlevel + 2);

}

   










#endif 