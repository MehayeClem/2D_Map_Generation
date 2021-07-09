#pragma once
#include "AnimableEntity.h"
#include "TextureLoader.h"

class AnimableBuilder {
public:
	virtual AnimableEntity& build() = 0;
	const static int DEFAULT_WIDTH = 298;
	const static int DEFAULT_HEIGHT = 421;
};