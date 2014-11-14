#include "Motivator.h"

Motivator::Motivator()
{
	behaviorCount = 0;
}

Motivator::~Motivator() {}

void Motivator::enableBehavior(int b)
{
#if __MOTIVATOR_H__DEBUG
	Serial.print("Motivator.enableBehavior(" + (String)b + ") ");
#endif
	behaviors[b]->enable();
}

void Motivator::disableBehavior(int b)
{
#if __MOTIVATOR_H__DEBUG
	Serial.print("Motivator.disableBehavior(" + (String)b + ") ");
#endif
	behaviors[b]->disable();
}

void Motivator::executeBehaviors()
{
#if __MOTIVATOR_H__DEBUG
	Serial.println("Motivator.executeBehaviors() BC: " + (String)behaviorCount);
#endif
	for (int x = 0; x < behaviorCount; x++)	
	{
		if (behaviors[x]->getEnabled())
		{
#if __MOTIVATOR_H__DEBUG
			Serial.println("b" + (String)x + "ee ");
#endif
			behaviors[x]->execute();
		}
		else
		{
#if __MOTIVATOR_H__DEBUG
			Serial.println("b" + (String)x + "dn ");
#endif
		}
	}
}

void Motivator::addBehavior(Behavior* b)
{
  behaviors[behaviorCount] = b;
  behaviorCount++;
}
