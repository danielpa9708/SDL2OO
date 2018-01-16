#pragma once

#include "SDL2OO_Font.hpp"

namespace SDL2OO {
  class TTF {
    static TTF * _instance;
  public:
    TTF & instance();
    TTF();
    ~TTF();
  };
}
