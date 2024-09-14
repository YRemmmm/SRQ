#include <iostream>

#define a(i, j) a[(i)*lda + (j)]
#define b(i, j) b[(i)*ldb + (j)]
#define c(i, j) C[(j)*ldc + (i)]
#define abs(x) ((x) < 0.0 ? -(x) : (x))

void random_matrix(int m, int n, float *C, int ldc) {
    int i, j;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            c(i, j) = 2.0 * (float)drand48() - 1.0;
            // c(i, j) = (rand()%255)/255.0;
        }
    }
}

void compare_matrices(int m, int n, float *a, int lda, float *b, int ldb) {
    int i, j;
    float max_diff = 0.0, diff;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            diff = abs(a(i, j) - b(i, j));
            max_diff = (diff > max_diff ? diff : max_diff);
            if (max_diff > 1.5 || max_diff < -1.5) {
                printf("| \x1b[31mTest failed !!!\x1b[0m\n");
                printf("| \x1b[31mFirst error in: i=%d j=%d\x1b[0m\n", i, j);
                printf("| \x1b[31mBase value: %f\x1b[0m\n", a(i, j));
                printf("| \x1b[31mYour value: %f\x1b[0m\n", b(i, j));
                printf("=========================================\n");
                exit(-1);
            }
        }
    }

}
