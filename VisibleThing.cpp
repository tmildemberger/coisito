#include "VisibleThing.hpp"

#include "Managers/GraphicsManager.hpp"

#include <sstream>

VisibleThing::VisibleThing(int val, GraphicsManager& graphics, vec2f center)
    : Thing(val), graphics_(graphics), center_(center) {
    setColor(40, 80, 120);
}

VisibleThing::VisibleThing(const VisibleThing& other)
    : Thing(other.val_), graphics_(other.graphics_), center_(other.center_) {
    // val_ = other.val_;
    // center_ = other.center_;
    setColor(40, 80, 120);
}

VisibleThing& VisibleThing::operator=(const VisibleThing& other) {
    val_ = other.val_;
    // center_ = other.center_;
    setColor(40, 80, 120);
    return *this;
}

void VisibleThing::setCenter(vec2f center) {
    center_ = center;
}

void VisibleThing::setColor(int r, int g, int b) {
    r_ = r;
    g_ = g;
    b_ = b;
}

void VisibleThing::draw() {
    vec2f size(40, 40);
    graphics_.drawRect(center_ - size / 2, size, r_, g_, b_);
    std::stringstream ss;
    ss << val_;
    graphics_.drawTextCentered(ss.str(), center_, 20);
}