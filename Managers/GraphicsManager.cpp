#include "GraphicsManager.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

GraphicsManager::GraphicsManager() {
    std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();

    unsigned width  = modes[0].width * .7;
    unsigned height = modes[0].height * .7;
    window          = new sf::RenderWindow(
        sf::VideoMode(width, height), "AAA", sf::Style::Resize);
    window->setKeyRepeatEnabled(false);

    width  = 1200;
    height = width / 16 * 9;
    view   = sf::View(sf::FloatRect(0, 0, width, height));
    window->setView(view);

    font.loadFromFile("font-02.ttf");

    camera_size = vec2f(width, height);
}

GraphicsManager::~GraphicsManager() {
    for (auto i = assets.begin(); i != assets.end(); ++i) {
        delete i->second;
    }
    assets.clear();
}

bool GraphicsManager::loadAsset(const std::string& path) {
    auto it = assets.find(path);
    if (it != assets.end()) {
        return true;
    } else {
        sf::Texture* texture = new sf::Texture();
        if (!texture->loadFromFile(path)) {
            std::cout << "e morreu\n";
            exit(1234);
        }
        assets.emplace(path, texture);
        return true;
    }
}

void GraphicsManager::drawAsset(const std::string& id, vec2f at) const {
    sf::Texture* texture;
    auto it = assets.find(id);
    if (it == assets.end()) {
        std::cout << "morreu porque tentou desenhar algo nao criado: \n" << id;
        exit(1235);
    }
    texture           = it->second;
    sf::Vector2u size = texture->getSize();

    if (!outOfSight(at, vec2f(size.x, size.y))) {
        at -= camera_pos;
        sf::Sprite sprite;
        sprite.setTexture(*texture);
        sprite.setPosition(at.x, at.y);
        window->draw(sprite);
    }
}

void GraphicsManager::drawRect(
    vec2f at, vec2f size, int r, int g, int b, int alpha) const {
    if (!outOfSight(at, size)) {
        at -= camera_pos;
        sf::RectangleShape rect
            = sf::RectangleShape(sf::Vector2f(size.x, size.y));

        rect.setFillColor(sf::Color(r, g, b, alpha));
        rect.setPosition(at.x, at.y);
        window->draw(rect);
    }
}

void GraphicsManager::drawTextCentered(
    const std::string& text, vec2f at, unsigned size) const {
    sf::Text txt = sf::Text(text, font);
    txt.setCharacterSize(size);
    txt.setFillColor(sf::Color::White);
    sf::FloatRect bounding  = txt.getGlobalBounds();

    txt.move((at.x - bounding.width / 2) - bounding.left, (at.y - bounding.height / 2) - bounding.top);
    
    // bounding  = txt.getGlobalBounds();
    // sf::RectangleShape rect = sf::RectangleShape(sf::Vector2f(bounding.width, bounding.height));

    // rect.setOutlineThickness(1);
    // rect.setOutlineColor(sf::Color::Red);
    // rect.setFillColor(sf::Color::Transparent);
    // rect.setPosition(bounding.left, bounding.top);

    // sf::CircleShape circ = sf::CircleShape(4);
    // circ.setPosition(at.x - circ.getGlobalBounds().width / 2, at.y - circ.getGlobalBounds().height / 2);
    // circ.setOutlineThickness(0);
    // circ.setFillColor(sf::Color::Yellow);
    // window->draw(rect);
    window->draw(txt);
    // window->draw(circ);
}

// void GraphicsManager::centerCamera(vec2f at) {
//     camera_pos = at - camera_size * .5;
// }

bool GraphicsManager::outOfSight(vec2f at, vec2f size) const {
    return (at.x + size.x < camera_pos.x || at.y + size.y < camera_pos.y
        || at.x > camera_pos.x + camera_size.x
        || at.y > camera_pos.y + camera_size.y);
}

sf::Window* GraphicsManager::getWindow() const {
    return window;
}

void GraphicsManager::display() const {
    window->display();
}

void GraphicsManager::clear(int r, int g, int b) const {
    window->clear(sf::Color(r, g, b));
}

vec2f GraphicsManager::getViewSize() const {
    return camera_size;
}

vec2f GraphicsManager::getMousePos() const {
    sf::Vector2i pos = sf::Mouse::getPosition(*window);
    return vec2f(pos.x, pos.y);
}

vec2f GraphicsManager::getMousePosInView() const {
    sf::Vector2i pos         = sf::Mouse::getPosition(*window);
    sf::Vector2u window_size = window->getSize();
    return vec2f(pos.x / static_cast<float>(window_size.x) * camera_size.x,
               pos.y / static_cast<float>(window_size.y) * camera_size.y)
        + camera_pos;
}

vec2f GraphicsManager::getSizeOfAsset(const std::string& id) const {
    sf::Texture* texture;
    auto it = assets.find(id);
    if (it == assets.end()) {
        std::cout << "morreu porque tentou desenhar algo nao criado\n";
        exit(1235);
    }
    texture           = it->second;
    sf::Vector2u size = texture->getSize();
    return vec2f(size.x, size.y);
}

vec2f GraphicsManager::getTextSize(
    const std::string& text, unsigned size) const {
    sf::Text txt = sf::Text(text, font);
    txt.setCharacterSize(size);
    txt.setFillColor(sf::Color::White);
    sf::FloatRect bounding = txt.getGlobalBounds();

    return { bounding.width, bounding.height };
}