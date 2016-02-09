/*************************************************************************
	> File Name: manager.cpp
	> Author: Maoting Ren
	> Mail: mren@g.clemson.edu
	> Created Time: Sat 06 Feb 2016 06:01:30 PM EST
 ************************************************************************/

#include "manager.h"

Manager::Manager():screen(IoManager::getInstance().getScreen()),
    genFrames(new GenerateFrames(screen)),
    world(new World("images/sky.jpg")),
    star(new Sprite("images/comet.png", rand()%1200, 0))    
{}

Manager::~Manager()
{
    delete genFrames;
    delete world;
    delete star;
}

void Manager::draw() const
{
    world->draw();
    star->draw();
}

bool Manager::update()
{  
    static unsigned int remainder = 0u; // ***
    static unsigned int currentTicks = 0u;
    static unsigned int prevTicks = SDL_GetTicks();
    currentTicks = SDL_GetTicks();
    unsigned int elapsedTicks = currentTicks - prevTicks + remainder; 
    if( elapsedTicks < 17u) return false; 
    star->update();
    prevTicks = currentTicks;
    remainder = elapsedTicks - 17u; // ***
    return true;
}

void Manager::play()
{   
    if (SDL_Init(SDL_INIT_VIDEO) != 0) 
        throw( std::string("Unable to initialize SDL: ")+ SDL_GetError());
    atexit(SDL_Quit);

    SDL_Event event;
    bool makeVideo = false;
    bool done = false;
    GenerateFrames genFrames(screen);
    while(!done)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                done = true;
            if(event.key.keysym.sym == SDLK_ESCAPE)
                done = true;
            if (event.key.keysym.sym == SDLK_F4)
                makeVideo = true;
        }
        if(makeVideo && genFrames.getFrameCount() < 200)  
            genFrames.makeFrame();
        else if(makeVideo && genFrames.getFrameCount() >= 200)
            makeVideo = false;

        SDL_Flip(screen);
        update();
        draw();
    }
}










