/*
Project Euler
Problem 15 - 20x20 grid, how many paths
Jacob Mintz
*/

#include <stdio.h>

int main(void)
{
	int long long ans;
	const int gridSize = 20;
	const int pascLevel = gridSize*2 + 1;
	int long long pasc[pascLevel];
	int long long temp[pascLevel];
	pasc[0] = 1; 
	pasc[1] = 1;
	for(int i = 2; i < pascLevel; i++)
	{
		for(int j = 0; j < i; temp[j] = pasc[j], j++);
		//{ printf("%ld ", pasc[j]); }
		//printf("\n");
		
		int k = 0;
		while( ++k < i )
		{
			pasc[k] = temp[k] + temp[k-1];
		}
		pasc[k] = 1;
	}
	ans = pasc[ gridSize ];
	printf( "Num of paths: %lld" , ans );



}