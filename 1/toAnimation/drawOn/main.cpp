// Brian Malloy, Building an animation with SDL and C++
// Example of blitting one surface onto another

#include <SDL.h>
#include <iostream>
#include <string>

const int WIDTH = 854;
const int HEIGHT = 480;

void init() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    throw( std::string("Unable to initialize SDL: ")+ SDL_GetError());
  }
  atexit(SDL_Quit);
}

SDL_Surface* getImage(const std::string& filename, bool setColorKey=true) {
  SDL_Surface *temp = SDL_LoadBMP(filename.c_str());
  if (temp == NULL) {
    throw std::string("Unable to load bitmap.")+SDL_GetError();
  }
  if ( setColorKey ) {
    Uint32 colorkey = SDL_MapRGB(temp->format, 255, 0, 255);
    SDL_SetColorKey(temp, SDL_SRCCOLORKEY|SDL_RLEACCEL, colorkey);
  }
  SDL_Surface *image = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  return image;
}

void draw(SDL_Surface* image, SDL_Surface* screen, 
          Sint16 x = 0, Sint16 y = 0) {
  Uint16 w = image->w;
  Uint16 h = image->h;
  SDL_Rect src = { 0, 0, w, h };
  SDL_Rect dest = {x, y, 0, 0 };
  SDL_BlitSurface(image, &src, screen, &dest);
  SDL_Flip(screen);
}

int main() {
  try {
   init();
   SDL_Surface *screen = SDL_SetVideoMode(WIDTH, HEIGHT, 0, SDL_DOUBLEBUF);
   if (screen == NULL) {
     throw std::string("Unable to set video mode: ")+SDL_GetError();
   }

  SDL_Surface *sky = getImage("images/sky.bmp");
  SDL_Surface *star = getImage("images/greenball.bmp", true);

  draw(sky, screen);
  draw(star, screen, 300, 350);
  SDL_Event event;
  while (true) {
    if ( SDL_PollEvent(&event) ) {
      if (event.type == SDL_QUIT) break;
      if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.sym == SDLK_ESCAPE) break;
      }
    }
  }
  SDL_FreeSurface(sky);
  SDL_FreeSurface(star);
  }
  catch(const std::string& msg) { std::cout << msg << std::endl;  }
  catch(...) { std::cout << "oops" << std::endl;  }
  return 0;
}
