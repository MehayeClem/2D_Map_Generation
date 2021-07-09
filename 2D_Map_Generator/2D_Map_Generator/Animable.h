#pragma once
#include <SFML/Graphics.hpp>

class Animable {
public:
	virtual void animate(float deltaTime) = 0;
	virtual void draw(sf::RenderWindow& window, bool drawFilter = false) = 0;
	virtual void reset() = 0;
};