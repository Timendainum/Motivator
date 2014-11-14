#ifndef __BEHAVIOR_H__
#define __BEHAVIOR_H__
#define __BEHAVIOR_H__DEBUG 0
#define M_CONFLICTS 4

class Behavior
{
private:
	int conflictCount;
    bool enabled;
    Behavior* conflicts[M_CONFLICTS];

protected:

public:
    Behavior();
    virtual ~Behavior();
    void addConflict(Behavior* b);
    void enable();
    virtual void disable();
    bool getEnabled();
    virtual void init();
    virtual void execute() =0;
};

#endif
