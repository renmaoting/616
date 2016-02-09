/*************************************************************************
	> File Name: sprite.c
	> Author: Maoting Ren
	> Mail: mren@g.clemson.edu
	> Created Time: Sun 07 Feb 2016 04:58:47 AM EST
 ************************************************************************/

#include "ioManager.h"
#include "sprite.h"

Sprite::Sprite(const std::string& name, float xCor, float yCor):
    frame(new Frame(name)),
    width(frame->getWidth()),
    height(frame->getHeight()),
    x(xCor), y(yCor),
    velocityX(300)
{}

void Sprite::draw() const
{
    frame->draw(x, y);
}

void Sprite::update()
{
    float incr = velocityX * 17u * 0.001; 
    x -= incr;
    y += incr*0.5;
}


