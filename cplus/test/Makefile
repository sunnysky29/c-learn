
CXX := g++
CXXFLAGS := -I./include -Wall -Wextra -g -std=c++20

# ./ 目录
SRCS := $(wildcard *.cpp)  # 匹配当前目录所有 .cpp 文件
TARGETS := $(SRCS:.cpp=)  # 将每个 .cpp 文件去掉 .cpp 后缀 → 得到可执行文件名

# ./src目录下所有.cpp文件并生成对应的.o文件
SRC_OBJS := $(patsubst %.cpp,%.o,$(wildcard src/*.cpp))

all: $(TARGETS)  #  依赖 TARGETS

# 编译规则：每个目标程序依赖对应的.cpp和所有src下的.o文件
# 要构建目标 1，需要 1.cpp 和所有 $(SRC_OBJS)
#              （即 src/a.o, src/log.o, src/math.o） 
$(TARGETS): %: %.cpp $(SRC_OBJS)
	$(CXX) $(CXXFLAGS) $< $(SRC_OBJS) -o $@

# 通用规则：告诉 Make 如何从 src/.cpp 编译出 src/.o。
src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGETS) src/*.o

.PHONY: all clean