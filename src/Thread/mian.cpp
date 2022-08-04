#include "condition_var.hpp"
#include "makeThread.hpp"
#include "mutex_lock.hpp"
#include "th_future.hpp"
#include "atomic_.hpp"

using namespace std;

int max(int a, int b) {
    // int relt = a >= b ? a : b;
    return a >= b ? a : b;
}

int min(int a, int b) {
    // int relt = a <= b ? a  : b;
    return a <= b ? a : b;
}
int (*p)(int, int);
int main(int argv, char **argc) {
    // int(*p)[10]; //定义数组指针 --> 指向数组的首地址；
    // int a[3][10];
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 10; j++)
    //     {
    //         a[i][j] = i + j;
    //     }
    // }
    // p = a;
    // int *q = (int *)p;
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 10; j++)
    //     {
    //         printf("%d", *q);
    //         q++;
    //     }
    //     printf("-----------------\n");
    //     p++;
    //     q = (int *)p;
    // }
    int m = 11, n = 9;
    p = max;
    int result = p(m, n);
    printf("max=%d\n", result);
    p = min;
    result = p(m, n);
    printf("min=%d\n", result);
}