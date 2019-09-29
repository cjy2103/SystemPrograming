#include <stdio.h>

int main(int argc, char* argv[]){
     FILE* fp1;
     FILE* fp2;
     int state1, state2;
     char getfp1, getfp2;
     if (argc != 3){
          printf("오류발생\n");
          return 1;
     }

     fp1 = fopen(argv[1], "rt");
     fp2 = fopen(argv[2], "rt");

     if (fp1 == NULL || fp2 == NULL){
          printf("에러\n");
          return 1;
     }
 	int count =0;
     while (1){	
	count++;
          if (feof(fp1) == 0 && feof(fp2) == 0){
               getfp1 = fgetc(fp1);
               getfp2 = fgetc(fp2);

               if (getfp1 != getfp2){
                   printf("서로다른파일\n");
                    printf("서로다른 첫번째 위치값 :%d.\n",count);	        
                    break;
               }
          }
    
          else if (feof(fp1) != 0 && feof(fp2) == 0){
            printf("서로다른파일\n");
              printf("서로다른 첫번째 위치값 :%d.\n",count);		    
               break;
          }

      
          else if (feof(fp1) == 0 && feof(fp2) != 0){
             printf("서로다른파일\n");
              printf("서로다른 첫번째 위치값 :%d.\n",count);	  
               break;
          }
      else{
               printf("같은파일\n");
               break;
          }
     }
     state1 = fclose(fp1);
     state2 = fclose(fp2);
     if (state1 != 0 || state2 != 0){
          printf("에러\n");
          return 1; 
     }
     return 0;
}


