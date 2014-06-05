//Project Euler
//Problem 5 - 10 001 prime
//Jacob Mintz

#include <stdio.h>
#include <math.h>


int main(void) {
	int pnum = 2;
	int pri = 0;
	int i = 1;
	long long int num = 3;
	while(pnum <= 10001) {
		pri = 0; i = 2;
		
		while(pri == 0 && i<num) {
			if(num%i == 0)
				pri = 1;
			i++;
		}
		
		if(pri == 0){
			if(pnum%1000==0)
				printf("%d: %lld\n",pnum,num);
			pnum++;	
		}
		
		num = num + 2;
	}


printf("\n%d: %lld",pnum-1,num-2);

return 0;
}

