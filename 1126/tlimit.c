#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<wait.h>
int pid;
void alarmHandler();

int main(int argc, char *argv[])
{
	int child,status,limit;
	signal(SIGALRM, alarmHandler);
	sscanf(argv[1], "%d", &limit);
	alarm(limit);
	pid = fork();
	if( pid == 0 )
	{
		execvp(argv[2], &argv[2]);
		fprintf(stderr, "%s: 실행 불가\n",argv[1]);
	}
	else
	{
		child = wait(&status);
		printf("[%d] 자식 프로세스 %d 종료 \n",getpid(),pid);
	}
}
void alarmHandler()
{
	printf("[알람] 자식 프로게스 %d 시간 초과\n",pid);
	kill(pid,SIGINT);
}

