/*************************************************************************
	> File Name: ioManager.h
	> Author: Maoting Ren
	> Mail: mren@g.clemson.edu
	> Created Time: Sun 07 Feb 2016 03:26:13 AM EST
 ************************************************************************/

#ifndef _IOMANAGER_H
#define _IOMANAGER_H

#include <SDL.h>
#include <iostream>

class IoManager
{
public:
    static IoManager& getInstance();
    SDL_Surface* getScreen(){ return screen;}
    SDL_Surface* loadImage(const std::string& filename, bool setColorKey);

private:
    IoManager();
    SDL_Surface* screen;

    IoManager(IoManager&);
    IoManager& operator=(IoManager&);
    ~IoManager();
};
#endif
