#ifndef VISIBLE_THING_HPP
#define VISIBLE_THING_HPP

#include "Thing.hpp"
#include "vec2.hpp"

class GraphicsManager;

class VisibleThing : public Thing {
public:
    VisibleThing(int val, GraphicsManager& graphics, vec2f center);
    VisibleThing(const VisibleThing& other);
    VisibleThing& operator=(const VisibleThing& other);

    void setCenter(vec2f center);
    void setColor(int r, int g, int b);

    void draw();

private:
    GraphicsManager& graphics_;
    vec2f center_;
    int r_;
    int g_;
    int b_;
};

#endif // VISIBLE_THING_HPP