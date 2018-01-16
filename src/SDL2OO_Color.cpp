#include "SDL2OO_Color.hpp"

namespace SDL2OO {
  Color::Color(const SDL_Color & color) {
    sdlColor = color;
  }
  Color::Color(const Uint32 & color) {
    fullColor = color;
  }
  Color::operator SDL_Color() const {
    return sdlColor;
  }
  Color::operator Uint32() const {
    return fullColor;
  }
}
