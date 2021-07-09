#pragma once
#include <SFML/Graphics.hpp>
#include "Const.h"
#include "TextureLoader.h"
#include "PerlinNoise.h"
#include "TileType.h"
#include <iostream>
#include <vector>
#include <random>
#include <map>

class Map {
public:
	Map();
	void draw(sf::RenderWindow& window) const;
	void generateRandom();

private:
	std::vector<TileType> m_tiles;
	sf::Texture m_tilesTexture;
};