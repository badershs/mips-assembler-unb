#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	
	char *res1, *res2;
	int count = 1;
	int difference = 0;
	char line1[128], line2[128];	
	FILE* file1 = fopen(argv[1],"r");
	FILE* file2 = fopen(argv[2],"r");
	
	if(file1 == NULL){
		printf("Error opening file 1: %s\n",argv[1]);
		return 1;
	}
	else if(file2 == NULL){
		printf("Error opening file 2: %s\n",argv[2]);
		return 1;
	}
	else{
		while(1){
			res1 = fgets ( line1, sizeof line1, file1 );
			res2 = fgets ( line2, sizeof line2, file2 );
			
			if(res1 == NULL && res2 == NULL) break;
			
			if(res1 == NULL){
				printf("FILE 1 IS SHORTER\n");
				exit(1);
			}
			if(res2 == NULL){
				printf("FILE 2 IS SHORTER\n");
				exit(1);
			}
			
			res1 = strtok(line1,"\n\r");
			res2 = strtok(line2,"\n\r");
			if(strcmp(res1,res2) != 0){
				difference = 1;
				printf("There is a difference in line %d\n",count);
			}
			
			count++;
		}
		
		if(!difference)
			printf("FILES ARE IDENTICAL\n");
		
		fclose(file1);
		fclose(file2);
		
		return 0;
	}
}