#include "Thing.hpp"

Thing::Thing(int val) : val_(val) {
}

int Thing::getVal() const {
    return val_;
}