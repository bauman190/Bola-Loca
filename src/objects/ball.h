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

	bool checkCollision(player::Player& player, Ball& ball);
	void updateBallPosition(Ball& ball, player::Player& player);
}