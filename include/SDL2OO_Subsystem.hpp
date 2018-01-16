#pragma once

#include <SDL2/SDL_stdinc.h>

namespace SDL2OO {
  class SubSystem {
    static unsigned times;
    Uint32 flags;
  public:
    static void InitSubSystem(Uint32 flags);
    static void QuitSubSystem(Uint32 flags);
    SubSystem(Uint32 flags = 0);
    ~SubSystem();
    void init(Uint32 flags);
  };

  template<Uint32 flags>
  class TSubSystem {
  public:
    TSubSystem() {
      SubSystem::InitSubSystem(flags);
    }
    ~TSubSystem() {
      SubSystem::QuitSubSystem(flags);
    }
  };
}
