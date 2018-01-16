#include "SDL2OO_Font.hpp"
#include "SDL2OO_Point.hpp"
#include "SDL2OO_Surface.hpp"

namespace SDL2OO {
  Font::Font() {
    font_ = 0;
  }
  Font::Font(const char *file, int size) {
    font_ = TTF_OpenFont(file, size);
    if(font_ == 0) {
      throw TTF_GetError();
    }
  }

  Font::~Font() {
    if(font_) {
      TTF_CloseFont(font_);
    }
  }

  // getters
  TTF_Font *Font::get() {
    return font_;
  }
  int Font::getHeight() const {
    return TTF_FontHeight(font_);
  }
  int Font::getStyle() const {
    return TTF_GetFontStyle(font_);
  }
  int Font::getOutline() const {
    return TTF_GetFontOutline(font_);
  }
  Point Font::getSizeText(const char * text) const {
    Point tmp;
    TTF_SizeText(font_, text, &tmp.x, &tmp.y);
    return tmp;
  }
  // setters
  void Font::setStyle(int style) {
    return TTF_SetFontStyle(font_, style);
  }
  void Font::setOutline(int outline) {
    return TTF_SetFontOutline(font_, outline);
  }
  Surface &Font::renderText_Solid(const char * text, Color fg) {
    SDL_Surface * surface = TTF_RenderText_Solid(font_, text, fg);
    if(surface == 0) {
      throw TTF_GetError();
    }
    SurfaceToSpare = Surface(surface, true);
    return SurfaceToSpare;
  }
  Surface &Font::renderText_Shaded(const char * text, Color fg, Color bg) {
    SDL_Surface * surface = TTF_RenderText_Shaded(font_, text, fg, bg);
    if(surface == 0) {
      throw TTF_GetError();
    }
    SurfaceToSpare = Surface(surface, true);
    return SurfaceToSpare;
  }
  Surface &Font::renderText_Blended(const char * text, Color fg) {
    SDL_Surface * surface = TTF_RenderText_Blended(font_, text, fg);
    if(surface == 0) {
      throw TTF_GetError();
    }
    SurfaceToSpare = Surface(surface, true);
    return SurfaceToSpare;
  }
}
