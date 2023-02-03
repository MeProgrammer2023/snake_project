#include "ui.h"

void Ui::create_game_window(){


    resolution = Vector2f(900, 900);
    game_window.create(VideoMode(resolution.x, resolution.y), "Game", Style::Close);
    game_window.setFramerateLimit(60);

}

void Ui::score_input(){

    Event event{};

    while (score_window.pollEvent(event)) {
        // Window closed
        if (event.type == Event::Closed) {
            score_window.close();
            exit(1);
        }

        // Handle Keyboard Input
        if (event.type == Event::KeyPressed) {
            // Quit
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                score_window.close();
                exit(1);
            }
        }
        if (event.type == Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                Vector2i mouse_pos = Mouse::getPosition(score_window); // window is a sf::Window
                if(mouse_pos.x>2 && mouse_pos.x<170 && mouse_pos.y>530 && mouse_pos.y<590){
                    score_window.close();
                    running = true;
                    break;

                }
                else if(mouse_pos.x>785 && mouse_pos.x<890 && mouse_pos.y>530 && mouse_pos.y<591){
                    score_window.close();
                    running = false;
                    break;

                }
            }
        }
    }

}

void Ui::create_score_window(){

    resolution = Vector2f(900, 600);
    score_window.create(VideoMode(resolution.x, resolution.y), "score", Style::Close);
    score_window.setFramerateLimit(60);

}

void Ui::drawboard(char board[][9],char lastmove) {

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            int converted_i = (i) * 100;
            int converted_j = (j) * 100;
            if(board[i][j] == 'O'){
                snake_spr.setPosition(converted_i,converted_j);
//                settexture(lastmove);
                game_window.draw(snake_spr);

            }
        }

    }

}

Ui::Ui(){

    font.loadFromFile("assets/georgia.ttf");
    msg.setFont(font);
    msg.setString("Text");
    msg.setCharacterSize(40);
    msg.setFillColor(Color::White);
    msg.setPosition(40,40);

    snake_body_txt.loadFromFile("assets/snake_body.png",IntRect(0,0,100,100));
    snake_spr.setTexture(snake_body_txt);

    bg.loadFromFile("assets/score_bg.png",IntRect(0,0,900,600));
    bg_s.setTexture(bg);
};

