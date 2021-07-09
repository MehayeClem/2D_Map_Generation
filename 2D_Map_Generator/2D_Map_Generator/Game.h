#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "AnimableBuilder.h"
#include "Const.h"

class Game
{
public:
	Game();

	void draw();
	void update();
	void handleCamera();

	const static float WORLD_UNIT;
private:
	sf::RenderWindow m_window;
	Map m_map;
	sf::View m_camera;

	const float ratio = 9 / 16;
	const unsigned int S_SIZE = 200;
	const unsigned int SCALE_FACTOR = 2;
};