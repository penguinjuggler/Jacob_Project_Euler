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
	int a[2][4];
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
			for(g=0, prod=1; g<4;g++)
				prod *= nums[i][f+g];
			if(prod>largeProd){
				largeProd = prod;
				for(int assi=0; assi<4; assi++){
					a[0][assi] = i;
					a[1][assi] = f+assi;
				}
			}
		}
	}
	
	//Horz
	for(i=0; i<(NROWS-LINE); i++){
		for(f=0; f<NCOLS; f++){
			for(g=0,prod=1; g<4;g++)
				prod *= nums[i+g][f];
			if(prod>largeProd){
				largeProd = prod;
				for(int assi = 0; assi<4; assi++){
					a[0][assi] = i+assi;
					a[1][assi] = f;
				}
			}
		}
	}

	//Angle Down/Right
	for(i=0; i<(NROWS-LINE); i++){
		for(f=0; f<(NCOLS-LINE); f++){
			for(g=0, prod=1; g<4;g++)
				prod *= nums[i+g][f+g];
			if(prod>largeProd){
				largeProd = prod;
				for(int assi = 0; assi<4; assi++){
					a[0][assi] = i+assi;
					a[1][assi] = f+assi;
				}
			}
		}
	}

	//Angle Down/Left
	for(i=1; i<(NROWS-LINE); i++){
		for(f=LINE-1; f<NCOLS; f++){
			for(g=0, prod=1; g<4;g++)
				prod *= nums[i+g][f-g];
			if(prod>largeProd){
				largeProd = prod;
				for(int assi = 0; assi<4; assi++){
					a[0][assi] = i+assi;
					a[1][assi] = f-assi;
				}
			}
		}
	}
	
	printf("At %d, %d the largest product is: %d\n\n",a[0][0]+1,a[1][0]+1,largeProd);
	
	
	for(i=0; i<4;i++){
		int b1 = a[0][i]+1;
		int b2 = a[1][i]+1;
		int b3 = nums[b1-1][b2-1];
		printf("(%d, %d)  %d",b1,b2,b3);
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

