#include "SDL2OO_Window.hpp"
#include "SDL2OO_Point.hpp"

#include <SDL2/SDL_video.h>
#include <SDL2/SDL_events.h>

namespace SDL2OO {
  Window::Window(Uint32 flags) {
    window = SDL_CreateWindow("SDL2OO Window",
                              SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              640, 480,
                              flags);
    if(window == 0) {
      throw SDL_GetError();
    }
  }

  Window::~Window() {
    if(window) {
      SDL_DestroyWindow(window);
    }
  }
  // GETTERS
  SDL_Window * Window::get() {
    return window;
  }
  Uint32 Window::getId() const {
    return SDL_GetWindowID(window);
  }
  const char * Window::getTitle() const {
    return SDL_GetWindowTitle(window);
  }
  Point Window::getPosition() const {
    Point tmp;
    SDL_GetWindowPosition(window, &tmp.x, &tmp.y);
    return tmp;
  }
  Point Window::getSize() const {
    Point tmp;
    SDL_GetWindowSize(window, &tmp.x, &tmp.y);
    return tmp;
  }
  Point Window::getMinimumSize() const {
    Point tmp;
    SDL_GetWindowMinimumSize(window, &tmp.x, &tmp.y);
    return tmp;
  }
  Point Window::getMaximumSize() const {
    Point tmp;
    SDL_GetWindowMaximumSize(window, &tmp.x, &tmp.y);
    return tmp;
  }

  Surface & Window::getSurface() {
    SurfaceToSpare = Surface(SDL_GetWindowSurface(window), false);
    return SurfaceToSpare;
  }

  void Window::updateSurface() {
    SDL_UpdateWindowSurface(window);
  }

  // SETTERS
  void Window::setTitle(const char * name) {
    SDL_SetWindowTitle(window, name);
  }
  void Window::setPosition(Point point) {
    SDL_SetWindowPosition(window, point.x, point.y);
  }
  void Window::setSize(Point point) {
    SDL_SetWindowSize(window, point.x, point.y);
  }
  void Window::setMinimumSize(Point point) {
    SDL_SetWindowMinimumSize(window, point.x, point.y);
  }
  void Window::setMaximumSize(Point point) {
    SDL_SetWindowMaximumSize(window, point.x, point.y);
  }
  // Flags Modifier
  void Window::show() {
    SDL_ShowWindow(window);
  }
  void Window::hide() {
    SDL_HideWindow(window);
  }
  void Window::raise() {
    SDL_RaiseWindow(window);
  }
  // Operators
  Window & Window::operator = (const Window & window) {
    throw "Equal operator not available on Windows";
  }

}
