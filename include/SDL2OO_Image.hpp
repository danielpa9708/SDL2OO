#pragma once

#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_image.h>

namespace SDL2OO {
  class IMG {
    static IMG * _instance;
  public:
    static IMG & instance();
    IMG(Uint32 flags = 0);
    ~IMG();
  };
}
