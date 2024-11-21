#include "game.h"

#include <SFML/Graphics.hpp>

#include "objects/player.h"

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
        P1.speed = 0.0002f;

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            deltaTime = clock.restart().asMicroseconds();
            //std::cout << "Delta Time: " << deltaTime << " segundos" << std::endl;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                player::moveUP(P1,deltaTime);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                player::moveDown(P1, deltaTime);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                player::moveLeft(P1, deltaTime);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                player::moveRight(P1, deltaTime);
            }
            window.clear(sf::Color::White);
            window.draw(P1.circle);
            window.display();
        }


	}





}