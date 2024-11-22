#include "ball.h"

#include "player.h"


namespace ball
{ 
	bool checkCollision(sf::CircleShape c1, sf::CircleShape c2)
	{
		float distance = sqrt(pow(c1.getPosition().x - c2.getPosition().x, 2) + 
								pow(c1.getPosition().y - c2.getPosition().y, 2));
							

		return distance <= c1.getRadius() + c2.getRadius();
	}

	void updateBallPosition(Ball& ball, player::Player& player)
	{
		
		if (checkCollision(player.circle, ball.circle))
		{
			sf::Vector2f direction = ball.circle.getPosition() - player.circle.getPosition();
			float magnitude = std::sqrt(direction.x * direction.x + direction.y * direction.y);


			if (magnitude != 0) {
				direction /= magnitude;
			}

		 
			float orbitDis = player.circle.getRadius() + ball.circle.getRadius();
			ball.dir = player.circle.getPosition() + direction * orbitDis;
			ball.circle.setPosition(player.circle.getPosition() + direction * orbitDis);
		}

	}

	void kickBall(Ball& ball) 
	{
		ball.speed = ball.dir * ball.kickForce;
	}

	void ballMovment(Ball& ball, player::Player P1, player::Player P2, float deltaTime) 
	{		
			ball.circle.setPosition(ball.circle.getPosition() + ball.speed * deltaTime);

			ball.speed *= 0.98f;		
	}
}