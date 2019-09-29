#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"

int main(int argc, char *argv[])
{
	int fd,id;
	char c;
	struct student rec;
	if(argc < 2) {
		fprintf(stderr, " 사용법 : %s file\n", argv[0]);
		exit(1);
	}

	if((fd = open(argv[1], O_RDWR)) == -1) {
		perror(argv[1]);
		exit(2);
	}
	do{	
		
		printf("삭제할 학생의 학번 입력: ");
		if(scanf("%d",&id) ==1 )
		{
			lseek(fd,(long) (id-START_ID+1) * sizeof(rec),SEEK_SET);
			if((read(fd, & rec,sizeof(rec)) > 0) &&rec.id !=0)
			{	
				rec.id = 0;
				lseek(fd,(long) -sizeof(rec),SEEK_CUR);
				write(fd,&rec,sizeof(rec));
								

			}
			else printf("레코드 %d 없음\n",id);
		}
		else printf("입력오류\n");
		printf("계속 하겠습니까?(Y/N)");
		scanf("%c", &c);
	}while(c=='Y');

	close(fd);
	exit(0);
}

