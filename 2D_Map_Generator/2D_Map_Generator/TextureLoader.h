#pragma once
#include <map>
#include <iostream>
#include "SFML/Graphics.hpp"

class TextureLoader
{
public:
    TextureLoader(TextureLoader& other) = delete;
    inline sf::Texture& getTexture(std::string textName) { return m_textures[textName]; }
    void operator=(const TextureLoader&) = delete;
    static TextureLoader* GetInstance();


protected:
    TextureLoader();

private:
    static TextureLoader* textureLoader;
    std::map<std::string, sf::Texture> m_textures;
};