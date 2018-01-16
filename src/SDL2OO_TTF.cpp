#include "SDL2OO_TTF.hpp"
#include <SDL2/SDL_ttf.h>

namespace SDL2OO {
  TTF * TTF::_instance = 0;

  TTF & TTF::instance() {
    return *_instance;
  }

  TTF::TTF() {
    _instance = this;
    if(!TTF_WasInit()) {
      if(TTF_Init() < 0) {
        throw TTF_GetError();
      }
    } else {
      throw "TTF initialized more than once";
    }
  }

  TTF::~TTF() {
    if(TTF_WasInit()) {
      TTF_Quit();
    } else {
      throw "TTF has not been initialized, or has already been closed";
    }
  }
}
