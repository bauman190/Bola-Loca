#include "player.h"


namespace player
{

	void move(Player& player, float DT) 
	{

		float magnitude = std::sqrt(player.dir.x * player.dir.x + player.dir.y * player.dir.y);

		if (magnitude > 0.0f) {
			
			player.dir.x = (player.dir.x / magnitude) * player.speed * DT;
			player.dir.y = (player.dir.y / magnitude) * player.speed * DT;

			
			float newX = player.circle.getPosition().x + player.dir.x;
			float newY = player.circle.getPosition().y + player.dir.y;
			if (newX - player.circle.getRadius() > -10 &&
				newX + player.circle.getRadius() < 1200) {
				player.circle.setPosition(newX, player.circle.getPosition().y);
			}
			if (newY - player.circle.getRadius() > -10 &&
				newY + player.circle.getRadius() < 600) {
				player.circle.setPosition(player.circle.getPosition().x, newY);
			}
			player.dir.x = 0.0f;
			player.dir.y = 0.0f;
		}
	}
}