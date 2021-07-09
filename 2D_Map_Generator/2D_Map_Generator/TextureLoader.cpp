#include "TextureLoader.h"

TextureLoader* TextureLoader::textureLoader = nullptr;;

TextureLoader::TextureLoader() {
	if (!m_textures["Ground"].loadFromFile("./assets/tiles.png")) {
		std::cout << "Impossible de charger les textures" << std::endl;
	}
}

TextureLoader* TextureLoader::GetInstance()
{
	if (textureLoader == nullptr) {
		textureLoader = new TextureLoader();
	}
	return textureLoader;
}