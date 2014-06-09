/*
Project Euler
Problem 20 - Sum of digits of 100!
Jacob Mintz
*/

#include <stdio.h>


int main(void)
{
	int len = 1;
	int tot[500];
	int addon = 0;
	int sumtot = 0;
	for(int i=0; i<500; tot[i++]=0){} // Set to 0
	tot[0] = 1;
	
	for(int i = 2; i < 100; i++)
	{
		//printf("\ni: %d\ttot: ",i);
		int temp[500];
		for(int j = 0; j < len; j++)
		{
			int a = i * tot[j] + addon;
			tot[j] = a%10;
			addon = a/10;
			if(addon > 0 && j == len-1)
				len++;			
		}
		//for(int q = len; q>0; q--)
		//	printf("%d ",tot[q-1]);
	}
	
	printf("\n\n");
	for(int i = len; i>0; i--)
		sumtot += tot[i-1];
	
	printf("\n\nSum of Digits of 100!: %d",sumtot);
	
	return 0;

}