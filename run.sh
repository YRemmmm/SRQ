#!/bin/bash
echo -e "\e[32m> Job starting at: $(date '+%Y-%m-%d %H:%M:%S') <\e[0m"

flag=$1

case $flag in
    "remakelib")
        cd lib
        echo -e "\e[32m> start remake lib <\e[0m"
        make clean
        make
        echo -e "\e[32m> finished remake lib <\e[0m"
        ;;
    *)
        echo -e "\e[32m> deleting old files <\e[0m"
        make clean

        echo -e "\e[32m> making new files <\e[0m"
        make

        echo -e "\e[32m> runing program <\e[0m"
        # 进程数最大为4，线程数最大为4
        export OMP_NUM_THREADS=4
        # 可执行程序后所跟的数字 n 代表计算的矩阵大小为 n * n
        ./gemm 1024
        # ./gemm 2048

        echo -e "\e[32m> Job finished at: $(date '+%Y-%m-%d %H:%M:%S') <\e[0m"
        ;;
esac