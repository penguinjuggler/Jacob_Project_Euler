//Project Euler
//Problem 5 - Lowest product of numbers 1-20
//Jacob Mintz

#include <stdio.h>
#include <math.h>


int main(void)
{
int maxn = 20;
int numt;
int j;
int facts[maxn];
for(int i=0; i<maxn; i++)
	facts[i] = 0;

for(int num=1; num<=maxn; num++){
	numt = num;	
	j = 0;
	printf("\nNum: %d", num);
	for(int i=2; i<=numt; i++){
		if(numt%i == 0){
			j++;
			if(j > facts[i-1])
				facts[i-1]++;
			printf("  %d:%d", i, facts[i-1]);
			numt = numt/i;
			if(numt%i != 0)
				j = 0;
			i = 1;
		}
	}
}

long int prodfin = 1;
printf("\n");
for(int i=0; i<maxn; i++){
	//printf(" %d:%d", i+1, facts[i]);
	if(facts[i]!=0)
		for(int a = 1; a<=facts[i]; a++)
			prodfin = prodfin * (i+1);
			//printf("%d:%d\n",i+1,prodfin);}
}

printf("\nFinal Product: %d\n", prodfin);

return 0;
}

