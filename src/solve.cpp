#include "solve.hpp"

#define A(i,j) A[(i)*lda+(j)]
#define B(i,j) B[(i)*ldb+(j)]
#define C(i,j) C[(i)*ldc+(j)]

void User_matMult(float* A, float* B, float* C, int M, int K, int N, int lda, int ldb, int ldc){
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < K; k++)
            {
                C(i,j) += A(i,k) * B(k,j);
            }
        }
    }
}