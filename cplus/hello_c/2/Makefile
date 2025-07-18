# 编译器和编译选项
CXX      = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++23 -g -O0

# 源文件与目标对应关系
SRCS     = 2-1.cpp 2-2.cpp 2-3.cpp 2-4.cpp
TARGETS  = $(SRCS:2-%.cpp=test%)

# 默认构建所有目标
all: $(TARGETS)

# 构建规则
$(TARGETS): test%: 2-%.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# 清理
clean:
	rm -f $(TARGETS)

.PHONY: all clean  # 这行声明all和clean是伪目标（phony targets）