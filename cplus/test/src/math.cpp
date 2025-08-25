
#include <iostream>

static int s_variable = 120;

int multiply(int a, int b) {
    int res= a * b;
    return res;
}

void multiply_log(int a, int b) {
    int res= a * b;
    std::cout << "::: " << res << std::endl;

}
