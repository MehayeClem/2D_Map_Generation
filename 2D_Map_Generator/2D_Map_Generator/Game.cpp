#include "./Game.h"
#include<windows.h>

const float Game::WORLD_UNIT = AnimableBuilder::DEFAULT_WIDTH;

Game::Game():
    m_window(sf::VideoMode(W_WIDTH, W_HEIGHT), "2D Maker")
{
    m_window.setFramerateLimit(60);
}

void Game::draw() {
    m_window.clear(sf::Color(0.0f, 0.0f, 0.0f, 1));
    m_map.draw(m_window);
    m_window.display();
}

void Game::update() {
    while (m_window.isOpen()) {
        this->handleCamera();
        this->draw();

        sf::Event event;
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                m_window.close();
        }
    }
}

void Game::handleCamera() {
    this->m_camera.setCenter(W_WIDTH / 2 , W_HEIGHT / 2);
    this->m_camera.setSize(W_WIDTH * 10, W_HEIGHT * 10);
    this->m_window.setView(m_camera);
}