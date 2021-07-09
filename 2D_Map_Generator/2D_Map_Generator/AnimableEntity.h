#pragma once
#include "Animable.h"
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class AnimableEntity : public Animable
{
public:
	AnimableEntity() = default;

	// SETTERS
	inline void setTexture(sf::Texture texture) { m_texture = texture; };
	inline void setTextureHeight(int height) { sf::IntRect rect = m_currentSprite.getTextureRect(); m_currentSprite.setTextureRect(sf::IntRect(0, 0, rect.width, height)); };
	inline void setOffsetY(float offsetY) { sf::Vector2f pos = m_currentSprite.getPosition(); m_currentSprite.setPosition(pos.x, offsetY); }
	inline void moveTo(float movementValue) { sf::Vector2f pos = m_currentSprite.getPosition(); m_currentSprite.setPosition(movementValue, pos.y); }

	// GETTERS
	inline const sf::Texture getTexture() { return m_texture; };
	inline const float getPosition() { return m_currentSprite.getPosition().y; }
	inline const sf::Sprite getCurrentSprite() { return m_currentSprite; }

protected:
	sf::Texture m_texture;
	sf::Sprite m_currentSprite;
	sf::Vector2<int> m_spriteSize;
};