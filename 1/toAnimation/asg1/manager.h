/*************************************************************************
	> File Name: manager.h
	> Author: Maoting Ren
	> Mail: mren@g.clemson.edu
	> Created Time: Sat 06 Feb 2016 05:18:36 PM EST
 ************************************************************************/

#ifndef _MANAGER_H
#define _MANAGER_H

#include "generateFrames.h"
#include "ioManager.h"
#include "sprite.h"
#include "world.h"
#include <SDL.h>
#include <vector>

class Manager
{
public:
    Manager();
    Manager(Manager& manager);
    ~Manager();
    Manager& operator=(Manager& manager);
    void play();

private:
    void draw() const;
    bool update();

    SDL_Surface* screen;
    GenerateFrames* genFrames;

    World* world;
    std::vector<Sprite> starVec;
};
#endif
