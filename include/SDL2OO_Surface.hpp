#pragma once

class SDL_Surface;

namespace SDL2OO {
  class Point;
  class Rect;
  union Color;
  class Surface {
    SDL_Surface * surface_;
    bool created_;
    Surface(SDL_Surface * surface, bool created = true);
    void destroy();
  public:
    static Surface loadBMP(const char * path);
    static Surface load(const char * path);
    Surface();
    Surface(Surface & surface);
    Surface(const Surface & surface);
    ~Surface();
    Surface & operator = (Surface & surface);
    Surface & operator = (const Surface & surface);
    Point getSize() const;
    Rect getRect() const;
    void fillRect(const Rect & rect, const Color & color);
    void fill(const Color & color);
    void blit(const Rect & source,
              Surface & other,
              const Point & destination);
    void blitScaled(const Rect & source,
                    Surface & other,
                    Rect destination);
    friend class Window;
    friend class Font;
  };

  extern Surface SurfaceToSpare;
}
