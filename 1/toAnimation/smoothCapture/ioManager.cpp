/*************************************************************************
	> File Name: ioManager.cpp
	> Author: Maoting Ren
	> Mail: mren@g.clemson.edu
	> Created Time: Sun 07 Feb 2016 03:33:45 AM EST
 ************************************************************************/

#include "ioManager.h"
#include <iostream>
#include <SDL_image.h>

IoManager& IoManager::getInstance()
{
    static IoManager io;
    return io;
}
 
IoManager::~IoManager()
{
//    SDL_FreeSurface(screen);
}

SDL_Surface* IoManager::loadImage(const std::string& filename, bool setColorKey)
{
//    SDL_Surface *temp = SDL_LoadBMP(filename.c_str());
    SDL_Surface *temp = IMG_Load(filename.c_str());
    if (temp == NULL) 
        throw std::string("Unable to load bitmap.")+SDL_GetError();
    if ( setColorKey )
    {
        Uint32 colorkey = SDL_MapRGB(temp->format, 255, 0, 255);
        SDL_SetColorKey(temp, SDL_SRCCOLORKEY|SDL_RLEACCEL, colorkey);
    }
    SDL_Surface *image = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);
    return image;
}

IoManager::IoManager():
    screen(SDL_SetVideoMode(854u, 480, 0, SDL_DOUBLEBUF))//TODO
{
    if (screen == NULL) 
        throw std::string("Unable to set video mode: ")+SDL_GetError(); 
}

