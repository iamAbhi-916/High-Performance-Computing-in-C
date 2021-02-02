#include <cuda.h>
 #include <stdio.h>
 #include <time.h>
 #define SIZE 1000
 __global__ void max(int *a , int *c) // kernel function definition
 {
 int i = threadIdx.x; // initialize i to thread ID
 *c = a[0];
 if(a[i] > *c)
 {
 *c = a[i];
 }
 }
 int main()
 {
 int i;
 srand(time(NULL)); //makes use of the computer's internal clock to control the choice of the
seed
 int a[SIZE];
 int c;
 int *dev_a, *dev_c; //GPU / device parameters
 cudaMalloc((void **) &dev_a, SIZE*sizeof(int)); //assign memory to parameters on GPU
 cudaMalloc((void **) &dev_c, SIZE*sizeof(int));
 for( i = 0 ; i < SIZE ; i++)
 {
 a[i] = i; // rand()% 1000 + 1; // input the numbers
 }