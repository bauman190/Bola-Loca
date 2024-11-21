#include "player.h"


namespace player
{
	void moveUP(Player& player, float DT)
	{
		if (player.circle.getPosition().y - player.circle.getRadius() > - 10)
		{
			float y = player.circle.getPosition().y - player.speed * DT;
			player.circle.setPosition(player.circle.getPosition().x, y);
		}
	}
	void moveDown(Player& player, float DT)
	{
		if (player.circle.getPosition().y + player.circle.getRadius() < 600 - player.circle.getRadius())
		{
			float y = player.circle.getPosition().y + player.speed * DT;
			player.circle.setPosition(player.circle.getPosition().x, y);
		}
	}
	void moveLeft(Player& player, float DT)
	{
		if (player.circle.getPosition().x - player.circle.getRadius() > - 10)
		{
			float x = player.circle.getPosition().x - player.speed * DT;
			player.circle.setPosition(x, player.circle.getPosition().y);
		}
	}
	void moveRight(Player& player, float DT)
	{
		if (player.circle.getPosition().x + player.circle.getRadius() < 1200 - player.circle.getRadius())
		{
			float x = player.circle.getPosition().x + player.speed * DT;
			player.circle.setPosition(x, player.circle.getPosition().y);
		}
	}
}