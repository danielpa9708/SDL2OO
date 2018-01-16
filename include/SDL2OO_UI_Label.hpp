#pragma once

#include "SDL2OO_Point.hpp"
#include "SDL2OO_Color.hpp"
#include "SDL2OO_Surface.hpp"

namespace SDL2OO {
  class Rect;
  namespace UI {
    class Label {
      Point position_;
      Surface surface_;
      Color bgColor_, fgColor_;
      bool drawBackground_;
      const char * text_;
    protected:
      void repaint();
    public:
      Label(const char *text = "", Point position = Point(0, 0));
      void draw(Surface & surface);
      // GETTERS
      Point getPosition() const;
      Point getSize() const;
      Rect getRect() const;
      bool isBackgroundDrawn() const;
      // SETTER
      void setPosition(Point point);
      void setText(const char *text);
      void setBackgroundDrawn(bool drawn);
    };
  }
}
