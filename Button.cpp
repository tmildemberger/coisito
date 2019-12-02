#include "Button.hpp"

#include "Managers/GraphicsManager.hpp"

Button::Button(
    GraphicsManager& graphics, vec2f center, const std::string& text, int id)
    : graphics_(graphics), center_(center), text_(text), id_(id) {
}

void Button::draw() {
    vec2f size = graphics_.getTextSize(text_, 40) * 1.7;
    graphics_.drawRect(center_ - size / 2, size, 70, 70, 70, 190);
    graphics_.drawTextCentered(text_, center_, 40);
}

bool Button::isInside(vec2f pos) const {
    vec2f size = graphics_.getTextSize(text_, 40) * 1.7;
    return (center_.x - size.x / 2 <= pos.x && pos.x <= center_.x + size.x / 2
        && center_.y - size.y / 2 <= pos.y && pos.y <= center_.y + size.y / 2);
}

int Button::getId() const {
    return id_;
}