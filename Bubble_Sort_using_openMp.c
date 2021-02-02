#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b);
int main()
{
 int N=10;
 double start,end;
 int i,arr[N],first,j;
 for(i=0;i<N;i++)
 {
 arr[i]=rand()%N;
 }
 start = omp_get_wtime();
 for(i=0;i<N-1;i++)
 {
 first = i%2;
 #pragma omp parallel for default(none),shared(arr,first,N)
 for(j=first;j<N-1;j++)
 {
 if(arr[j]>arr[j+1])
 swap(&arr[j],&arr[j+1]);
 }
 }
 end=omp_get_wtime();
 for(i=0;i<N;i++)
 {
 printf("%d\n",arr[i]);
 }
 printf("Parallel time execution : %lf\n",(end-start));
 return 0;
}
void swap(int *a,int *b)
{
 int temp = *a;
 *a=*b;
 *b=temp;
}