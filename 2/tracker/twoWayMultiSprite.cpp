#include "twoWayMultiSprite.h"
#include <cmath>
#include <vector>
#include "ioManager.h"
#include "extractSurface.h"
#include "frameFactory.h"
#include "gamedata.h"
#include <stdlib.h> 
#include "explodingSprite.h"

void TwoWayMultiSprite::advanceFrame(Uint32 ticks) {
	timeSinceLastFrame += ticks;
	if (timeSinceLastFrame > frameInterval) {
        if(right == false)
            currentFrame = (currentFrame+1) % (numberOfFrames/2);
        else
            currentFrame = (currentFrame+1) % (numberOfFrames/2) + numberOfFrames/2;
        timeSinceLastFrame = 0;
	}
}

TwoWayMultiSprite::TwoWayMultiSprite( const std::string& name) :
  Drawable(name, 
           Vector2f(Gamedata::getInstance().getXmlInt(name+"/startLoc/x") , 
                    Gamedata::getInstance().getXmlInt(name+"/startLoc/y") ), 
           Vector2f(Gamedata::getInstance().getXmlInt(name+"/speedX") ,
                    Gamedata::getInstance().getXmlInt(name+"/speedY") )
           ),
  explosion(NULL),
  frames( FrameFactory::getInstance().getFrames2(name)),
  starFrames(),
  frameName(name),
  worldWidth(Gamedata::getInstance().getXmlInt("world/width")),
  worldHeight(Gamedata::getInstance().getXmlInt("world/height")),
  right(velocityX()>0),

  currentFrame(0),
  numberOfFrames( Gamedata::getInstance().getXmlInt(name+"/frames") ),
  frameInterval( Gamedata::getInstance().getXmlInt(name+"/frameInterval") ),
  timeSinceLastFrame( 0 ),
  frameWidth(frames[0]->getWidth()),
  frameHeight(frames[0]->getHeight())
{ 
}

void TwoWayMultiSprite::explode() { 
  if ( explosion ) return;
  Sprite sprite(getName(), getPosition(), getVelocity(), getFrame());
  explosion = new ExplodingSprite(sprite); 
}

void TwoWayMultiSprite::draw() const { 
  if (explosion) {
    explosion->draw();
    return;
  }

  Uint32 x = static_cast<Uint32>(X());
  Uint32 y = static_cast<Uint32>(Y());
  frames[currentFrame]->draw(x, y);
}

void TwoWayMultiSprite::update(Uint32 ticks) { 
  if ( explosion ) {
    explosion->update(ticks);
    if ( explosion->chunkCount() == 0 ) {
      delete explosion;
      explosion = NULL;
    }
    return;
  }

  advanceFrame(ticks);
  Vector2f incr = getVelocity() * static_cast<float>(ticks) * 0.001;
  setPosition(getPosition() + incr);
  if ( Y() <= 0) {
    velocityY( abs( velocityY() ) );
  }
  if ( Y() >= worldHeight-frameHeight) {
    velocityY( -abs( velocityY() ) );
  }

  if ( X() <= 0) {
    velocityX( abs( velocityX() ) );
    right = true;
  }
  if ( X() >= worldWidth-frameWidth) {
    velocityX( -abs( velocityX() ) );
    right = false;
  }  
}

int TwoWayMultiSprite::getDistance(const TwoWayMultiSprite *obj) const { 
  return hypot(X()-obj->X(), Y()-obj->Y());
}
