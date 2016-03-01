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
    int W()const { return width;}
    int H()const { return height;}
    int X()const { return x;}
    int Y()const { return y;}
    void X(int val) { x = val;}
    void Y(int val) { y = val;}
    int getVelocityX()const { return velocityX;}
    int getVelocityY()const { return velocityY;}
    Frame* getFrame()const { return frame;}
    std::string getName()const { return fName;}

private:
    std::string fName;
    Frame*  frame;
    int     width;
    int     height;
    float   x;
    float   y;
    int     velocityX;
    int     velocityY;
};
#endif
