#include <stdio.h>
#include <omp.h>
#include <time.h>
#define N 10
int main()
{
int i,j;
clock_t ser_st,ser_end;
double par_st,par_end,ser_time,par_time;
 ser_st=clock();
//serial code execution
 for(i=0;i<N;i++)
 printf("%d\n",i);
 for(j=N;j>=1;j--)
 printf("%d\n",j);
 ser_end=clock();
 ser_time = ((double)(ser_end-ser_st))/CLOCKS_PER_SEC;
//parallel code execution

#pragma omp parallel sections
{
 par_st = omp_get_wtime();
 #pragma omp section
 for(i=0;i<N;i++)
 printf("%d\n",i);
 #pragma omp section
 for(j=N;j>=1;j--)
 printf("%d\n",j);
}//end sections
 par_end = omp_get_wtime();
 par_time = par_end-par_st;
 printf("Parallel time execution : %lf\n",par_time);
 printf("Serial time execution : %lf\n",ser_time);
 return 0;
}