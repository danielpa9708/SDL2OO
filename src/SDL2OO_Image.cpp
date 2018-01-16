#include "SDL2OO_Image.hpp"
#include "SDL2OO_Surface.hpp"

#include <SDL2/SDL_image.h>

namespace SDL2OO {


  IMG * IMG::_instance = 0;

  IMG::IMG(Uint32 flags) {
    _instance = this;
    if(IMG_Init(flags) < 0) {
      throw IMG_GetError();
    }
  }

  IMG::~IMG() {
    IMG_Quit();
  }

  IMG & IMG::instance() {
    return *_instance;
  }

  // Surface addon
  Surface Surface::load(const char *path) {
    SurfaceToSpare = IMG_Load(path);
    if(SurfaceToSpare.surface_ == 0) {
      throw IMG_GetError();
    }
    return SurfaceToSpare;
  }
}
