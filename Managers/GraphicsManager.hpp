#ifndef GRAPHICS_MANAGER_HPP
#define GRAPHICS_MANAGER_HPP

#include "../vec2.hpp"
#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class GraphicsManager {
public:
    GraphicsManager();
    ~GraphicsManager();
    bool loadAsset(const std::string& path);

    void drawAsset(const std::string& id, vec2f at) const;
    void drawRect(
        vec2f at, vec2f size, int r, int g, int b, int alpha = 255) const;
    void drawTextCentered(
        const std::string& text, vec2f at, unsigned size) const;

    // void centerCamera(Utils::VectorF at);
    sf::Window* getWindow() const;
    void display() const;

    void clear(int r, int g, int b) const;

    vec2f getViewSize() const;
    vec2f getMousePos() const;
    vec2f getMousePosInView() const;
    vec2f getSizeOfAsset(const std::string& id) const;
    vec2f getTextSize(const std::string& text, unsigned size) const;

private:
    std::map<std::string, sf::Texture*> assets;
    sf::RenderWindow* window;
    sf::View view;
    vec2f camera_pos;
    vec2f camera_size;
    sf::Font font;
    bool outOfSight(vec2f at, vec2f size) const;
};

#endif // GRAPHICS_MANAGER_HPP