#pragma once

#include "SDL2OO_Point.hpp"

class SDL_Rect;

namespace SDL2OO {
  class Rect {
  public:
    Point position, size;
    Rect();
    Rect(const Point & position, const Point & size);
    // getters
    Point getPosition() const;
    Point getSize() const;
    // setters
    Rect & setPosition(const Point & value);
    Rect & setSize(const Point & value);
    // sdl
    bool Empty() const;
    bool HasIntersection(const Rect & other) const;
    Rect Intersection(const Rect & other) const;
    Rect Union(const Rect & other) const;
    const SDL_Rect & ToSDL() const;
    SDL_Rect & ToSDL();
    operator SDL_Rect() const;
  };
}
