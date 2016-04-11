/*************************************************************************
	> File Name: hero.h
	> Author: Maoting Ren
	> Mail: mren@g.clemson.edu
	> Created Time: Fri 04 Mar 2016 05:23:21 AM EST
 ************************************************************************/

#ifndef _HERO_H
#define _HERO_H

#include <string>
#include <vector>
#include "drawable.h"
#include "multisprite.h"

class ExplodingSprite;
class Hero : public Drawable {
public:
  Hero(const std::string&);
  virtual ~Hero();

  virtual void draw() const;
  virtual void update(Uint32 ticks);
  virtual const Frame* getFrame() const { 
    return frames[currentFrame]; 
  }
  void explode();
  void addSpecialEffect(MultiSprite* sprite);

protected:
  ExplodingSprite* explosion;
  MultiSprite* special;
  const std::vector<Frame *> frames;
  std::vector<Frame*> starFrames;
  std::string frameName;
  int worldWidth;
  int worldHeight;
  bool right;

  unsigned currentFrame;
  unsigned numberOfFrames;
  unsigned frameInterval;
  float timeSinceLastFrame;
  int frameWidth;
  int frameHeight;
  int getDistance(const Hero*) const;

  void advanceFrame(Uint32 ticks);
  Hero(const Hero&);
  Hero& operator=(const Hero&);
};
#endif
