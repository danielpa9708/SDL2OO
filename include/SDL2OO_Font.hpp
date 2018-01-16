#pragma once

#include "SDL2OO_Color.hpp"
#include <SDL2/SDL_ttf.h>

namespace SDL2OO {
  class Surface;
  class Point;
  union Color;
  class Font {
    TTF_Font *font_;
  public:
    Font();
    Font(const char *file, int size);
    ~Font();
    // getters
    TTF_Font *get();
    int getHeight() const;
    int getStyle() const;
    int getOutline() const;
    Point getSizeText(const char * text) const;
    // setters
    void setStyle(int style);
    void setOutline(int outline);
    // render
    Surface & renderText_Solid(const char * text, Color fg = Color_Black);
    Surface & renderText_Shaded(const char * text, Color fg = Color_Black, Color bg = Color_White);
    Surface & renderText_Blended(const char * text, Color fg = Color_Black);
  };
}
