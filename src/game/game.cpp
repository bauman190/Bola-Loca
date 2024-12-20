#include "game.h"

#include <SFML/Graphics.hpp>

#include "objects/player.h"
#include "objects/ball.h"
#include "objects/goal.h"

#include <iostream>

namespace game
{
    static sf::RenderWindow window(sf::VideoMode(1200, 620), "SFML");
    static player::Player P1;
    static player::Player P2;
    static ball::Ball ball;
    static goal::Goal goal1;
    static goal::Goal goal2;

    static sf::Font font;
    static int puntos1 = 0;
    static int puntos2 = 0;

    static void input();
    static void update();
    static void init();
    static void draw();
    static void resolvePlayerCollision(player::Player& player1, player::Player& player2);
    static void keepEntityInMap(sf::CircleShape& entity);
    static float calDis(sf::CircleShape c1, sf::CircleShape c2);
    static float deltaTime = 0.0f;

    void runGame()
    {

        sf::Clock clock;

        init();

        font.loadFromFile("res/arial.ttf");
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            deltaTime = clock.restart().asMicroseconds();

            input();

            update();

            draw();
            window.display();
        }


    }

    static void init()
    {

        P1.circle.setRadius(15.0f);
        P1.circle.setFillColor(sf::Color::Red);
        P1.circle.setPosition(30, 330);
        P1.circle.setOutlineThickness(1.f);
        P1.circle.setOutlineColor(sf::Color::Black);
        P1.speed = 0.00015f;


        P2.circle.setRadius(15.0f);
        P2.circle.setFillColor(sf::Color::Blue);
        P2.circle.setPosition(1130, 330);
        P2.circle.setOutlineThickness(1.f);
        P2.circle.setOutlineColor(sf::Color::Black);
        P2.speed = 0.00015f;


        ball.circle.setRadius(10.0f);
        ball.circle.setFillColor(sf::Color::White);
        ball.circle.setPosition(600, 320);
        ball.circle.setOutlineThickness(1.f);
        ball.circle.setOutlineColor(sf::Color::Black);

        goal1.goal.setSize({ 20, 100 });
        goal1.goal.setPosition(20 - (goal1.goal.getSize().x / 2), 340 - goal1.goal.getSize().y);
        goal1.goal.setFillColor(sf::Color::White);
        goal1.goal.setOutlineColor(sf::Color::Black);
        goal1.goal.setOutlineThickness(1.0f);

        goal2.goal.setSize({ 20, 100 });
        goal2.goal.setPosition(1180 - (goal2.goal.getSize().x / 2), 340 - goal2.goal.getSize().y);
        goal2.goal.setFillColor(sf::Color::White);
        goal2.goal.setOutlineColor(sf::Color::Black);
        goal2.goal.setOutlineThickness(1.0f);
    }

    static void input()
    {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            P1.dir.y = -1.0f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            P1.dir.y = 1.0f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            P1.dir.x = -1.0f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            P1.dir.x = 1.0f;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            P2.dir.y = -1.0f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            P2.dir.y = 1.0f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            P2.dir.x = -1.0f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            P2.dir.x = 1.0f;
        }

            if (calDis(P1.circle , ball.circle) <= P1.circle.getRadius() + ball.circle.getRadius()  + 10.f && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                ball::kickBall(ball, P1);
            }
            if (calDis(P2.circle, ball.circle) <= P2.circle.getRadius() + ball.circle.getRadius() + 10.f && sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0))
            {
                ball::kickBall(ball, P2);
            }

    }

    static void update()
    {

        player::move(P1, deltaTime);
        player::move(P2, deltaTime);
        if (ball::checkCollision(P1.circle, P2.circle))
        {
            resolvePlayerCollision(P1, P2);
        }
        ball::updateBallPosition(ball, P1);
        ball::updateBallPosition(ball, P2);
        ball::ballMovment(ball, deltaTime);
        ball::ballWall(ball);
        keepEntityInMap(P1.circle);
        keepEntityInMap(P2.circle);
        keepEntityInMap(ball.circle);

        if (goal::colitionBallGoal(ball,goal1))
        {
            ball.circle.setPosition(600, 330);
            P1.circle.setPosition(30, 320);
            P2.circle.setPosition(1130, 320);
            puntos2++;
        }

        if (goal::colitionBallGoal(ball, goal2))
        {
            ball.circle.setPosition(600, 320);
            P1.circle.setPosition(30, 320);
            P2.circle.setPosition(1130, 320);
            puntos1++;
       
        }

    }

    static void draw()
    {

        window.clear(sf::Color::White);
        window.draw(P1.circle);
        window.draw(P2.circle);
        window.draw(ball.circle);
        window.draw(goal1.goal);
        window.draw(goal2.goal);

        sf::Text text;
        text.setFont(font);      
        text.setString(std::to_string(puntos1));
        text.setCharacterSize(40);
        text.setFillColor(sf::Color::Red);
        text.setStyle(sf::Text::Bold);
        text.setPosition(50, 50);
        window.draw(text);

        text.setString(std::to_string(puntos2));
        text.setFillColor(sf::Color::Blue);
        text.setPosition(1100, 50);
        window.draw(text);

    


    }
    static void resolvePlayerCollision(player::Player& player1, player::Player& player2)
    {
        sf::Vector2f direction = player2.circle.getPosition() - player1.circle.getPosition();
        float magnitude = std::sqrt(direction.x * direction.x + direction.y * direction.y);
        
        direction /= magnitude;
 
        float overlap = (player1.circle.getRadius() + player2.circle.getRadius()) - magnitude;

        player1.circle.setPosition(player1.circle.getPosition() - direction * (overlap / 2.f));
        player2.circle.setPosition(player2.circle.getPosition() + direction * (overlap / 2.f));
    }

    static void keepEntityInMap(sf::CircleShape& entity)
    {
        if (entity.getPosition().x - entity.getRadius() < -10)
        {
            entity.setPosition(-10 + entity.getRadius(), entity.getPosition().y);
        }

        if (entity.getPosition().x + entity.getRadius() > 1200)
        {
            entity.setPosition(1200 - entity.getRadius(), entity.getPosition().y);
        }

        if (entity.getPosition().y - entity.getRadius() < -10)
        {
            entity.setPosition(entity.getPosition().x, -10 + entity.getRadius());
        }

        if (entity.getPosition().y + entity.getRadius() > 600)
        {
            entity.setPosition(entity.getPosition().x, 600 - entity.getRadius());
        }
    }

    static float calDis(sf::CircleShape c1, sf::CircleShape c2)
    {
        return sqrt(pow(c1.getPosition().x - c2.getPosition().x, 2) +
            pow(c1.getPosition().y - c2.getPosition().y, 2));
    }

    
}