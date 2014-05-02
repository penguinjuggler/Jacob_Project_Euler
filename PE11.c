/*
Project Euler
Problem 11 - find largest product 4 nums in a line
Jacob Mintz
*/

#include <stdio.h>
int getGrid(void);

int main(void)
{
	int NROWS = 20;
	int NCOLS = 20;
	int LINE  = 4;
	int largeProd = 1;
	int prod;
	//int *nums = getGrid();
	int *a;
	int i, f, g; 
	
	int nums[20][20];
	FILE *fptr; //pointer to file 
	fptr = fopen("Jacob_Project_Euler\\P11Grid.txt","r");
	if(fptr == NULL){
		printf("Error!");
		exit(1);
	}
	
	for(int i=0; i<20; i++){
		for(int f=0; f<20; f++){
			fscanf(fptr,"%d", &nums[i][f]);
			printf("%4d",nums[i][f]);
		}
		printf("\n");
	}

	fclose(fptr);
	
	//Verts
	for(i=0; i<NROWS; i++){
		for(f=0; f<(NCOLS - LINE); f++){
			for(g=0; g<4;g++)
				prod *= nums[i][f+g];
			if(prod>largeProd){
				largeProd = prod;
				for(int assi = 0; assi<4; assi++){
					a[1][assi] = f+assi;
					a[0][assi] = i;
				}
			}
		}
	}
	
	//Horz
	for(i=0; i<NCOLS; i++){
		for(f=0; f<(NROWS - LINE); f++){
			for(g=0; g<4;g++)
				prod *= nums[i+g][f];
			if(prod>largeProd){
				largeProd = prod;
				for(int assi = 0; assi<4; assi++){
					a[0][assi] = i+assi;
					a[1][assi] = f;
				}
				//a[2][4] = {i,f,i+1,f,i+2,f,i+3,f};
			}
		}
	}

	//Angle Down/Right
	for(i=0; i<(NROWS-LINE); i++){
		for(f=0; f<(NROWS - LINE); f++){
			for(g=0; g<4;g++)
				prod *= nums[i+g][f+g];
			if(prod>largeProd){
				largeProd = prod;
				//a[2][4] = {i,f,i+1,f,i+2,f,i+3,f};
				for(int assi = 0; assi<4; assi++){
					a[1][assi] = f+assi;
					a[0][assi] = i+assi;
				}
			}
		}
	}

	//Angle Down/Left
	for(i=LINE-1; i<NROWS; i++){
		for(f=LINE-1; f<NROWS; f++){
			for(g=0; g<4;g++)
				prod *= nums[i-g][f-g];
			if(prod>largeProd){
				largeProd = prod;
				for(int assi = 0; assi<4; assi++){
					a[1][assi] = f-assi;
					a[0][assi] = i-assi;
				}
				//a[2][4] = {i,f,i+1,f,i+2,f,i+3,f};
			}
		}
	}
	
	printf("At %d, %d the largest product is: %d",a[0][0],a[1][0],largeProd);
	
	
	for(i=0; i<3;i++){
		for(f=0; f<3; f++)
			printf("%d",nums[i][f]);
		printf("\n");
	}
return 0;
}

/*
int getGrid(void){

int nums[20][20];
	FILE *fptr; //pointer to file 
	fptr = fopen("Jacob_Project_Euler\\P11Grid.txt","r");
	if(fptr == NULL){
		printf("Error!");
		exit(1);
	}
	
	for(int i=0; i<20; i++){
		for(int f=0; f<20; f++){
			fscanf(fptr,"%d", &nums[i][f]);
			printf("%4d",nums[i][f]);
		}
		printf("\n");
	}

	fclose(fptr);
	
	return *nums;

}
*/

