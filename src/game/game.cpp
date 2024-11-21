#include "game.h"

#include <SFML/Graphics.hpp>

#include "objects/player.h"
#include "objects/ball.h"

#include <iostream>

namespace game
{

	void runGame() 
	{

        sf::RenderWindow window(sf::VideoMode(1200, 600), "SFML");

        sf::Clock clock;

        
        float deltaTime = 0.0f;

        player::Player P1;
        P1.circle.setRadius(15.0f);
        P1.circle.setFillColor(sf::Color::Red);
        P1.circle.setPosition(600, 300);
        P1.circle.setOutlineThickness(1.f);
        P1.circle.setOutlineColor(sf::Color::Black);
        P1.speed = 0.00015f;

        player::Player P2;
        P2.circle.setRadius(15.0f);
        P2.circle.setFillColor(sf::Color::Blue);
        P2.circle.setPosition(300, 400);
        P2.circle.setOutlineThickness(1.f);
        P2.circle.setOutlineColor(sf::Color::Black);
        P2.speed = 0.00015f;

        ball::Ball ball;
        ball.circle.setRadius(10.0f);
        ball.circle.setFillColor(sf::Color::White);
        ball.circle.setPosition(500, 200);
        ball.circle.setOutlineThickness(1.f);
        ball.circle.setOutlineColor(sf::Color::Black);


        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            deltaTime = clock.restart().asMicroseconds();
           
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

            player::move(P1, deltaTime);
            player::move(P2, deltaTime);
            ball::updateBallPosition(ball, P1);
            ball::updateBallPosition(ball, P2);
            window.clear(sf::Color::White);
            window.draw(P1.circle);
            window.draw(P2.circle);
            window.draw(ball.circle);
            window.display();
        }


	}





}