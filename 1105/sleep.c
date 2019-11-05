#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc,char*argv[])
{
	int i;
	printf("Hello\n");
	i= atoi(argv[1]);
	sleep(i);
	printf("Bye\n");
}	
