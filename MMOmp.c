#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <math.h>

#define NUM_THREADS 4

#define SIZE 100

int A[SIZE][SIZE];
int B[SIZE][SIZE];
int result[SIZE][SIZE];
int step = 0;


int main(){
    
   struct timeval start_time, end_time;
    
   for(int i = 0 ; i < SIZE ; i++){
		for(int j = 0 ; j < SIZE ; j++){
			A[i][j] = rand() % 10;
			B[i][j] = rand() % 10;
		}
   }
  
    omp_set_num_threads(NUM_THREADS);
    gettimeofday(&start_time, NULL);  
    #pragma omp parallel for
    for(int i = 0; i < SIZE; i++){
    	for(int j = 0; j < SIZE; j++){
    		int sum = 0;
    		for(int k = 0 ; k < SIZE; k++){
    			sum+= A[i][k] * B[k][j];
		}
		result[i][j] = sum;
    	}
    }
    gettimeofday(&end_time, NULL);
    
    double execution_time = (double) (end_time.tv_sec - start_time.tv_sec) + (double) (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
    
    printf("Execution time of Matrix Multiplication using threads: %f seconds | NUM THREADS = %d", execution_time, NUM_THREADS);
    
    return 0;
}
