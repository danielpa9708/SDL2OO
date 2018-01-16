#pragma once

#include <SDL2/SDL_timer.h>

namespace SDL2OO {
  class Timer {
    Uint32 last;
    Uint32 time;
    Uint32 timeout;
  public:
    static Uint32 getTime();
    static void delay(Uint32 time);
    void setTimeout(Uint32 timeout);
    void reset();
    void click();
    Sint32 left() const;
    Sint32 right() const;
    bool done() const;
  };
}
