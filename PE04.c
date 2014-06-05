// Project Euler
// Problem 4 - Highest palindromic number from the product two 3-digit numbers
// Jacob Mintz

#include <stdio.h>
#include <math.h>

int checkp(int);
int power(int,int);

int main(void) {

// printf("0: %d\n",checkp(345543));
// printf("1: %d",checkp(343543));
int a = 999;
int b = 999;
int aL = 900;
int bL = 900;
int pal = a * b;

while(!checkp(pal) && a>aL){

	while(!checkp(pal) && b>bL){
		b--;
		pal = a * b;
	}
	a--;
	b = a;
}	

printf("\n  %d  \n", pal);
printf("\n   a:%d \n", a);
printf("\n   b:%d \n", b);
return 0;
}


// Gives 1 for Palindrome (t)
//		 0 for not a Palindrome (f)
int checkp(int n) {

int arr[6];
int i = 0;
long int pow[8] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
while((n - pow[i]) > 0){
	arr[i] = (n % pow[i+1] - n % pow[i])/pow[i];
	i++;
}

int pal = 1;
int sz = sizeof(arr) / sizeof(arr[0]);
i = (int) sz/2;
while(i > 0 && pal){
	if(arr[i-1] != arr[sz-i])
		pal = 0;
	i--;
}

return pal;
}