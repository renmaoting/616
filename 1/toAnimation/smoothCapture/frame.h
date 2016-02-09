/*************************************************************************
	> File Name: frame.h
	> Author: Maoting Ren
	> Mail: mren@g.clemson.edu
	> Created Time: Sun 07 Feb 2016 01:25:45 PM EST
 ************************************************************************/

#ifndef _FRAME_H
#define _FRAME_H

#include <SDL.h>

class Frame
{
public:
    Frame( const std::string& name);
    ~Frame();
    Frame& operator=(const Frame& frame);
    Frame(const Frame&);
    int getWidth()  const { return width; }
    int getHeight() const { return height; }
    void draw(int x, int y);

private:
    SDL_Surface*    screen;
    SDL_Surface*    surface;
    int             width;
    int             height;

    Frame();
};
#endif
