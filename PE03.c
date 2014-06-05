// Project Euler
// Problem 3 - Largest Prime Factor of Initial Number
// Jacob Mintz

#include <stdio.h>
#include <math.h>

int main(void)
{
int pf[100];
long long int num = 600851475143;		//Initial Number
long long int div = 2;					//Starting Factor
int i = 0;								//Counter
int ans = 1;							//True

while (ans) {
	if(num < 4)		//If largest factor becomes less than 4, back out
		ans = 0;
	else {
		if(num%div == 0 && (div<num || div == 2 || div ==3)){ 	//Divisible and either 2 or 3
			pf[i] = div;										//Add factor to list
			num = num/div;										//Reset num
			printf("It)%d  Factor)%d  New)%d\n", i, pf[i], num);		
			i++;						
			div = 2;}					
		else if(div == num){						//If factor checker = num, then PRIME
			ans = 0;
			pf[i] = div;
			printf("It)%d  Factor)%d  New)%d\n", i, pf[i], num);	
			printf("Largest Prime: %d",div);}
		else										//Otherwise increase factor checker
			div++;
	}
}

return 0;
}

//Checks from bottom up if a number is prime
// int primecheck(num)
// {
// int ans = 1;							//true or false. 1t, 0f
// int new = 2;							//factor checker
// int sqrnum = floor(sqrt(num));
//printf("  %d  ",sqrnum);

// while (ans && new<=sqrnum){
	// if (num%new == 0)
		// ans = 0;							//False if does have factor
	// else {
		//printf("ch:%d\n",new);
		// new++;								//Else add to checking number
		//while (primecheck(new) && new>3)	//Check that new checker is prime
		//	new++;							//If it is, go to next one
	// }	
// }

// return ans;
// }