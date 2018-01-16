#include "SDL2OO_OpenGL.hpp"
#include "SDL2OO_Window.hpp"

namespace SDL2OO {
  GL::GL(int majorVersion, int minorVersion) {
    setVersion(majorVersion, minorVersion);
  }

  void GL::setVersion(int majorVersion, int minorVersion) {
    setAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, majorVersion);
    setAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minorVersion);
  }
  void GL::setAttribute(SDL_GLattr attribute, int value) {
    SDL_GL_SetAttribute(attribute, value);
  }
  void GL::setSwapInterval(int interval) {
    if(SDL_GL_SetSwapInterval(interval) < 0) {
      throw SDL_GetError();
    }
  }

  void GL::swap(Window &window) {
    SDL_GL_SwapWindow(window.get());
  }

  GLContext::GLContext(Window &window) {
    context = SDL_GL_CreateContext(window.get());
    if(context == 0) {
      throw SDL_GetError();
    }
  }
}
