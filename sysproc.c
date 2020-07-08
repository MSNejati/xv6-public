#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}


// Implement new system call named "procInfo" here
int
sys_procInfo(void) 
{
  struct proc_info *plist;
    if(argptr(0, (void*)&plist, sizeof(*plist)) < 0)
        return -1;
    getProcess(plist);      // I use this function to find and sort running or runnable processes. I defined this function in proc.c file.
    return 0;
}


// Implement new system call named "waitx" here.
int
sys_waitx(void) 
{
  int *wtime;
  int *rtime;
  
  if(argptr(0, (char**)&wtime, sizeof(int)) < 0)
    return -1;

  if(argptr(1, (char**)&rtime, sizeof(int)) < 0)
    return -1;

  return waitx(wtime, rtime);     // It passes the parameters "rtime", "wtime" to the "waitx()" in proc.c
}

int
sys_cps(void)
{
  return cps();
}

// Implement new system call named "setp" here.
int
sys_setp(void)
{
    int pid, priority;
    if(argint(0, &pid) < 0)
        return -1;
    if(argint(1, &priority) < 0)
        return -1;

    return setp(pid, priority);
}
