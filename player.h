#ifndef PLAYER_H
#define PLAYER_H

#include <windows.h>
#include <iostream>
#include <conio.h>
using namespace std;




class Player
{

    private:
       int bestscore;

    public:
		string name;
        char dir; //direction of player input
        string getname();
        void input();
		bool yes_no_input();
		int get_bestscore();
		void set_bestscore(int i);
       

};


string Player::getname(){ //get player name

cout<<"Please enter your name"<<endl;
cin>>name;
return name;

}


void Player::input(){ //get user input
char c = _getch();
	{
	switch (c)
	{
	case 'a':
		dir = 'l';
		break;
	case 'A':
		dir = 'l';
		break;
	case 'd':
		dir = 'r';
		break;
	case 'D':
		dir = 'r';
		break;
	case 'w':
		dir = 'u';
	case 'W':
		dir = 'u';
		break;
	case 's':
		dir = 'd';
		break;
	case 'S':
		dir = 'd';
		break;
	}
	}
}


bool Player::yes_no_input(){
char d = _getch();

switch (d)
{
case 'y':
	return true;
	break;
case 'Y':
	return true;
	break;
case 'n':
	return false;
	break;
case 'N':
	return false;
	break;
default:
	break;
}

}


int Player::get_bestscore(){

	return bestscore;

}


void Player::set_bestscore(int i){

	bestscore = i;

}




#endif 