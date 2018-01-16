#include "SDL2OO_UI_Label.hpp"
#include "SDL2OO_Rect.hpp"
#include "SDL2OO_Font.hpp"

namespace SDL2OO {
  namespace UI {
    Label::Label(const char *text, Point position) {
      drawBackground_ = false;
      setText(text);
      setPosition(position);
    }

    void Label::repaint() {
      static Font font("ttf/arial.ttf", 28);
      if(drawBackground_) {
        surface_ = font.renderText_Shaded(text_, fgColor_, bgColor_);
      } else {
        surface_ = font.renderText_Solid(text_, fgColor_);
      }
    }

    void Label::draw(Surface & surface) {
      surface_.blit(surface_.getRect(), surface, position_);
    }

    // GETTERS
    Point Label::getPosition() const {
      return position_;
    }
    Point Label::getSize() const {
      return surface_.getSize();
    }
    Rect Label::getRect() const {
      return Rect(position_, surface_.getSize());
    }

    bool Label::isBackgroundDrawn() const {
      return drawBackground_;
    }

    // SETTER
    void Label::setPosition(Point point) {
      position_ = point;
    }

    void Label::setText(const char *text) {
      text_ = text;
      repaint();
    }

    void Label::setBackgroundDrawn(bool drawn) {
      drawBackground_ = drawn;
      repaint();
    }
  }
}
