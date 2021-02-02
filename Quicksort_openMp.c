#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define n 500000
int partition(int arr[], int low, int high)
{
    int i,j, temp,key;
    key=arr[low];
    i=low+1;
    j=high;
    while(1)
    {
        while(i<high && key>=arr[i])
        {
                i++;
        }
        while(key<arr[j])
        {
                j--;
        }
        if(i<j)
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
        else
        {
            int temp=arr[low];
            arr[low]=arr[j];
            arr[j]=temp;
            return(j);
        }
    }
}
void quicksort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pivot=partition(arr,low,high); //returns position of pivot element
        //these two can also be executed as parallel threads        quicksort(arr,low,pivot-1);
        quicksort(arr,pivot+1,high);
    }
}

int main()
{
    int a[n];
    double p_start;
    double p_end;
    double s_start;
    double s_end;
    printf("For n= %d \n",n);
    int i;
    for(i=0;i<n;i++)
    {
        a[i]=rand()*10;
    }

    //serial sorting    s_start=omp_get_wtime();
    quicksort(a,0,n);
    s_end=omp_get_wtime();


    for(i=0;i<n;i++)
    {
        a[i]=rand()*10;
    }

    //parallel sorting    p_start=omp_get_wtime();
    int j=partition(a,0,n-1);
        #pragma omp parallel sections
        {
            #pragma omp section
            {
                quicksort(a,0,j-1);
            }
            #pragma omp section
            {
                quicksort(a,j+1,n-1);
            }
        }
    p_end=omp_get_wtime();

    printf("Execution time for sequential quick sort: %f \n",s_end-s_start);
    printf("Execution time for parallel quick sort: %f \n",p_end-p_start);
}