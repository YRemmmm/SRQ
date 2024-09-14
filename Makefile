# 定义编译器和编译选项
CXX = g++
CXXFLAGS = -Wall -std=c++17 -O2
OMPFLAGS = -fopenmp

# 定义目标文件和可执行文件名称
SRC = $(wildcard ./src/*.cpp)
OBJS = $(patsubst %.cpp,%.o, $(SRC))
EXEC = gemm
#指定头文件目录
INC_DIR = -I./include
#链接选项
LINKFLAGS = -linit -L./lib

# 默认目标
all: $(EXEC)

# 规则：编译可执行文件
$(EXEC): $(OBJS)
	$(CXX) $^ $(OMPFLAGS) $(LINKFLAGS) -o $@

# 规则：编译对象文件
src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) $(OMPFLAGS) $(INC_DIR) -c $< -o $@

# 清理规则
clean:
	rm -f $(OBJS) $(EXEC)