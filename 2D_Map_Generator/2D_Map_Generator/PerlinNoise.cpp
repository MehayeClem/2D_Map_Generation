#include "PerlinNoise.h"

PerlinNoise::PerlinNoise(float seed, float frequence, float amplitude, int octaves) : m_frequence(frequence), m_amplitude(amplitude), m_octaves(octaves) {
	reseed(seed);
}

void PerlinNoise::reseed(float seed) {
	for (int i = 0; i < 256; ++i) {
		p[i] = i;
	}
	std::shuffle(std::begin(p), std::begin(p) + 256, std::default_random_engine(seed));
	for (int i = 0; i < 256; i++) {
		p[256 + i] = p[i];
	}
}

double PerlinNoise::noise1D(double x) {
	double result = 0.0;
	for (int i = 0; i < m_octaves; ++i) {
		result += noise3D(x, 0, 0, m_frequence / pow(2, i));
	}

	return result;
}

double PerlinNoise::noise2D(double x, double y) {
	return noise3D(x, y, 0, m_frequence);
}

double PerlinNoise::noise3D(double x, double y, double z, float frequence) {
	x *= frequence;
	y *= frequence;
	z *= frequence;
	int X = (int)floor(x) & 255;
	int Y = (int)floor(y) & 255;
	int Z = (int)floor(z) & 255; // Find unit cube that contains point

	x -= floor(x);
	y -= floor(y);
	z -= floor(z); // Find relative x, y, z of points in cube

	double u = fade(x);
	double v = fade(y);
	double w = fade(z);

	int A(p[X] + Y),
		AA(p[A] + Z),
		AB(p[A + 1] + Z),
		B(p[X + 1] + Y),
		BA(p[B] + Z),
		BB(p[B + 1] + Z); // Hash coordinates of the 8 cubes cube corners

	return m_amplitude * lerp(w, lerp(v, lerp(u, grad(p[AA], x, y, z),
		grad(p[BA], x - 1, y, z)),
		lerp(u, grad(p[AB], x, y - 1, z),
			grad(p[BB], x - 1, y - 1, z))),
		lerp(v, lerp(u, grad(p[AA + 1], x, y, z - 1),
			grad(p[BA + 1], x - 1, y, z - 1)),
			lerp(u, grad(p[AB + 1], x, y - 1, z - 1),
				grad(p[BB + 1], x - 1, y - 1, z - 1))));
}

double PerlinNoise::fade(double t) {
	return t * t * t * (t * (t * 6 - 15) + 10);
}

double PerlinNoise::lerp(double t, double a, double b) {
	return a + t * (b - a);
}

double PerlinNoise::grad(int hash, double x, double y, double z) {
	int h = hash & 15;
	double u = h < 8 ? x : y;
	double v = h < 4 ? y : h == 12 || h == 14 ? x : z;

	return ((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v);
}



