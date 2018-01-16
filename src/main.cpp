#include "SDL2OO.hpp"
#include "SDL2OO_Image.hpp"
#include "SDL2OO_TTF.hpp"
#include "SDL2OO_UI.hpp"
#include <cstdio>
#include <iostream>
using namespace std;
using namespace SDL2OO;
using namespace SDL2OO::UI;

class App {
  SubSystem sdl;
  IMG img;
  TTF ttf;
  Window window;
  Color bgColor;
  Font font;
public:
  App();
  ~App();
  void draw();
};

void loop(App &app);

int main(int argc, char **args) {
  try {
    App app;
    loop(app);
  } catch(const char * error) {
    puts(error);
  }
  return 0;
}

void loop(App & app) {
  bool quit = false;
  Event event;
  while(!quit) {
    event.wait();
    switch(event.get().type) {
    case SDL_QUIT:
      quit = true;
      break;
    }
    app.draw();
  }
}

App::App()
  : sdl(SDL_INIT_VIDEO),
    img(IMG_INIT_PNG),
    font("ttf/arial.ttf", 28),
    window() {
  window.setTitle("Hello There");
  bgColor = Color_White;
}

App::~App() {
}

void App::draw() {
  window.getSurface().fill(bgColor);
  Surface surface = font.renderText_Solid("Hello There", Color_Black);
  surface.blit(Rect(Point(0, 0), Point(32, 32)), window.getSurface(), Point(0, 0));
  window.updateSurface();
}
