/*
Project Euler
Problem 19 - How many sundays fall on the first from 1901 thru 2001
Jacob Mintz
*/

#include <stdio.h>

int main(void)
{
	int sunDate[10000];
	int numS = 0;
	int t;
	int months[] = {31,28,31,30,31,30,31,31,30,31,30,31,0,0,29};
	int m = 0;
	int year = 1900;
	sunDate[0] = 0;
	int i = 1;
	while(year < 2001)
	{
		t = sunDate[i-1] + 7;
		if(t > months[m])
		{
			t -= months[m];
			m++;
			if(m == 12)
			{
				m = 0;
				year++;
			}
			if((year%4 == 0) && ((year%100 != 0) || (year%400 == 0))) 
				if(m == 1)
					m = 14; 		// leap year
				else if(m == 15)	
					m = 2;			
		}
		sunDate[i] = t;
		i++;
		if(t == 1 && year != 1900)
			numS++;
	}

	printf("\nNumber of Sundays: %d\n",numS);

	return 0;
}