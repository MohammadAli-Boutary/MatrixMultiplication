#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define r1 100
#define c1 100
#define r2 100
#define c2 100

int result[r1][c2];


void matrixMultiply(int A[][c1], int B[][c2]){
	
	for (int i = 0 ; i < r1; i++){
		for(int j = 0; j < c2; j++){
			result[i][j] = 0;
			for(int k = 0; k < r2; k++){
				result[i][j] += A[i][k] * B[k][j];
			}
		}
	}

}

void fillMatrix(int r, int c, int A[r][c]){
	for(int i = 0 ; i < r ; i++){
		for(int j = 0 ; j < c ; j++){
			A[i][j] = rand() % 100;
		}
	}
}

void printMatrix(int r, int c, int A[r][c]){
	for(int i = 0 ; i < r ; i++){
		for(int j = 0 ; j < c ; j++){
			printf("%d\t", A[i][j]);
		}
		printf("\n");
	}
}

int main(){

    struct timeval start_time, end_time;
    
    if(r1<=0 || c1<=0 || r2<=0){
    	printf("Invalid dimensions for matrix multiplication: must be greater than 0");
    	exit(EXIT_FAILURE);
    }
    
    if(c1 != r2){
    	printf("Number of columns in matrix A must be equal to the number of rows in matrix B\n");
    	exit(EXIT_FAILURE);
    }	
    
    int A[r1][c1], B[r2][c2];
    
    gettimeofday(&start_time, NULL);
    
    fillMatrix(r1,c1,A);
    fillMatrix(r2,c2,B);
    
    
    matrixMultiply(A,B);
    
    gettimeofday(&end_time, NULL);
    
    double execution_time = (double) (end_time.tv_sec - start_time.tv_sec) + (double) (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
    
    printf("Execution time of sequential Matrix Multiplication : %f seconds", execution_time);
    
    return 0;
}

















