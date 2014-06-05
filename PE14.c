/*
Project Euler
Problem 14 - collatz n/2 if even, 3n+1 if odd
longest one under 1 million
Jacob Mintz
*/

/*
#include <stdio.h>

int main(int argc, char **argv)
{
  int longest = 0;
  int terms = 0;
  int i;
  unsigned long j;

  for (i = 1; i <= 1000000; i++)
  {
    j = i;
    int this_terms = 1;

    while (j != 1)
    {
      this_terms++;

      if (this_terms > terms)
      {
        terms = this_terms;
        longest = i;
      }

      if (j % 2 == 0)
      {
        j = j / 2;
      }
      else
      {
        j = 3 * j + 1;
      }
    }
  }

  printf("longest: %d (%d)\n", longest, terms);
  return 0;
}
*/

#include <stdio.h>

int main(void)
{
	int out;
	int long long cur;
	int longesti = 1;
	int longest = 1;
	int regi[100000];
	regi[0] = 1;
	int tot = 0;

	for(int i = 2; i < 1000000; i++)
	{
		out = 0;
		tot = 0;
		cur = i;
		while(out == 0)
		{
			if(cur < i && cur < 100000)
			{
				tot += regi[cur - 1];
				if(i < 100000)
					regi[i-1] = tot;
				out = 1;
			}
			else
			{
				if(cur % 2 == 0)
					cur = cur / 2;
				else
					cur = 3 * cur + 1;
				tot++;
			}	
		}
		
		if(longest < tot)
		{
			longest = tot;
			longesti = i;
		}
		//if(i%1000==0)
			//printf("%lldk)\t%d \t[%6d, %d]\n",i/1000,tot,longesti,longest);
	}		
	printf("Longest Collatz Sequence: \n\tn: %d\n\t#: %d",longesti,longest);
	
	return 0;
}
