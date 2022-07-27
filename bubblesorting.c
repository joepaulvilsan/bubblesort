#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int getpid();
int gettimeofday();
float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

int main()
{
	struct timeval t0;
   	struct timeval t1;
   	float elapsed;
    
  int n,c,d,swap;

  printf("Enter number of elements\n");
  scanf("%d", &n);
	int array[n];
  printf("Enter number of random numbers");
	srand( (unsigned) time(NULL) * getpid());	
  for (c=0;c<n;c++)
    {	
		array[c]=rand()%100;
		printf("%d\n",array[c]);
    }
	gettimeofday(&t0, NULL);
  for (c=0;c<n-1;c++)
  {
    for (d=0;d<n-c-1;d++)
    {
      if (array[d]>array[d+1]) 
      {
        swap=array[d];
        array[d]=array[d+1];
        array[d+1]=swap;
      }
    }
  }

  printf("Sorted list \n");

	  for (c = 0; c < n; c++)
		 printf("%d\n", array[c]);
	gettimeofday(&t1, NULL);
	   elapsed = timedifference_msec(t0, t1);
	   printf("\nCode executed in %f milliseconds.\n",elapsed);
  return 0;
}
