/*
Project Euler
Problem 16 - Sum of digits of 2^1000
Jacob Mintz
*/

#include <stdio.h>

int main(void)
{
	int num[1000];
	num[0] = 2;
	for(int a = 1; a < 1000; num[a] = 0, a++);
	int cur = 0;
	int powtimes = 1000;
	int sum = 0;
	int dignum;
	for(int cur = 1; cur < powtimes; cur++)
	{
		int addover = 0;
		for(int i = 0; i < 1000; i++)
		{	
			int f = num[i] * 2;
			num[i] = f%10 + addover;
			addover = f / 10;
		}
	}
	for(int i = 0; i < 1000; sum += num[i], i++);
	printf("Total sum: %d",sum);



}