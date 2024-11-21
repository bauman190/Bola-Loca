#include "ball.h"

#include "player.h"


namespace ball
{ 
	bool checkCollision(player::Player& player, Ball& ball)
	{
		float distance = sqrt(pow(ball.circle.getPosition().x - player.circle.getPosition().x, 2) + 
								pow(ball.circle.getPosition().y - player.circle.getPosition().y, 2));
							

		return distance <= ball.circle.getRadius() + player.circle.getRadius();
	}

	void updateBallPosition(Ball& ball, player::Player& player)
	{
		
		if (checkCollision(player, ball))
		{
			sf::Vector2f direction = ball.circle.getPosition() - player.circle.getPosition();
			float magnitude = std::sqrt(direction.x * direction.x + direction.y * direction.y);


			if (magnitude != 0) {
				direction /= magnitude;
			}

			
			float orbitDis = player.circle.getRadius() + ball.circle.getRadius();
			ball.circle.setPosition(player.circle.getPosition() + direction * orbitDis);
		}

	}
}