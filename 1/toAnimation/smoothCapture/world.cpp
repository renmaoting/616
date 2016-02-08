/*************************************************************************
	> File Name: /home/ren/616/1/toAnimation/smoothCapture/world.c
	> Author: Maoting Ren
	> Mail: mren@g.clemson.edu
	> Created Time: Sun 07 Feb 2016 01:13:36 PM EST
 ************************************************************************/

#include "world.h"

World::~World()
{
    delete frame;
}

World::World(const std::string& name):
    frame(new Frame(name)),
    width(1000),
    height(800)
{}

void  World::draw()const
{
    frame->draw(0, 0);
}

