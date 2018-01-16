#include "SDL2OO_Timer.hpp"

namespace SDL2OO {
  Uint32 Timer::getTime() {
    return SDL_GetTicks();
  }

  void Timer::delay(Uint32 time) {
    SDL_Delay(time);
  }

  void Timer::setTimeout(Uint32 timeout) {
    this->timeout = timeout;
  }

  void Timer::reset() {
    time = getTime();
    last = time;
    click();
  }

  void Timer::click() {
    time += timeout;
  }

  Sint32 Timer::left() const {
    return getTime() - time;
  }

  Sint32 Timer::right() const {
    return getTime() - last;
  }

  bool Timer::done() const {
    return left() <= 0;
  }
}
