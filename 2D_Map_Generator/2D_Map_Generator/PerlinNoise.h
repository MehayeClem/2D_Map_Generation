#pragma once
#include <math.h>  
#include <iostream>
#include <random>

class PerlinNoise
{
public:
	PerlinNoise(float seed, float frequence = 0.1f, float amplitude = 1.0f, int octaves = 1);

	double noise1D(double x);
	double noise2D(double x, double y);
	double noise3D(double x, double y, double z, float frequence);
	void reseed(float seed);

private:
	double fade(double t);
	double lerp(double t, double a, double b);
	double grad(int hash, double x, double y, double z);

	int p[512];
	float m_frequence;
	float m_amplitude;
	int m_octaves;
};

