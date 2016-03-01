#include <SDL.h>
#include <string>
#include <deque>

class Manager;

class Clock {
public:
  static Clock& getInstance();
  unsigned int getTicks() const;
  unsigned int getTotalTicks() const { return sumOfAllTicks-pausedSpan; }
  void pause(){ paused = true; pausedTime = currTicks;}
  void unPause(){ paused = false; pausedSpan += (getTicks()-pausedTime);}
  inline bool isPaused(){ return paused;}

private:
  friend class Manager;

  bool paused;
  int pausedTime;
  int pausedSpan;
  bool started;
  bool sloMo;
  const bool framesAreCapped;
  const int frameCap;

  unsigned int frames;
  std::deque<int> recentFrames;
  const unsigned int maxFramesToAvg;

  unsigned int tickSum;
  unsigned int sumOfAllTicks;
  unsigned int timeAtStart;
  unsigned int currTicks;
  unsigned int prevTicks;
  unsigned int ticks;

  unsigned int getElapsedTicks();
  Clock& operator++();
  void toggleSloMo();

  bool isStarted() const { return started; }
  unsigned int getFrames() const  { return frames;  }
  unsigned int getSeconds() const { return sumOfAllTicks/1000;  }
  unsigned int capFrameRate() const;
  int getFps() const;
  int getAvgFps() const;

  void start();
  void display() const;

  Clock();
  Clock(const Clock&);
  Clock&operator=(const Clock&);
};
