/*
Project Euler
Problem 17 - Number of letters through 1000
Jacob Mintz
*/
#include <stdio.h>

int main(void)
{
	//-, one, two, three, four, five, six
	//seven, eight, nine
	int sing[] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4};
	
	//-, -, twenty, thirty, forty, fifty, sixty
	//seventy, eighty, ninety
	int tens[] = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};
	
	//ten, eleven, twelve, thirteen, fourteen, fifteen
	//sixteen, seventeen, eighteen, nineteen
	int teens[] = {3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
	
	int and = 3;
	int hundred = 7;
	int thousand = 8;
	int sum = 0;
	
	for(int i = 1; i < 1000; i++)
	{	
		int a = i%100; 		// tens and ones
		int b = i/100; 		// hundreds 
		int c = i%10; 		// ones 
		int d = (a - c)/10; // tens
		
		if(b >= 1)
			if( d > 0 || c > 0)
				sum += (sing[b] + hundred + and);
			else
				sum += (sing[b] + hundred);
		
		if(a >= 20 || a < 10)
			sum += (tens[d] + sing[c]); 
			
		else 
			sum += teens[c];
	}
	
	sum += sing[1] + thousand; // one thousand
	
	printf("Total Sum of Letters: %d", sum);
}