/*
Project Euler
Problem 13 - First ten digits of the sum of the following one hundred 50 digit numbers
Jacob Mintz
*/

#include <stdio.h>

int main(void)
{
	char chars[100][51];
	int nums[100][50];
	FILE *fptr; //pointer to file 
	fptr = fopen("Jacob_Project_Euler\\P13Grid.txt","r");
	if(fptr == NULL){
		printf("Error!");
		exit(1);
	}
	
	for(int i=0; i<100; i++){
		for(int f=0; f<51; f++){
			fscanf(fptr,"%c", &chars[i][f]);
			//Read in and skip Null Return Line
			if(f!=50){
				nums[i][f] = (int) chars[i][f] - '0';
				//printf("%d",nums[i][f]);
			}	
		}
		//printf("\n");
	}
	fclose(fptr);
	

	
	int ans[100];
	int currentSum;
	int addover = 0;
	int c=0;
	for(; c<50; c++){
		currentSum = addover;
		for(int j=0; j<100; j++){
			currentSum += nums[j][49-c];
		}
		addover = (int) currentSum/10;
		ans[c] = currentSum%10;
	}
	
	printf("\n\n\t%d ",addover);
	for(int i=1; i<10; printf("%d",ans[c-i]),i++);

}