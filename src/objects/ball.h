#pragma once
#include <SFML/Graphics.hpp>

#include "player.h"

namespace ball
{
	struct Ball
	{
		sf::CircleShape circle;
		sf::Vector2f speed;
	};

	bool checkCollision(sf::CircleShape c1, sf::CircleShape c2);
	void updateBallPosition(Ball& ball, player::Player& player);
}