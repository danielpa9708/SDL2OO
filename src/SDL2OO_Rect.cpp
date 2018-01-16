#include "SDL2OO_Rect.hpp"
#include <SDL2/SDL_rect.h>

namespace SDL2OO {

  Rect::Rect()
    : position(), size() {}
  Rect::Rect(const Point & position, const Point & size)
    : position(position), size(size) {}

  Point Rect::getPosition() const {
    return position;
  }
  Point Rect::getSize() const {
    return size;
  }
  Rect & Rect::setPosition(const Point & value) {
    position = value;
    return *this;
  }
  Rect & Rect::setSize(const Point & value) {
    size = value;
    return *this;
  }

  bool Rect::Empty() const {
    return size.x > 0 && size.y > 0;
  }

  bool Rect::HasIntersection(const Rect & other) const {
    return SDL_HasIntersection(&this->ToSDL(), &other.ToSDL());
  }

  Rect Rect::Intersection(const Rect & other) const {
    Rect tmp;
    SDL_IntersectRect(&this->ToSDL(), &other.ToSDL(), &tmp.ToSDL());
    return tmp;
  }

  Rect Rect::Union(const Rect & other) const {
    Rect tmp;
    SDL_UnionRect(&this->ToSDL(), &other.ToSDL(), &tmp.ToSDL());
    return tmp;
  }

  const SDL_Rect & Rect::ToSDL() const {
    return *((const SDL_Rect*)this);
  }

  SDL_Rect & Rect::ToSDL() {
    return *((SDL_Rect*)this);
  }
  Rect::operator SDL_Rect() const {
    return ToSDL();
  }
}
