#pragma once

#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_video.h>
#include <GL/GLU.h>

namespace SDL2OO {
  class Window;
  class GL {
  public:
    GL(int majorVersion = 2, int minorVersion = 1);
    static void setAttribute(SDL_GLattr attribute, int value);
    static void setVersion(int majorVersion, int minorVersion);
    static void setSwapInterval(int interval = 1);
    static void swap(Window &window);
  };

  class GLContext {
    SDL_GLContext context;
  public:
    GLContext(Window &window);
  };
}
