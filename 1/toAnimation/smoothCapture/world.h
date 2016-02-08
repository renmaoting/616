/*************************************************************************
	> File Name: world.h
	> Author: Maoting Ren
	> Mail: mren@g.clemson.edu
	> Created Time: Sun 07 Feb 2016 01:11:31 PM EST
 ************************************************************************/

#ifndef _WORLD_H
#define _WORLD_H

#include <iostream>
#include "ioManager.h" 
#include "frame.h" 

class World
{
public:
    World(const std::string& name);
    int   getWidth() { return width;}
    int   getHeight() { return height;}
    void  draw()const;
    ~World();

private:
    Frame* frame;
    const  int   width;
    const  int   height;

    World(const World&);
    World& operator=(World&);

};
#endif
