/******************************************************************************
* The motivator is aware of sensory input (via another class?) and uses that 
* that information to choose the best behavior.
*/

#ifndef __MOTIVATOR_H__
#define __MOTIVATOR_H__
#define __MOTIVATOR_H__DEBUG 0
#define M_BEHAVIORS 8

#include <Arduino.h>
#include "Behavior.h"

class Motivator
{
  private:
	 
  
  protected:
    int behaviorCount;
    Behavior* behaviors[M_BEHAVIORS];
    void enableBehavior(int b);
    void disableBehavior(int b);
    void addBehavior(Behavior* b);
    void executeBehaviors();

  public:
    Motivator();
    virtual ~Motivator();

    virtual void motivate() =0;
};

#endif