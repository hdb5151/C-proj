#ifndef __TH_FRUTURE_HPP__
#define __TH_FRUTURE_HPP__

#include <iostream>   // std::cout
#include <functional> // std::ref
#include <thread>     // std::thread
#include <future>     // std::promise, std::future
#include <queue>
using namespace std;

class th_pro_Fut
{
public:
      th_pro_Fut() : fut(prom.get_future()){}; //构造函数中  将promise 和future 关联起来
      void pro_setV()
      {
            cout << "will wait for 2s" << endl;
            std::chrono::milliseconds dura(5000);
            // std::chrono::duration<int, std::ratio<60>>
            std::this_thread::sleep_for(dura);
            cout << "promise will set value" << endl;
            prom.set_value(10);
            cout << "the value is %d" << 10 << endl;
      };
      void fut_getV()
      {
            int result = 0;
            cout << "the future is wait for ..." << endl;

            if (fut.valid())
                  cout << "the future is valid" << endl;
            else
                  cout << "the future is ERR" << endl;

            cout << "will wait the value be setted for 1s" << endl;
            std::chrono::milliseconds dura(1000);
            if (fut.wait_for(dura) == std::future_status::timeout)
                  cout << "future wait timeout" << endl;
            fut.wait();

            cout << "the future.value has been setted" << endl;

            result = fut.get();
            cout << "the result is %d" << result << endl;
      };
      ~th_pro_Fut(){};

private:
      std::promise<int> prom; // 生成一个 std::promise<int> 对象.
      std::future<int> fut;   // 和 future 关联.
};

// class th_pack_fut
// {
// public:
//       th_pack_fut(){
//           // pck = std::move(this->pck_mov);
//       };
//       int pck_mov(int a, int b)
//       {
//             int c = 0;
//             cout << "测试 package_task 构造" << endl;
//             c = a + b;
//             return c;
//       };

//       ~th_pack_fut(){};

// private:
//       std::packaged_task<int(int, int)> pck;
//       std::future<int> fut1;
// };

//  packaged_task  在类中如何定义声明。。。。
#endif