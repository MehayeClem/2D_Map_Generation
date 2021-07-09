#include "Map.h"

Map::Map() {
		for (int i = 0; i < MAP_SIZE; i++) {
			m_tiles.push_back(ROCK);
		}

		m_tilesTexture = TextureLoader::GetInstance()->getTexture("Ground");
		generateRandom();
}

void Map::draw(sf::RenderWindow& window) const {
	int bound = BLOC_TO_SHOW;
	int lowerBound = 0;
	int upperBound = bound;
	float lowerF = lowerBound * TILE_WIDTH;
	float upperF = upperBound * TILE_WIDTH;

	if (upperBound > MAP_SIZE) {
		upperBound = MAP_SIZE;
	}

	for (int i = lowerBound; i < upperBound; i++) {
		sf::Sprite sprite;
		sprite.setTexture(m_tilesTexture);
		switch (m_tiles[i]) {
		case GRASS:
			sprite.setTextureRect(sf::IntRect(0, 0, TILE_WIDTH, TILE_HEIGHT));
			break;
		case FOREST:
			sprite.setTextureRect(sf::IntRect(TILE_WIDTH, 0, TILE_WIDTH, TILE_HEIGHT));
			break;
		case ROCK:
			sprite.setTextureRect(sf::IntRect(2 * TILE_WIDTH, 0, TILE_WIDTH, TILE_HEIGHT));
			break;
		}
		sprite.setPosition(TILE_WIDTH * (i-30), W_HEIGHT * 4 + TILE_HEIGHT / 2);
		window.draw(sprite);
	}
}

void Map::generateRandom() {

	float proba = 0.0f;
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_real_distribution<float> distribution(0.0, 1.0);
	std::uniform_real_distribution<float> seed(-10000.0f, 10000.0f);

	PerlinNoise perlin(seed(generator), 0.1f, 1.0f, 3);
	for (int i = 0; i < MAP_SIZE; i++) {
		proba = distribution(generator);
		if (perlin.noise1D(i) <= -0.4f) {
			m_tiles[i] = ROCK;
		}
		else if (perlin.noise1D(i) > -0.4f && perlin.noise1D(i) <= 0.2f) {
			m_tiles[i] = FOREST;
		}
		else {
			m_tiles[i] = GRASS;
		}
	}
}