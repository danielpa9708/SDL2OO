#include "SDL2OO_Surface.hpp"
#include "SDL2OO_Rect.hpp"
#include "SDL2OO_Color.hpp"

#include <SDL2/SDL_surface.h>
#include <iostream>
using namespace std;

namespace SDL2OO {
  Surface SurfaceToSpare;

  Surface::Surface()
    : surface_(0), created_(0) {}

  Surface::Surface(SDL_Surface * surface, bool created)
    : surface_(surface), created_(created) {}

  Surface::Surface(const Surface & surface) {
    *this = surface;
  }

  Surface::Surface(Surface & surface) {
    *this = surface;
  }

  void Surface::destroy() {
    if(surface_) {
      if(created_) {
        SDL_FreeSurface(surface_);
        surface_ = 0;
        created_ = false;
      }
    }
  }

  Surface::~Surface() {
    destroy();
  }

  Surface & Surface::operator = (Surface & surface) {
    destroy();
    surface_ = surface.surface_;
    created_ = surface.created_;
    return *this;
  }
  Surface & Surface::operator = (const Surface & surface) {
    destroy();
    surface_ = surface.surface_;
    created_ = false;
    return *this;
  }

  Point Surface::getSize() const {
    return Point(surface_->w, surface_->h);
  }

  Rect Surface::getRect() const {
    return Rect().setSize(getSize());
  }

  Surface Surface::loadBMP(const char * path) {
    Surface surface(SDL_LoadBMP(path));
    if(surface.surface_ == 0) {
      throw SDL_GetError();
    }
    return surface;
  }
  void Surface::fill(const Color & color) {
    SDL_FillRect(surface_, 0, color.fullColor);
  }
  void Surface::fillRect(const Rect & rect, const Color & color) {
    SDL_FillRect(surface_, &rect.ToSDL(), color.fullColor);
  }
  void Surface::blit(const Rect & source,
                     Surface & other,
                     const Point & destination) {
    SDL_BlitSurface(surface_, &source.ToSDL(),
                    other.surface_, &Rect().setPosition(destination).ToSDL());
  }
  void Surface::blitScaled(const Rect & source,
                           Surface & other,
                           Rect destination) {
    SDL_BlitScaled(surface_, &source.ToSDL(), other.surface_, &destination.ToSDL());
  }
}
