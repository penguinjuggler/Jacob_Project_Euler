// Project Euler
// Problem 2 - Sum of even valued Fibonacci Numbers < 4.000.000
// Jacob Mintz

#include <stdio.h>
#include <math.h>

int main(void)
{
int sum = 0;
int temp = 0; 
int i1 = 0;
int max = 4000000;

for (int i2 = 1; i2 < max;) {
	if ((i2%2) == 0)		//even
		sum = sum + i2;		//add to sum
	temp = i1 + i2;				
	i1 = i2;			//new i1
	i2 = temp;			//new i2
}

printf("\n  %d  \n",sum);

return 0;
}