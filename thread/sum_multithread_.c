

/*
多任务（线程）竞争导致的加和输出不稳定，
通过 互斥锁保证结果正确
参考：
    [B站，CPU眼里的：竞争 | 线程切换 | 上下文](https://www.bilibili.com/video/BV1fT4y1177R/?p=22&spm_id_from=pageDriver)


错误程序：
int sum=0;
void *task(void* ptr){
    for(int i=0; i<1000; i ++)
    {
        sum++;
        usleep(10);
    }
}

编译执行：
gcc test.c -lpthread
for i in {1..40}; do ./a.out ; done
结果不确定！！！
*/

// #include <iostream>  //头文件
// using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int sum=0;
pthread_mutex_t lock;
void *task(void* ptr){
    for(int i=0; i<1000; i ++)
    {
        pthread_mutex_lock(&lock);  // 采用互斥锁结果稳定！！
        sum++;
        pthread_mutex_unlock(&lock);
        usleep(10);
    }
}


int main()
{   
    pthread_t thread1, thread2;
    pthread_create(&thread1, 0, task, 0);
    pthread_create(&thread2, 0, task, 0);
    pthread_join(thread1, 0);
    pthread_join(thread2, 0);


    printf("%d \n", sum);
    // sleep(10000000);

}
