#include <iostream>
#include <conio.h>
#include <ctime>
#include <stdlib.h>


#include "savefile.h"
#include "level.h"





using namespace std;

int main() {

    srand(time(NULL)); //randomize rand() based on time


    Level lvl; //create the whole game and lvl
    Player p;
    Score score;
    Snake snake;
    Savefile file;
    Ui user_interface;



while(user_interface.running == true){


    user_interface.create_game_window();
    lvl.makelevel();
    user_interface.msg.setString("\n \n \n \n \n \n \n \n  \t \t \tMEMORIZE THE PATTERN");
    user_interface.game_window.draw(user_interface.msg);
    user_interface.game_window.display();
    Sleep(1500);
    user_interface.game_window.clear();

    user_interface.drawboard(lvl.board, 'l');
    user_interface.game_window.display();
    Sleep(1000);
    user_interface.game_window.clear();

    for (int i = 0; i < lvl.snake_moves; i++) {

        snake.random_dir();
        lvl.makesnake(snake);
        user_interface.drawboard(lvl.board, lvl.snakelastmove);
        user_interface.game_window.display();

        score.update_snake_pattern(lvl.temp_i, lvl.temp_j);
        Sleep(500);
        user_interface.game_window.clear();
    }


    lvl.makelevel();
    user_interface.game_window.clear();
    user_interface.drawboard(lvl.board, lvl.snakelastmove);
    user_interface.game_window.display();
    user_interface.game_window.clear();
    for (int i = 0; i < lvl.player_moves; i++) {//show players board{

        p.input(user_interface.game_window,user_interface.running);
        p.awaiting_player_input = true;
        lvl.makeplayer(p, user_interface.game_window,user_interface.running);
        user_interface.drawboard(lvl.board, lvl.snakelastmove);
        user_interface.game_window.display();
        score.update_player_pattern(lvl.temp_i, lvl.temp_j);
        user_interface.game_window.clear();
    }

    Sleep(500);

    score.compare(lvl.snake_moves, lvl.currentlevel + 2); //calculate score


    if (score.get_score() == lvl.currentlevel + 2) { //player wins

        user_interface.msg.setString("Level " + to_string(lvl.currentlevel) + "completed");
        user_interface.game_window.draw(user_interface.msg);
        user_interface.game_window.display();
        Sleep(1000);
        user_interface.game_window.clear();
        user_interface.msg.setString("Loading level " + to_string(lvl.currentlevel + 1));
        user_interface.game_window.draw(user_interface.msg);
        user_interface.game_window.display();
        Sleep(1000);
        user_interface.game_window.clear();
        lvl.snake_moves += 1;
        lvl.player_moves += 1;
        lvl.currentlevel += 1; //increase snake & player moves and level
        lvl.max_lvl = lvl.currentlevel;
        score.reset_score();    //reset calculated scores
        lvl.resetlevel();

    } else if (score.get_score() != lvl.currentlevel + 2) { //player loses
        user_interface.game_window.close();
        user_interface.create_score_window();
        user_interface.score_window.draw(user_interface.bg_s);
        user_interface.msg.setString(
                "You Lost, Your score is " + to_string(lvl.currentlevel) + "\n \n \t \t highscore is " +
                to_string(lvl.max_lvl));
        user_interface.score_window.draw(user_interface.msg);
        user_interface.score_window.display();

        while (user_interface.score_window.isOpen()) {
            user_interface.score_input();

        }
        lvl.resetlevel();    //reset lvl vars
        score.reset_score();     //reset calculated scores
        lvl.resetgame();    // go back to lvl 1
    }

}



p.set_bestscore(lvl.max_lvl); // gets the player max score


file.write_to_file(to_string(1),p.get_bestscore()); //writes scores to file


}