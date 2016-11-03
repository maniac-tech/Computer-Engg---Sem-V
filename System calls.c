#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#define MAX_COUNT 5

void ChildProcess(void);
void ParentProcess(void);

int main (void)
{
	int pid;
	pid = fork();
	if (pid==0)
		ChildProcess();
	else
		ParentProcess();
}

void ChildProcess()
{
	int i;
	for (i=1;i<=MAX_COUNT;i++)
		printf("The line is from child,value=%d \n",i );
	printf("***Child Process is done!***\n");
}


void ParentProcess()
{
	int i;
	for (i=1;i<MAX_COUNT;i++)
		printf("This line is from parent, value=%d\n",i );
	printf("***Parent is done!***\n");
}