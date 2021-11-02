#include <sstream>
#include <cstdlib>
#include "bat.h"
#include "ball.h"

int main()
{
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Pong", Style::Fullscreen);

    int score = 0;
    int lives = 3;

    Bat bat(1920 / 2, 1080 - 20);
    Ball ball(1920/2, 0);

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
        ball.update(dt);
        std::stringstream ss;
        ss << "Score:" << score << "  Lives:" << lives;
        hud.setString(ss.str());

        if (ball.getPosition().top > window.getSize().y)
        {
            ball.reboundBottom();
            --lives;

            if(lives < 1) {
                score = 0;
                lives = 3;
            }
        }

        if (ball.getPosition().top < 0)
        {
            ball.reboundBatOrTop();

            ++score;
        }
        if (ball.getPosition().left < 0 || ball.getPosition().left + ball.getPosition().width > window.getSize().x)
            ball.reboundSides();
        if (ball.getPosition().intersects(bat.getPosition()))
            ball.reboundBatOrTop();
        if (bat.getPosition().left + bat.getPosition().width < 0)
            bat.setPosition(1920, bat.getPosition().top);
        if (bat.getPosition().left  > window.getSize().x)
            bat.setPosition(0 - bat.getPosition().width, bat.getPosition().top);
        /*******************
         *******DRAW********
         *******************/
        window.clear();
        window.draw(hud);
        window.draw(bat.getShape());
        window.draw(ball.getShape());
        window.display();
    }
    return 0;
}
