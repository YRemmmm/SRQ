#include <iostream>
#include <chrono>
#include <cstring>

#include "base.hpp"
#include "solve.hpp"

int main(int argc, char**argv)
{
    // 计算的矩阵大小为 matrix_size * matrix_size
    // 测试时，可直接在此处设置矩阵大小
    int matrix_size = atoi(argv[1]);
    int M = matrix_size;
    int K = matrix_size;
    int N = matrix_size;
    int size_A = sizeof(float) * M * K;
    int size_B = sizeof(float) * K * N;
    int size_C = sizeof(float) * M * N;
    float *A = (float*)malloc(size_A);
    float *B = (float*)malloc(size_B);
    float *C_Base = (float*)malloc(size_C);
    float *C_User = (float*)malloc(size_C);

    random_matrix(M, K, A, M);
    random_matrix(K, N, B, K);
    memset(C_Base, 0, size_C);
    memset(C_User, 0, size_C);
    
    printf("=========================================\n");

    auto t1 = std::chrono::steady_clock::now();
    //开始计算
    //////可修改函数User_matMult在solve.cpp中///////
    User_matMult(A, B, C_User, M, K, N, K, N, N);
    ///////////////////////////////////////////
    auto t2 = std::chrono::steady_clock::now();
    int User_time = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count(); 
    printf("| Your matMult Cost \x1b[33m%d ms\x1b[0m\n", User_time);
    

    auto t3 = std::chrono::steady_clock::now();
    Base_matMult(A, B, C_Base, M, K, N, K, N, N);
    auto t4 = std::chrono::steady_clock::now();
    int base_time = std::chrono::duration_cast<std::chrono::milliseconds>(t4 - t3).count();
    printf("| Base matMult Cost \x1b[33m%d ms\x1b[0m\n", base_time);

    compare_matrices(M, N, C_Base, N, C_User, N);
    double speedup = double(base_time) / double(User_time) ;
    printf("| \x1b[34mTest passed\x1b[0m\n");
    printf("| \x1b[34mSpeedup factor: %.2f\x1b[0m\n", speedup);
    printf("=========================================\n");
   
    free(A);
    free(B);
    free(C_Base);
    free(C_User);

    return 0;
}