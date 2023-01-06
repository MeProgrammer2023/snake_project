#ifndef PLAYER_H
#define PLAYER_H

#include <windows.h>
#include <iostream>
#include <conio.h>
using namespace std;




class Player
{

    private:
       string name;
       int bestscore;
       int x_pos,y_pos;

    public:
        char dir;
        string getname();
		string get_player_pattern(char board[][9]);
        void input();
		
        // void move(char dir);


};


string Player::getname(){
cout<<"please enter your name"<<endl;
cin>>name;
return name;
}





void Player::input(){
char c = _getch();
	{
	switch (c)
	{
	case 'a':
		dir = 'l';
		break;
	case 'd':
		dir = 'r';
		break;
	case 'w':
		dir = 'u';
		break;
	case 's':
		dir = 'd';
		break;
		}
	}
}





#endif 