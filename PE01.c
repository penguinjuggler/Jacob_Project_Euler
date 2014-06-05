// Project Euler
// Problem 1
// Jacob Mintz

#include <stdio.h>
#include <math.h>

int main(void)
{
int tot = 1000; 
int sum = 0;
for (int i = 0; i < tot; i++) {
	if (i%3 == 0 || i%5 == 0)
		sum += i;
}

printf("\n  %d  \n",sum);

return 0;
}