#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#include<time.h>

void serial_addition(int a[], int b[], int c[], int N)
{
	int i;
	clock_t t;
	t = clock();
	for(i = 0; i < N; i++)
	{
		c[i] = a[i] + b[i];
	}
	t = clock()-t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("Time Taken for Sequential Addition: %f seconds\n", time_taken);
	printf("Starting elements of Serially added array: \n");
	for (int i = 0; i < 5; i++)
	{
		printf("%d\t", c[i]);
	}
	printf("\n\n");
}

void parallel_addition(int a[], int b[], int c[], int N)
{
	int i;
	double itime =((double)omp_get_wtime());
	#pragma omp parallel shared(a, b, c) private(i)
	{
		#pragma omp for
		for(i = 0; i < N; i++)
		{
			c[i] = a[i] + b[i];
		}
	}
	double ftime = omp_get_wtime();
	double exec_time = ftime - itime;
	printf("Time taken for Parallel Addition: %f seconds\n", exec_time);
	printf("Starting elements of Parallely added array: \n");
	for (int i = 0; i < 5; i++)   bbn 
	{
		printf("%d\t", c[i]);
	}
	printf("\n\n");
}

void serial_subtraction(int a[], int b[], int c[], int N)
{
	int i;
	clock_t t;
	t = clock();
	for(i = 0; i < N; i++)
	{
		c[i] = a[i] - b[i];
	}
	t = clock()-t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("Time Taken for Sequential Subtraction: %f seconds\n", time_taken);
	printf("Starting elements of Serially subtracted array: \n");
	for (int i = 0; i < 5; i++)
	{
		printf("%d\t", c[i]);
	}
	printf("\n\n");
}

void parallel_subtraction(int a[], int b[], int c[], int N)
{
	int i;
	double itime = omp_get_wtime();
	#pragma omp parallel shared(a, b, c) private(i)
	{
		#pragma omp for
		for(i = 0; i < N; i++)
		{
			c[i] = a[i] - b[i];
		}
	}
	double ftime = omp_get_wtime();
	double exec_time = ftime - itime;
	printf("Time taken for Parallel Subtraction: %f seconds\n", exec_time);
	printf("Starting elements of Parallely subtracted array: \n");
	for (int i = 0; i < 5; i++)
	{
		printf("%d\t", c[i]);
	}
	printf("\n\n");
}

void serial_multiplication(int a[], int b[], int c[], int N)
{
	int i;
	clock_t t;
	t = clock();
	for(i = 0; i < N; i++)
	{
		c[i] = a[i] * b[i];
	}
	t = clock()-t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("Time Taken for Sequential Multiplication: %f seconds\n", time_taken);
	printf("Starting elements of Serially multiplied array: \n");
	for (int i = 0; i < 5; i++)
	{
		printf("%d\t", c[i]);
	}
	printf("\n\n");
}

void parallel_multiplication(int a[], int b[], int c[], int N)
{
	int i;
	double itime = omp_get_wtime();
	#pragma omp parallel shared(a, b, c) private(i)
	{
		#pragma omp for
		for(i = 0; i < N; i++)
		{
			c[i] = a[i] * b[i];
		}
	}
	double ftime = omp_get_wtime();
	double exec_time = ftime - itime;
	printf("Time taken for Parallel multiplication: %f seconds\n", exec_time);
	printf("Starting elements of Parallely multiplied array: \n");
	for (int i = 0; i < 5; i++)
	{
		printf("%d\t", c[i]);
	}
	printf("\n\n");
}

int main()
{
	int N, opt;
	char choice = 'y';
	char choose = 'y';
	do
	{
		printf("Enter the size of array: ");
		scanf("%d", &N);

		int a[N];
		int b[N];
		int c[N];
		int i;

		for(i = 0; i < N; i++)
		{
			a[i] = rand()%1000;
		}
		printf("Starting elements of Array A: \n");
		for(i = 0; i < 5; i++)
		{
			printf("%d\t", a[i]);
		}

		printf("\n");

		for(i = 0; i < N; i++)
		{
			b[i] = rand()%1000;
		}
		printf("Starting elements of Array B: \n");
		for(i = 0; i < 5; i++)
		{
			printf("%d\t", b[i]);
		}

		printf("\n\n");
		
		printf("***SERIAL AND PARALLEL ARRAY OPERATIONS***\n");
		
		do{
			printf("1. Addition\n2. Subtraction\n3. Multiplication\n");
			printf("Choose from above options: ");
			scanf("%d", &opt);
			
			switch(opt)
			{
				case 1: serial_addition(a, b, c, N);
					parallel_addition(a, b, c, N);
					break;
				case 2: serial_subtraction(a, b, c, N);
					parallel_subtraction(a, b, c, N);
					break;
				case 3: serial_multiplication(a, b, c, N);
					parallel_multiplication(a, b, c, N);
					break;
				default: printf("Invalid option!!");
			}
			
			printf("Do you want to perform more operations?(y/n): ");
			getchar();
			scanf("%c", &choice);
			printf("-------------------------------\n");
		}while(choice == 'y');
		
		printf("Do you want to continue?(y/n): ");
		getchar();
		scanf("%c", &choose);
		printf("*******************************\n");
		
	}while(choose == 'y');
	return 0;
}

