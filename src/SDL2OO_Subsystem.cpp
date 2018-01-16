#include "SDL2OO_SubSystem.hpp"

#include <SDL2/SDL.h>

namespace SDL2OO {

  unsigned SubSystem::times = 0;

  void SubSystem::InitSubSystem(Uint32 flags) {
    if(times == 0) {
      SDL_Init(0);
    }
    times++;
    if(SDL_InitSubSystem(flags) < 0) {
      throw SDL_GetError();
    }
  }

  void SubSystem::QuitSubSystem(Uint32 flags) {
    times--;
    if(times == 0) {
      SDL_Quit();
    }
    SDL_QuitSubSystem(flags);
  }

  SubSystem::SubSystem(Uint32 flags)
    : flags(0) {
    init(flags);
  }

  SubSystem::~SubSystem() {
    QuitSubSystem(flags);
  }

  void SubSystem::init(Uint32 flags) {
    InitSubSystem(flags);
    this->flags |= flags;
  }
}
