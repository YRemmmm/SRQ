
#define A(i,j) A[(i)*lda+(j)]
#define B(i,j) B[(i)*ldb+(j)]
#define C(i,j) C[(i)*ldc+(j)]

void random_matrix(int m, int n, float *C, int ldc);
void compare_matrices(int m, int n, float *a, int lda, float *b, int ldb);

//用于比较的baseline
void Base_matMult(float* A, float* B, float* C, int M, int K, int N, int lda, int ldb, int ldc) {
    float temp;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            temp = A(i,j);
            for (int k = 0; k < N; k++) {
                C(i,k) += temp * B(j,k);
            }
        }
    }
}