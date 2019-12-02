#include <cmath>

template <typename T>
vec2<T>::vec2(const vec2& other) : x(other.x), y(other.y) {
}

template <typename T>
vec2<T>::vec2(const T& other_x, const T& other_y) : x(other_x), y(other_y) {
}

template <typename T>
void vec2<T>::operator=(const vec2& other) {
    x = other.x;
    y = other.y;
}

template <typename T>
vec2<T> vec2<T>::operator+(const vec2& other) const {
    return vec2(x + other.x, y + other.y);
}

template <typename T>
vec2<T>& vec2<T>::operator+=(const vec2& other) {
    x += other.x;
    y += other.y;
    return *this;
}

template <typename T>
vec2<T> vec2<T>::operator-(const vec2& other) const {
    return vec2(x - other.x, y - other.y);
}

template <typename T>
vec2<T>& vec2<T>::operator-=(const vec2& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

// canonical inner product for R²
template <typename T>
T vec2<T>::operator*(const vec2& other) const {
    return x * other.x + y * other.y;
}

template <typename T>
template <typename S>
vec2<T> vec2<T>::operator*(const S& scalar) const {
    return vec2(scalar * x, scalar * y);
}

template <typename T>
template <typename S>
vec2<T>& vec2<T>::operator*=(const S& scalar) const {
    x *= scalar;
    y *= scalar;
    return *this;
}

template <typename T>
template <typename S>
vec2<T> vec2<T>::operator/(const S& scalar) const {
    return vec2(x / scalar, y / scalar);
}

template <typename T>
template <typename S>
vec2<T>& vec2<T>::operator/=(const S& scalar) const {
    x /= scalar;
    y /= scalar;
    return *this;
}

template <typename T>
T vec2<T>::magnitude() const {
    return std::sqrt(x * x + y * y);
}

template <typename T>
void vec2<T>::normalize() {
    (*this) = *this / magnitude();
}

template <typename T>
vec2<T> vec2<T>::heading() const {
    return *this / magnitude();
}

// Projection of this in the direction of the argument
template <typename T>
vec2<T> vec2<T>::projection(const vec2& other) const {
    
    return other.heading() * (*this * other) / other.magnitude();
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const vec2<T>& vector) {
    out << vector.x << ' ' << vector.y;
    return out;
}