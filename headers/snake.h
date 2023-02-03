#ifndef SNAKE_H
#define SNAKE_H


#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>


class Snake
{

    private:
        

    public:
        char dir;
        void random_dir();


};



void Snake::random_dir(){

    
    int random = 1 + (rand() % 4);
    switch (random)
    {
    case 1:
        dir = 'u';//u
        break;
    case 2:
        dir = 'd';//d
        break;
    case 3:
        dir = 'l';//l
        break;
    case 4:
        dir = 'r';//r
        break;
    default:
        break;
    }
    

}





#endif 