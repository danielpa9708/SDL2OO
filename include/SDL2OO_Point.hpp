#pragma once

namespace SDL2OO {
  class Point {
  public:
    int x, y;
    Point();
    Point(int x, int y);
    int getX() const;
    int getY() const;
    Point & setX(int value);
    Point & setY(int value);

    Point operator * (int value) const;
    Point &operator *= (int value);
    Point operator / (int value) const;
    Point &operator /= (int value);
  };
}
