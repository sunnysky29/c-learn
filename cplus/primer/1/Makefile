# 编译器和编译选项
CXX      = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++23 -g -O0

# 默认目标
all: test1 sale

# 单独定义每个目标的构建规则, 注意是 tab
test1: test1.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

sale: sale.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# 清理规则
clean:
	rm -f test1 sale           

.PHONY: all clean