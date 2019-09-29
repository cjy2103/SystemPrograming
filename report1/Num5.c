#include<stdio.h>
#include<string.h>
#define BUFSIZE 512

int main(int argc, char *argv[])
{
	int countline = 0;
	int count = 0;
	int countword = 1;
	
	int state;

	char String[BUFSIZE];
	char ch;
	int i;

	FILE* fp = fopen("test3.txt","rt");
	if(fp == NULL)
	{
		printf("에러\n");
		return 0;
	}

	while(1)
	{
		if(feof(fp) != 0)
			break;

		fgets(String,BUFSIZE,fp);


	for(i = 0 ; i<strlen(String); i++)
	{
		ch =String[i];
		if(ch == ' ')
			countword++;
		else if(String[0]==' ' && String[strlen(String)]==' ')
		{
			countword--;
		}
		else
		{
			count++;
		}
	}
	countline++;
	}
	
	printf("줄 개수 : %d\n" ,countline);
	printf("문자 개수 : %d\n", count+countword-1);
	printf("단어 개수 : %d\n", countword);

	state = fclose(fp);
	if(state != 0)
	{
		printf("에러\n");
		return 0;
	}
	return 1;
}
