#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <pthread.h>
#include <vector>

/* (a) (20 points) Write a shared memory OpenMP program on Fox server to multiply two n-by-n matrices using p */
/* processors with 1<= p <=12. Fill up the matrices with some constant values so that it would be easier for you to */
/* verify the resulting matrix for correctness. */

const int MATRIX_SIZE = 4;

void init_matrix(int value);
void print_matrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]);
void matrix_multiply(int A[MATRIX_SIZE][MATRIX_SIZE], 
        int B[MATRIX_SIZE][MATRIX_SIZE], 
        int C[MATRIX_SIZE][MATRIX_SIZE]);


int
main(int argc, char *argv[])
{
    /* mulitiply two n by n martrices using p processors 1 <= p <= 12 */
    /* fill up matrices with some constant values to verify correctness */
    
    int A_matrix[MATRIX_SIZE][MATRIX_SIZE];
    int B_matrix[MATRIX_SIZE][MATRIX_SIZE];
    int C_matrix[MATRIX_SIZE][MATRIX_SIZE];
    int i;
    int j;
    int k;
    
    for (i = 0; i < MATRIX_SIZE; ++i) {
        for (j = 0; j < MATRIX_SIZE; ++j) {
            A_matrix[i][j] = 2;
        }
    }
    
    fprintf(stdout, "A matrix:\n");
    print_matrix(A_matrix);
    fprintf(stdout, "\n");

    for (i = 0; i < MATRIX_SIZE; ++i) {
        for (j = 0; j < MATRIX_SIZE; ++j) {
            B_matrix[i][j] = 4;
        }
    }

    fprintf(stdout, "B matrix:\n");
    print_matrix(B_matrix);
    fprintf(stdout, "\n");

    for (i = 0; i < MATRIX_SIZE; ++i) {
        for (j = 0; j < MATRIX_SIZE; ++j) {
            C_matrix[i][j] = 0;
        }
    }
    fprintf(stdout, "C_matrix:\n");
    print_matrix(C_matrix);
    fprintf(stdout, "\n");


    /* multiply matrixes using matrix-matrix multiply */
    matrix_multiply(A_matrix, B_matrix, C_matrix);

    fprintf(stdout, "A_matrix * B_matrix = C_matrix: \n");
    print_matrix(C_matrix);
    fprintf(stdout, "\n");

    
    


    exit(EXIT_SUCCESS);
}

void
print_matrix(int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    int i;
    int j;
    
    for (i = 0; i < MATRIX_SIZE; ++i) {
        for (j = 0; j < MATRIX_SIZE; ++j) {
            fprintf(stdout, "%i ", matrix[i][j]);
        }
        fprintf(stdout, "\n");
    }

}

void 
matrix_multiply(int A[MATRIX_SIZE][MATRIX_SIZE], 
        int B[MATRIX_SIZE][MATRIX_SIZE], 
        int C[MATRIX_SIZE][MATRIX_SIZE]) 
{
    #pragma omp parallel for
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            C[i][j] = 0;  // Initialize the resultant matrix element to 0
            for (int k = 0; k < MATRIX_SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}


