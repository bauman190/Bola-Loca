#pragma once
#include <SFML/Graphics.hpp>

#include "player.h"

namespace ball
{
	struct Ball
	{
		sf::CircleShape circle;
		sf::Vector2f speed;
		sf::Vector2f dir;
		float kickForce = 0.007f;
	};

	bool checkCollision(sf::CircleShape c1, sf::CircleShape c2);
	void updateBallPosition(Ball& ball, player::Player& player);
	void ballMovment(Ball& ball, float deltaTime);
	void kickBall(Ball& ball, player::Player player);
	void ballWall(Ball& ball);
}