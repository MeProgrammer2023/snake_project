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
       char dir;
       int x_pos,y_pos;

    public:
        string getname();
        void input();
        void move(char dir);


};


string Player::getname(){
cout<<"please enter your name"<<endl;
cin>>name;
return name;
}

void Player::input(){
if (_kbhit())
	{
	switch (_getch())
	{
	case 'a':
		dir = 'L';
		break;
	case 'd':
		dir = 'R';
		break;
	case 'w':
		dir = 'U';
		break;
	case 's':
		dir = 'D';
		break;
		}
	}
}

void Player::move(char dir){

switch (dir)
{
case 'L':
    x_pos--;
    break;
case 'R':
    x_pos++;
    break;
case 'U':
    y_pos++;
    break;
case 'D':
    y_pos--;
    break;
default:
    break;
}
}



#endif 