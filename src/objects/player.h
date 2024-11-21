#pragma once
#include <SFML/Graphics.hpp>

namespace player
{ 

struct Player
{
	sf::CircleShape circle;
	float speed;
	sf::Vector2f dir;
};

void move(Player& player, float DT);
}