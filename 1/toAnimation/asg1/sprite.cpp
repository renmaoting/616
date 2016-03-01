/*************************************************************************
	> File Name: sprite.c
	> Author: Maoting Ren
	> Mail: mren@g.clemson.edu
	> Created Time: Sun 07 Feb 2016 04:58:47 AM EST
 ************************************************************************/

#include "ioManager.h"
#include "sprite.h"
#include <math.h> 

Sprite::Sprite(const std::string& name, float xCor, float yCor):
    fName(name),
    frame(new Frame(name)),
    width(frame->getWidth()),
    height(frame->getHeight()),
    x(xCor), y(yCor),
    velocityX(100),
    velocityY(100)
{}

Sprite::Sprite(const Sprite& sprite):
    fName(sprite.getName()),
    frame(new Frame(fName)),
    width(sprite.W()),
    height(sprite.H()),
    x(sprite.X()), y(sprite.Y()),
    velocityX(sprite.getVelocityX()),
    velocityY(sprite.getVelocityY())
{
    x = rand()%1000;
    y = rand()%500;
    velocityX = 100 * (rand()%100)*0.01 + 40;
    velocityY = 50*rand()%100* 0.01+100;
}

Sprite& Sprite::operator=(const Sprite& sprite)
{
    fName = sprite.fName;
    frame = new Frame(fName);
    width = sprite.W();
    height = sprite.H();
    x = sprite.X();
    y = sprite.Y();
    velocityX = sprite.getVelocityX();
    velocityY = sprite.getVelocityY();

    return *this;
}

void Sprite::draw() const
{
    frame->draw(x, y);
}

void Sprite::update()
{
    float incrX = velocityX * 17u * 0.001; 
    float incrY = velocityY * 17u * 0.001; 
    x += incrX;
    y += incrY;
    if(y >= 740)
        y = rand()%500;
    if(x > 1300)
        x = rand()%200;
    if(x < 0)
        x = 1300- rand()%200;
}


