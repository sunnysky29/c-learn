
/*
枚举

*/
#include "header/all.h"
#include <iostream>
#include <cstdio>
#include <cstring>  // for memset


using namespace std;

#define log_(message) cout << "..." << message << endl;

class Log{
public:
    enum Level
    {
        log_level_err =0, log_level_warning, log_level_info
    };

private:
    Level log_level = log_level_info;

public:

    void set_level(Level level){
        log_level = level;
    }

    void print_err(const char* message){
        if (log_level >= log_level_err)
            cout << "[ERROR]: "<< message << endl;
    }

    void print_warn(const char* message){
        if (log_level >= log_level_warning)
            cout << "[WARNING]: "<< message << endl;
    }

    void print_info(const char* message){
        if (log_level >= log_level_info)
            cout << "[INFO]: "<< message << endl;
    }

};



int main() {

    Log log;
    log.set_level(Log::log_level_warning);

    log.print_warn("hello !!");
    log.print_err("hello !!");
    log.print_info("hello !!");


    return 0;
}