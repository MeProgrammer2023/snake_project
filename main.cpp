#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>

#include "savefile.h"
#include "level.h"
#include "snake.h"
#include "player.h"
#include "score.h"


using namespace std;

int main(){

srand(time(NULL)); //randomize rand() based on time 


Level lvl; //create the whole game and lvl
Player p;
Savefile file;




p.set_bestscore(lvl.max_lvl); // gets the player max score

p.getname(); // get player's name

file.write_to_file(p.name,p.get_bestscore()); //writes scores to file







}