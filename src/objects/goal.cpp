#include "goal.h"



bool goal::colitionBallGoal(ball::Ball ball, goal::Goal goal)
{
	float testX = ball.circle.getPosition().x;
	float testY = ball.circle.getPosition().y;

	if (ball.circle.getPosition().x < goal.goal.getPosition().x)
	{
		testX = goal.goal.getPosition().x;
	}
		

	else if (ball.circle.getPosition().x > goal.goal.getPosition().x + goal.goal.getSize().x)
	{
		testX = goal.goal.getPosition().x + goal.goal.getSize().x;
	}

	if (ball.circle.getPosition().y < goal.goal.getPosition().y)
	{
		testY = goal.goal.getPosition().y;
	}

	else if (ball.circle.getPosition().y > goal.goal.getPosition().y + goal.goal.getSize().y)
	{
		testY = goal.goal.getPosition().y;
	}

	float distX = ball.circle.getPosition().x - testX;
	float distY = ball.circle.getPosition().y - testY;
	float distance = sqrt((distX * distX) + (distY * distY));

	return distance < ball.circle.getRadius();
}
