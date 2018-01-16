#pragma once

#include "SDL2OO_Surface.hpp"
#include <SDl2/SDL_stdinc.h>

class SDL_Window;

namespace SDL2OO {
  class Surface;
  class Point;
  class Window {
    SDL_Window * window;
  public:
    // CONSTRUCTORS
    Window(Uint32 flags = 0);
    // DESTRUCTOR
    ~Window();
    void updateSurface();
    // GETTERS
    SDL_Window * get();
    Uint32 getId() const;
    const char * getTitle() const;
    Point getPosition() const;
    Point getSize() const;
    Point getMinimumSize() const;
    Point getMaximumSize() const;
    Surface & getSurface();
    // SETTERS
    void setTitle(const char * name);
    void setPosition(Point point);
    void setSize(Point point);
    void setMinimumSize(Point point);
    void setMaximumSize(Point point);
    // Flags Modifier
    void show();
    void hide();
    void raise();
    // Operators
    Window & operator = (const Window & window);

    friend class SubSystem;
  };
}
