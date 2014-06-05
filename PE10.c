/*
Project Euler
Problem 10 - Sum of all prime numbers under 2 mil
Jacob Mintz
*/

#include <stdio.h>
#include <math.h>

int primecheck(int input);

int main(void)
{
	long long totalSum = 5;
	int primenums = 2;	
	for(int i=5; i<2000000; i+=2)
		if(primecheck(i)){
			totalSum += i;
			primenums++;
		}
		
	printf("Sum Total: %lld\nNumber of Primes: %d",totalSum,primenums);

return 0;
}


//True if prime (not 0)
int primecheck(int num) 
{
	int check = 1;
	int prcheck = 1;
	int i = 2;
	while(check && prcheck) {
		if(num%i==0)
			check=0;
		else if((num/i) <= i)
			prcheck=0;
		i++;
	}
	
return check;
}