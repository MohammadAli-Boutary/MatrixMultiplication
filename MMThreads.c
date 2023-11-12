#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <math.h>

#define NUM_THREADS 2

#define SIZE 100

int A[SIZE][SIZE];
int B[SIZE][SIZE];
int result[SIZE][SIZE];
int step = 0;


void *MM_Worker(void *arg){
	int start, end, tid,sum, block_size;
	tid = *(int *)(arg);
	block_size = SIZE/NUM_THREADS; 
	start = tid * block_size;
	end = start + block_size;
	for(int i = start; i<end; i++){
		for(int j = 0; j < SIZE; j++){
			sum = 0;
			for(int k = 0; k < SIZE; k++){
				sum += A[i][k] * B[k][j];
			}
			result[i][j] = sum;
		}
	}
}
int main(){
    
   struct timeval start_time, end_time;
    
   for(int i = 0 ; i < SIZE ; i++){
		for(int j = 0 ; j < SIZE ; j++){
			A[i][j] = rand() % 10;
			B[i][j] = rand() % 10;
		}
   }
  
    
    gettimeofday(&start_time, NULL);  
    pthread_t threads[NUM_THREADS];
    for(int i = 0 ; i < NUM_THREADS; i++){
	int* tid;
	tid = (int *) malloc(sizeof(int));
	*tid = i;
	pthread_create(&threads[i], NULL, MM_Worker, (void *)(tid));
    }
    for(int i = 0 ; i < NUM_THREADS; i++){
	pthread_join(threads[i], NULL);
    }
    gettimeofday(&end_time, NULL);
    
    double execution_time = (double) (end_time.tv_sec - start_time.tv_sec) + (double) (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
    
    printf("Execution time of Matrix Multiplication using threads: %f seconds | NUM THREADS = %d", execution_time, NUM_THREADS);
    
    return 0;
}
