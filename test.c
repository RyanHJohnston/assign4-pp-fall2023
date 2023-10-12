#include <stdio.h>

#define M 3
#define N 3
#define P 3

void matrixMultiply(int A[M][N], int B[N][P], int C[M][P]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            C[i][j] = 0;  // Initialize the resultant matrix element to 0
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[M][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[N][P] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int C[M][P];  // Resultant matrix

    matrixMultiply(A, B, C);

    // Print the result
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
