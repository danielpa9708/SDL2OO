#pragma once

#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_pixels.h>

namespace SDL2OO {
  union Color {
  public:
    SDL_Color sdlColor;
    Uint32 fullColor;
    Color(const SDL_Color & color);
    Color(const Uint32 & color = 0);
    operator SDL_Color() const;
    operator Uint32() const;
  };

  const Color Color_Black = 0xFF000000;
  const Color Color_White = 0xFFFFFFFF;
  const Color Color_Red   = 0xFF0000FF;
  const Color Color_Green = 0xFF00FF00;
  const Color Color_Blue  = 0xFFFF0000;
}
