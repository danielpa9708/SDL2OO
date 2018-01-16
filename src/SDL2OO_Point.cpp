#include "SDL2OO_Point.hpp"

namespace SDL2OO {
  Point::Point()
    : x(0), y(0) {}

  Point::Point(int x, int y)
    : x(x), y(y) {}

  int Point::getX() const {
    return x;
  }

  int Point::getY() const {
    return y;
  }

  Point & Point::setX(int value) {
    x = value;
    return *this;
  }

  Point & Point::setY(int value) {
    y = value;
    return *this;
  }

  Point &Point::operator *= (int value) {
    x *= value;
    y *= value;
    return *this;
  }

  Point &Point::operator /= (int value) {
    x /= value;
    y /= value;
    return *this;
  }

  Point Point::operator * (int value) const {
    return Point(x * value, y * value);
  }

  Point Point::operator / (int value) const {
    return Point(x / value, y / value);
  }
}
