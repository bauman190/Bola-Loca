#pragma once
#include <SFML/Graphics.hpp>

namespace player
{ 

struct Player
{
	sf::CircleShape circle;
	float speed;
};

void moveUP(Player& player, float DT);
void moveDown(Player& player, float DT);
void moveLeft(Player& player, float DT);
void moveRight(Player& player, float DT);
}