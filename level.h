#ifndef LEVEL_H
#define LEVEL_H

#include <windows.h>
#include <iostream>
#include <vector>
#include "snake.h"


using namespace std;



class Level
{

   
    private:
        const int start_pos_i = 4;
        const int start_pos_j = 4;
        int head_pos_i = 4;
        int head_pos_j = 4;
        int currentlevel = 1;
        


    public:
        char board[9][9];
        void makelevel(); // with console
        void drawlevel(Snake snake); // with console
        char** getboard();
        Level();



};


void Level::makelevel(){ //set all arrays to NULL


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


void Level::drawlevel(Snake snake){ //draw level on console

    
            if(snake.dir == 'u'){
                head_pos_i = head_pos_i -1;
                if(board[head_pos_i][head_pos_j] == 'O'){
                    head_pos_i = head_pos_i +1;
                    snake.random_dir();
                    Level::drawlevel(snake);
                    return ;
                }
                else {
                    board[head_pos_i][head_pos_j] = 'O';    
                }
            }
            else if(snake.dir == 'd'){
                head_pos_i = head_pos_i +1;
                if(board[head_pos_i][head_pos_j] == 'O'){
                    head_pos_i = head_pos_i -1;
                    snake.random_dir();
                    Level::drawlevel(snake);
                    return ;
                    
                }
                else {
                    board[head_pos_i][head_pos_j] = 'O';    
                }
            }
            else if(snake.dir == 'l'){
                head_pos_j = head_pos_j-1 ;
                if(board[head_pos_i][head_pos_j] == 'O'){
                    head_pos_j = head_pos_j +1;
                    snake.random_dir();
                    Level::drawlevel(snake);
                    return ;
                    
                }
                else {
                    board[head_pos_i][head_pos_j] = 'O';    
                }
            }
            else if(snake.dir =='r'){
                head_pos_j = head_pos_j +1;
                if(board[head_pos_i][head_pos_j] == 'O'){
                    head_pos_j = head_pos_j -1;
                    snake.random_dir();
                    Level::drawlevel(snake);
                    return ;
                    
                }
                else {
                    board[head_pos_i][head_pos_j] = 'O';    
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

// bool gameon = true;

makelevel();



for(int i=0; i<currentlevel+2; i++){

    Sleep(700);
	system("cls"); //system("clear");
    
    Snake snake;
    snake.random_dir();
    drawlevel(snake);

    
    snake.get_snake_pattern(board);



}

}










#endif 