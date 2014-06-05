/*
Project Euler
Problem 12 - highly divisible triangular number
	More than 500 divisors for a triangle number (added natural numbers)
Jacob Mintz
*/

#include <stdio.h>

int triNum(int num);
int numFactors(int num);

int main(void)
{
	int n=4;
	int tN, tNF;
	while((tNF = numFactors(tN = triNum(n++)))<500);
	printf("The %d triangular number is %d and has %d factors",n,tN,tNF); 
	
	return 0;
}	

int triNum(int num)
{
	int tri=0;
	while(num>0, --num){
		tri += num;
	}
	return tri;
}

int numFactors(int num)
{
	int i2 = 0;
	int i1 = 10;
	int tot = 0;
	while(i1>(i2++))
		if(num%i2==0){
			tot++;
			i1 = num/i2;
		}
		
	return tot*2;
}