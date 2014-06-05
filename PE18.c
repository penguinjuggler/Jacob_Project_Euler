/*
Project Euler
Problem 18 - Largest sum top to bottom of a triangle
Jacob Mintz
*/

#include <stdio.h>

int main(void)
{
	int const SZ = 15;											// 100 for prob 67
	int nums[SZ][SZ];
	FILE *fptr; 
	fptr = fopen("Jacob_Project_Euler\\P18Grid.txt","r");		// P67Grid.txt for prob 67
	if(fptr == NULL)
	{
		printf("Error!");
		exit(1);
	}
	
	for(int i = 0; !feof(fptr); i++)
	{
		for(int h = 0; h <= i; h++)
		{
			//if(h == 0) printf("\n");
			fscanf(fptr, "%d", &nums[i][h]);
			//printf("%d ",nums[i][h]);
		}
	}
	//printf("\n\n");
	fclose(fptr);
	
	
	int sums[SZ];
	for(int q = 0; q < SZ; sums[q++] = nums[SZ-1][q]) {};	// Sum starts with bottom row

	for(int i = SZ - 1; i > 0; i--)							// Start from bottom row
	{
		int temp[SZ];										// Temporary
		for(int j = 0; j <= i; j++)							// From left to right side
		{
			int p[2];										// Reset temp first or second check
			for(int k = 0; k < 2; k++)
			{
				p[k] = sums[j + k] + nums[i - 1][j];		// Do a sum
				if(k == 1 && temp[j] < p[1])				// If second time, and > than first sum
					temp[j] = p[1];							// Reset it
				else
					temp[j] = p[0];							// Otherwise set first one
			}
		}
		for(int q = 0; q < SZ; sums[q++] = temp[q]);		// Set sums to temp sums
		
	}
	printf("\nLargest sum: %d\n", sums[0]);					// Print largest
	
	return 0;
}