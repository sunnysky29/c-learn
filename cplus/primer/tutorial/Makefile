# 编译器和编译选项
CXX      = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++23 -g -O0

# 默认目标
all: test1 sale test2 test3

# # 单独定义每个目标的构建规则, 注意是 tab
# test1: test1.cpp
# 	$(CXX) $(CXXFLAGS) $< -o $@
# 构建所有 test1 test2 test3... 的通用规则
test%: test%.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

sale: sale.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# 清理规则
clean:
	rm -f test[0-9] test[0-9][0-9]  sale        

.PHONY: all clean