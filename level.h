#ifndef LEVEL_H
#define LEVEL_H

#define width 9
#define length 9

#include <windows.h>
#include <iostream>

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
        bool gameon = true;
        
        

    public:
        int max_lvl;
        char board[width][length];
        void makelevel(); // with console
        void drawsnake(Snake snake); // with console
        void drawplayer(Player plyer); // with cosole 
        Level();//with console
        void resetlevel();
        void resetgame();
        void completion();
        void drawboard();
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


void Level::drawsnake(Snake snake){ //draw snake on console


    
if(snake.dir == 'u'){ 
    if(snake_head_pos_i == 0){ //check if snake hits upper boarder
        snake.random_dir(); //choose a random dir if hits boarder
        drawsnake(snake); // draw the new random dir
        system("cls");
        
    }
    else{
    snake_head_pos_i = snake_head_pos_i -1;
    if(board[snake_head_pos_i][snake_head_pos_j] == 'O'){ //if snake body alredy exist
        snake_head_pos_i = snake_head_pos_i +1; //reset location to its last
        snake.random_dir(); // and choose a random dir again
        drawsnake(snake);
        return ;
    }
    else {
    board[snake_head_pos_i][snake_head_pos_j] = 'O';
        temp_i = snake_head_pos_i;
        temp_j = snake_head_pos_j;
        
    }
    }
}
else if(snake.dir == 'd'){ //check if snake hits lower boarder
    if(snake_head_pos_i == 8){
        snake.random_dir();
        drawsnake(snake);
        system("cls");
        
    }
    else{
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
}
else if(snake.dir == 'l'){
    if(snake_head_pos_j == 0){
        snake.random_dir();
        drawsnake(snake);
        system("cls");
        
    }
    else{
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
}
else if(snake.dir =='r'){
    if(snake_head_pos_j == 8){
        snake.random_dir();
        drawsnake(snake);
        system("cls");
    
    }
    else{
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
}



cout<<"___________________"<<endl;
for (int i = 0; i < width; i++)
{
    cout<<"|";
    for (int j = 0; j < length; j++)
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



cout<<"___________________"<<endl;
for (int i = 0; i < width; i++)
{
    cout<<"|";
    for (int j = 0; j < length; j++)
    {
        // if(board[i][j]=='O'){cout<<" ";}
        if(board[i][j] == '\0'){cout<<"_";}
        cout<<board[i][j]<<"|";
        
    }
    
    cout<<endl;
}



}


void Level::drawboard(){ //draw board for better graphic looks


cout<<"___________________"<<endl;
for (int i = 0; i < width; i++)
{
    cout<<"|";
    for (int j = 0; j < length; j++)
    {
        // if(board[i][j]=='O'){cout<<" ";}
        if(board[i][j] == '\0'){cout<<"_";}
        cout<<board[i][j]<<"|";
        
    }
    
    cout<<endl;
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
    cout<<"GREAT JOB,YOU WON !";
}

}


Level::Level(){  //construct lvl


Player plyer;
Score score;
Snake snake;



while(gameon == true){ //game running loop




makelevel(); //create board of the game
cout<<"MEMORIZE THE PATTERN"<<endl;
Sleep(2000);
system("cls"); //system("clear");
drawboard();

for(int i=0; i<snake_moves; i++){ //show snake pattern

    Sleep(700);
	system("cls"); //system("clear");
    snake.random_dir(); 
    drawsnake(snake);
    score.update_snake_pattern(temp_i,temp_j); // update player score in time 


}


Sleep(1000);
system("cls"); //system("clear");
cout<<"YOUR TURN"<<endl;
makelevel(); //remake the board
drawboard();

for (int i = 0; i<player_moves; i++) //show players board
{
    Sleep(700);
    plyer.input();
    system("cls"); //system("clear");
	drawplayer(plyer);
    score.update_player_pattern(temp_i,temp_j);


}



score.compare(snake_moves,currentlevel + 2); //calculate score 

if(score.get_score() != currentlevel+2){ //player loses

    cout<<"Do you want to try again? Y/N";
    if(plyer.yes_no_input() == false){system("cls");gameon = false;break;}
    resetlevel();    //reset lvl vars
    score.reset_score();     //reset calculated scores 
    resetgame();    // go back to lvl 1
    Sleep(1000);
    system("cls");
    continue;

}

else if (score.get_score() == currentlevel+2){ //player wins


    cout<<"Level "<<currentlevel<<" completed \n";
    cout<<"loading level "<<currentlevel+1;
    Sleep(3000);
    snake_moves += 1;player_moves += 1;currentlevel+=1; //increase snake & player moves and level
    max_lvl = currentlevel;
    score.reset_score();    //reset calculated scores 
    resetlevel(); 
    system("cls");

}

completion(); // check if game is complete 


}

}










#endif 