/*
Project Euler
Problem 9 - pythagorean Triplet a+b+c=1000 and a^2 + b^2 = c^2
Jacob Mintz
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
	int a, b, c;
	int bl;
	int af, bf, cf;
	
	for(int a=1; a<500; a++) {
		for(b=1, bl = 1000-a; b<bl; b++) {
			c = 1000-a-b;
			if(c*c == a*a + b*b)
				af = a, bf = b, cf = c;
		}
	}
	
	printf("\na:%d b:%d c:%d\n\n",af, bf, cf);
	printf("Product: %d\n",af*bf*cf);
	
return 0;
}