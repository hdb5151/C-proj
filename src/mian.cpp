#include "condition_var.hpp"
#include "makeThread.hpp"
#include "mutex_lock.hpp"
#include "th_future.hpp"
#include "atomic_.hpp"

using namespace std;

int t_f_e_sum = 0;
void test_for_each(int test)
{
    t_f_e_sum += test;
}
// int main()
// {
//     std::vector<int> v1 = {1, 2, 3, 4};
//     int sum = 0;
//     for (int vi : v1)
//     {
//         sum += vi;
//     }
//     cout << "the sum is -->" << sum << '\n'
//          << "the size is -->" << v1.size() << endl;

//     std::for_each(v1.begin(), v1.end(), test_for_each); //从迭代器iter.begin()～v1.end() 每一个 都调用一次test_for_each函数
//     int lambda_sum = 0;
//     std::for_each(v1.begin(), v1.end(), [&](int vv) { // lambda 表达式
//         lambda_sum += vv;
//     });

//     return 0;
// }

int main(int argv, char **argc)
{
    int(*p)[10]; //定义数组指针 --> 指向数组的首地址；
    int a[3][10];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            a[i][j] = i + j;
        }
    }
    p = a;
    int *q = (int *)p;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d", *q);
            q++;
        }
        printf("-----------------\n");
        p++;
        q = (int *)p;
    }
}