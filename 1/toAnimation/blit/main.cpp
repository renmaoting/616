// Brian Malloy, Blitting with SDL and C++

#include <SDL.h>
#include <iostream>
#include <string>

const int WIDTH = 256;
const int HEIGHT = 256;

void init() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    throw( std::string("Unable to initialize SDL: ")+ SDL_GetError());
  }
  atexit(SDL_Quit);
}

// int SDL_BlitSurface(SDL_Surface*    src, const SDL_Rect* srcrect,
//                     SDL_Surface*    dst, SDL_Rect*       dstrect)
// Returns 0 if the blit is successful or a negative error code on failure;
// call SDL_GetError() for more information.
// Notes:
// The blit function should not be called on a locked surface.
// The width and height in srcrect determine the size of the copied 
// rectangle. Only the position is used in the dstrect (the width and 
// height are ignored). Blits with negative dstrect coordinates will be 
// clipped properly.

// If srcrect is NULL, the entire surface is copied. If dstrect is NULL, 
// then the destination position (upper left corner) is (0, 0).
// The final blit rectangle is saved in dstrect after all clipping is 
// performed (srcrect is not modified).
void blit(SDL_Surface* image, SDL_Surface* screen) {
  Uint16 w = image->w;
  Uint16 h = image->h;
  SDL_Rect src = { 0, 0, w, h };
  SDL_Rect dest = {0, 0, 0, 0 };
  SDL_BlitSurface(image, &src, screen, &dest);
}

int main() {
  try {
    init();
    SDL_Surface *screen = SDL_SetVideoMode(WIDTH, HEIGHT, 0, SDL_DOUBLEBUF);
    if (screen == NULL) {
      throw std::string("Unable to set video mode: ")+SDL_GetError();
    }
   SDL_Surface *temp = SDL_LoadBMP("images/diamond.bmp");
   if (temp == NULL) {
     throw std::string("Unable to load bitmap.")+SDL_GetError();
   }
   SDL_Surface *image = SDL_DisplayFormat(temp);
   SDL_FreeSurface(temp);

   blit(image, screen);
   SDL_Flip(screen);
   SDL_Event event;
   while (true) {
     if ( SDL_PollEvent(&event) ) {
       if (event.type == SDL_QUIT) break;
       if (event.type == SDL_KEYDOWN) {
         if (event.key.keysym.sym == SDLK_ESCAPE) break;
       }
     }
   }
   SDL_FreeSurface(image);
  }
  catch(const std::string& msg) { std::cout << msg << std::endl;  }
  catch(...) { std::cout << "oops" << std::endl;  }
  return 0;
}
