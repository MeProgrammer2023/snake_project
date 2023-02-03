#ifndef PLAYER_H
#define PLAYER_H

#include <windows.h>
#include <iostream>
#include <conio.h>
#include "ui.h"

using namespace std;




class Player
{

    private:
       int bestscore;

    public:
        bool flag = true;
        bool awaiting_player_input = true;
		string name;
        char dir; //direction of player input
        string getname();
        void input(RenderWindow &window,bool running);
		bool yes_no_input();
		int get_bestscore();
		void set_bestscore(int i);
       

};


string Player::getname(){ //get player name

cout<<"Please enter your name"<<endl;
cin>>name;
return name;

}


//void Player::input(){ //get user input
//char c = _getch();
//	{
//	switch (c)
//	{
//	case 'a':
//		dir = 'l';
//		break;
//	case 'A':
//		dir = 'l';
//		break;
//	case 'd':
//		dir = 'r';
//		break;
//	case 'D':
//		dir = 'r';
//		break;
//	case 'w':
//		dir = 'u';
//	case 'W':
//		dir = 'u';
//		break;
//	case 's':
//		dir = 'd';
//		break;
//	case 'S':
//		dir = 'd';
//		break;
//	}
//	}
//}


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


void Player::input(RenderWindow &window,bool running) {

    Event event{};
    while (awaiting_player_input == true) {
        while (window.pollEvent(event)) {
            // Window closed
            if (event.type == Event::Closed) {
                window.close();
                exit(1);


            }

            // Handle Keyboard Input
            if (event.type == Event::KeyPressed) {

                if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                    window.close();
                    exit(1);
                } else if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) {
                    dir = 'u';
                    awaiting_player_input = false;
                } else if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) {
                    dir = 'd';
                    awaiting_player_input = false;
                } else if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)) {
                    dir = 'l';
                    awaiting_player_input = false;
                } else if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)) {
                    dir = 'r';
                    awaiting_player_input = false;
                }


            }
            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    Vector2i mouse_pos = Mouse::getPosition(window); // window is a sf::Window

                }
            }
        }
    }
}


#endif 