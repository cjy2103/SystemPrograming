#include<stdio.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>

main(int argc, char *argv[])
{
	long strtol();
	int newmode;
	newmode = (int) strtol(argv[1] , (char **) NULL,8);
	if(chmod(argc[2], newmode) ==-1)
	{
		perror(argv[2]);
		exit(1);
	}
	exit(0);

}
