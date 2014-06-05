//Project Euler
//Problem 5 - Difference between (1+2+...+100)^2 - (1^2+2^2+...+100^2)
//Jacob Mintz

#include <stdio.h>
#include <math.h>

int main(void)
{
long int a = 0;
long int b = 0;

for(int i=1; i<=100; i++){
	a = a+i;	
	b = b + (i*i);
	printf("%d) a:%ld   b:%ld\n",i,a,b);
}

a = a*a;

int long long final = a-b;

printf("Final answer: %lld,  %ld, %ld",final,a,b);

return 0;
}