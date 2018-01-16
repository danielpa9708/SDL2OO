#include "SDL2OO_Event.hpp"

namespace SDL2OO {
  bool Event::poll() {
    return SDL_PollEvent(&event);
  }

  void Event::wait() {
    if(SDL_WaitEvent(&event) == 0) {
      throw SDL_GetError();
    }
  }

  SDL_Event &Event::get() {
    return event;
  }
}
