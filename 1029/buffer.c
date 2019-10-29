#include<stdio.h>
#include<stdio_ext.h>
int main(int argc,char*argv[]){
	int i,j,k,h;
	char c;
	printf("반복 횟수 입력: \n");
	scanf("%d",&i);
	for(k=0;k<i;k++){
		printf("문자와 출력 횟수 입력 : \n");
		__fpurge(stdin);
		scanf("%c %d",&c,&j);
		printf("당신은 %c와 %d를 입력했습니다. ",c,j);
		for(h=0;h<j;h++){
			printf("%c",c);
		}
		printf("\n");
	}
}
