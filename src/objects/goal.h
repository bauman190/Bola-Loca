#pragma once
#include <SFML/Graphics.hpp>
#include "ball.h"

namespace goal
{

	struct Goal
	{
		sf::RectangleShape goal;
	};

	bool colitionBallGoal(ball::Ball ball, Goal goal);
}
