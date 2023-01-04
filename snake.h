#ifndef SNAKE_H
#define SNAKE_H


#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <string> 
//#include "level.h"

using namespace std;







class Snake
{

    private:
        
        

    public:
        char dir;
        void random_dir();
        void get_snake_pattern(char board[][9]);



};



void Snake::random_dir(){

    
    int random = 1 + (rand() % 4);
    switch (random)
    {
    case 1:
        dir = 'u';
        break;
    case 2:
        dir = 'd';
        break;
    case 3:
        dir = 'l';
        break;
    case 4:
        dir = 'r';
        break;
    default:
        break;
    }
    
    // if(temp_dir == 'd' && dir == 'u'){
    //     Snake::random_dir();
    // }
    // else if(temp_dir == 'u' && dir == 'd'){
    //     Snake::random_dir();
    // }
    // else if(temp_dir == 'l' && dir == 'r'){
    //     Snake::random_dir();
    // }
    // else if(temp_dir == 'r' && dir == 'l'){
    //     Snake::random_dir();
    // }
    // else{
    //     dir = temp_dir;
    // }
        
        

}



void Snake::get_snake_pattern(char board[][9]){

string snake_pattern;

for (int i = 0; i < 9; i++)
{
    for (int j = 0; j < 9; j++)
    {
       if(board[i][j]=='O'){
           snake_pattern = snake_pattern + to_string(i);
           snake_pattern = snake_pattern + to_string(j);
           snake_pattern += '-';
       }
    }
    
}

cout<<snake_pattern;

}







#endif 