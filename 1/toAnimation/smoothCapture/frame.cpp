/*************************************************************************
	> File Name: frame.cpp
	> Author: Maoting Ren
	> Mail: mren@g.clemson.edu
	> Created Time: Sun 07 Feb 2016 01:50:38 PM EST
 ************************************************************************/

#include<iostream>
#include "frame.h"
#include "ioManager.h"
using namespace std;

Frame::~Frame()
{
   SDL_FreeSurface(surface);
}

Frame::Frame(const std::string& name):
    screen(IoManager::getInstance().getScreen()),
    surface(IoManager::getInstance().loadImage(name, true)), 
    width(surface->w), 
    height(surface->h)
{}

void Frame::draw(int x, int y)
{
    SDL_Rect src = {0, 0, static_cast<Uint16>(width), static_cast<Uint16>(height) };    
    SDL_Rect dest= {static_cast<Sint16>(x), static_cast<Sint16>(y), 0, 0};    
    SDL_BlitSurface(surface, &src, screen, &dest);
}
