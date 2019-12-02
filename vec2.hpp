#ifndef VEC2_HPP
#define VEC2_HPP

#include <ostream>

template <typename T>
class vec2 {
public:
    T x;
    T y;

    vec2(const vec2& other);
    vec2(const T& other_x = 0, const T& other_y = 0);

    void operator=(const vec2& other);

    vec2 operator+(const vec2& other) const;
    vec2& operator+=(const vec2& other);

    vec2 operator-(const vec2& other) const;
    vec2& operator-=(const vec2& other);

    // canonical inner product for R²
    T operator*(const vec2& other) const;

    template <typename S>
    vec2 operator*(const S& scalar) const;
    template <typename S>
    vec2& operator*=(const S& scalar) const;

    template <typename S>
    vec2 operator/(const S& scalar) const;
    template <typename S>
    vec2& operator/=(const S& scalar) const;

    T magnitude() const;
    void normalize();

    vec2 heading() const;

    // Projection of this in the direction of the argument
    vec2 projection(const vec2& other) const;
};

typedef vec2<float> vec2f;
typedef vec2<int> vec2i;
typedef vec2<unsigned int> vec2u;

template <typename T>
std::ostream& operator<<(std::ostream& out, const vec2<T>& vector);

#include "vec2.ipp"

#endif // VEC2_HPP