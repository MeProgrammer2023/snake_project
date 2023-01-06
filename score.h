#ifndef SCORE_H
#define SCORE_H


#include <iostream>
#include <algorithm> 
#include <cstring>
using namespace std;


class Score
{

    private:
        string snake_pattern;
        string player_pattern;
        int score = 0;
        




    public:
      
        void update_player_pattern(int i,int j);
        void update_snake_pattern(int i, int j);
        void compare(int sim,int lvl);



};


void Score::update_player_pattern(int i,int j){

player_pattern = player_pattern + to_string(i);
player_pattern = player_pattern + to_string(j);
player_pattern = player_pattern + "-";



}


void Score::update_snake_pattern(int i,int j){

snake_pattern = snake_pattern + to_string(i);
snake_pattern = snake_pattern + to_string(j);
snake_pattern = snake_pattern + "-";



}




void Score::compare(int sim,int lvl){



for (int i = 0; i <snake_pattern.size(); i++)
{
    if(snake_pattern[i]=='-'){
        continue;
    }
    if(snake_pattern[i] == player_pattern[i] && snake_pattern[i+1] == player_pattern[i+1])
    {
        if(snake_pattern[i+1] == '-' ||player_pattern[i+1] == '-'){continue;}
        else{score += 1;}
        
    }
}

// score = score - 1;
cout<<"you're score is :"<<score<<"/"<<lvl;





}




#endif