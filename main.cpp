#include <sstream>
#include <cstdlib>
#include "bat.h"

int main()
{
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Pong", Style::Fullscreen);

    int score = 0;
    int lives = 3;

    Bat bat(1920 / 2, 1080 - 20);
    //urmeaza mingea |  :)
    //               V

    Text hud;
    Font font;
    font.loadFromFile("fonts/DS-DIGI.TTF");
    hud.setFont(font);
    hud.setCharacterSize(75);
    hud.setFillColor(Color::White);
    hud.setPosition(20, 20);
    Clock clock;
    /*********************
     ********WHILE********
     *********************/
    while(window.isOpen()) {
        /*********************
         ********INPUT********
         *********************/
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape))
            window.close();
        if (Keyboard::isKeyPressed(Keyboard::Left))
            bat.moveLeft();
        else
            bat.stopLeft();
        if (Keyboard::isKeyPressed(Keyboard::Right))
            bat.moveRight();
        else
            bat.stopRight();
        /********************
         *******UPDATE*******
         ********************/
        Time dt = clock.restart();
        bat.update(dt);
        std::stringstream ss;
        ss << "Score:" << score << "  Lives:" << lives;
        hud.setString(ss.str());
        /*******************
         *******DRAW********
         *******************/
        window.clear();
        window.draw(hud);
        window.draw(bat.getShape());
        window.display();
    }
    return 0;
}
