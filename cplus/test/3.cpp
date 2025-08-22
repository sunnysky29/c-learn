#include "header/all.h"
#include <iostream>
#include <cstdio>

using namespace std;

int main() {

    for (int i=0; i<5;i++){
 
        string message = "hello-- " + to_string(i);
        log_message11(message);

        log_message11("dsadwe");

    }
    

    return 0;
}