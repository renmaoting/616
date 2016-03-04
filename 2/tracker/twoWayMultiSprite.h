#ifndef TWOWAYMULTISPRITE__H
#define TWOWAYMULTISPRITE__H
#include <string>
#include <vector>
#include "drawable.h"

class ExplodingSprite;
class TwoWayMultiSprite : public Drawable {
public:
  TwoWayMultiSprite(const std::string&);
  virtual ~TwoWayMultiSprite() { } 

  virtual void draw() const;
  virtual void update(Uint32 ticks);
  virtual const Frame* getFrame() const { 
    return frames[currentFrame]; 
  }
  void explode();

protected:
  ExplodingSprite* explosion;
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
  int getDistance(const TwoWayMultiSprite*) const;

  void advanceFrame(Uint32 ticks);
  TwoWayMultiSprite(const TwoWayMultiSprite&);
  TwoWayMultiSprite& operator=(const TwoWayMultiSprite&);
};
#endif
