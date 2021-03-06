#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "spinlock.h"

int
sys_yield(void)
{
    
    //Reset Process
    #ifdef MLFQ_SCHED
        struct proc *p = myproc();
        p->level = 0;
        p->quantum = 0;
    #endif
        
    yield();
    return 0;
}

int
sys_getlev(void)
{
    return getlev();
}

int
sys_setpriority(void)
{
    int pid;
    int priority;

    if(argint(0, &pid) < 0)
        return -1;
    if(argint(1, &priority) < 0)
        return -2;
    return setpriority(pid, priority);
}
