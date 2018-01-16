#pragma once

#include <SDl2/SDL_events.h>

namespace SDL2OO {
  class Event {
    SDL_Event event;
  public:
    bool poll();
    void wait();
    SDL_Event &get();
  };
}
