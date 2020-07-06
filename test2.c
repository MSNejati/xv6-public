#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

int main (int argc,char *argv[])
{

	int pid;
	int status;
	float waitTime, runTime;	
	pid = fork();
	if (pid == 0)
  	{	
  		exec(argv[1], argv);
    	printf(1, "exec %s failed\n", argv[1]);
    }
  	else
 	{
    	status = waitx(&waitTime, &runTime);
 	}  
 	printf(1, "Wait Time = %d\n Run Time = %d with Status %d \n", waitTime, runTime, status); 
 	exit();
}