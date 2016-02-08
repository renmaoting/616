/*************************************************************************
	> File Name: sprite.h
	> Author: Maoting Ren
	> Mail: mren@g.clemson.edu
	> Created Time: Sun 07 Feb 2016 02:29:22 AM EST
 ************************************************************************/

#ifndef _SPRITE_H
#define _SPRITE_H

#include <iostream>
#include "frame.h"

class Sprite
{
public:
    Sprite(const std::string& name, float xCor, float yCor);
    Sprite(const Sprite& sprite);
    ~Sprite(){ delete frame; }
    Sprite& operator=(const Sprite& sprite);
    void draw()const;
    void update();
    int W() { return width;}
    int H() { return height;}
    int X() { return x;}
    int Y() { return y;}

private:

    Frame *frame;
    int width;
    int height;
    float x;
    float y;
    int velocityX;
};

#endif
