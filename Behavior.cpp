#include "Behavior.h"

//constructor
Behavior::Behavior()
{
	conflictCount = 0;
	enabled = false;
}

Behavior::~Behavior()
{
    delete [] conflicts;
}

void Behavior::addConflict(Behavior* b)
{
	conflicts[conflictCount] = b;
	conflictCount++;
}

void Behavior::enable()
{
    if (!enabled)
    {
        for (int x = 0;x < conflictCount; x++)
        {
            conflicts[x]->disable();
        }

        enabled = true;
    }

}	

void Behavior::disable()
{
    if (enabled)
        enabled = false;
}

bool Behavior::getEnabled()
{
    return enabled;
}

void Behavior::init() {};