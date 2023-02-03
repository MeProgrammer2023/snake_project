#ifndef PATTERNGUI_UI_H
#define PATTERNGUI_UI_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>

using namespace sf;

class Ui{

    private:
    Vector2f resolution;
    Texture snake_body_txt;
    Texture bg;
    Sprite snake_spr;
    Font font;

    public:
    bool running = true;
    RenderWindow game_window;
    RenderWindow score_window;
    Text msg;
    Sprite bg_s;
    Ui();
    void create_game_window();
    void drawboard(char board[][9],char lastmove);
    void settexture(char a);
    void create_score_window();
    void score_input();

};






#endif