#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "vec2.hpp"
#include <string>

class GraphicsManager;

class Button {
public:
    Button(GraphicsManager& graphics, vec2f center, const std::string& text,
        int id);
    void draw();

    bool isInside(vec2f pos) const;
    int getId() const;

private:
    GraphicsManager& graphics_;
    vec2f center_;
    std::string text_;
    int id_;
};

#endif // BUTTON_HPP