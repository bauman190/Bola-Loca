#include "game.h"

#include <SFML/Graphics.hpp>



namespace game
{

	void runGame() 
	{

        sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML");
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.clear(sf::Color::Black);
            window.display();
        }


	}





}