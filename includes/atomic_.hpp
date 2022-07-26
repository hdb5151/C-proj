#ifndef __ATOMIC__HPP__
#define __ATOMIC__HPP__

#include <thread>
#include <iostream>
#include <atomic>
// #include <

class th_atomic
{
public:
      th_atomic() : at1(0){};
      ~th_atomic(){};
      void th_setV(int x)
      {
            std::chrono::milliseconds dura(2000);
            std::this_thread::sleep_for(dura);
            // at1.fetch_add(x);
            at1.fetch_add(x, memory_order_release);
      };
      void th_printV()
      {
            // int y;
            // do
            // {
            //       y = at1.load();
            //       cout << "automic.load while" << endl;
            // } while (y == 0);

            // while (at1 == 0)
            // {
            //       cout << "circle" << endl;
            //       std::this_thread::yield(); //任务切换
            // }

            while (at1.load(memory_order_acquire) == 0)
            {
                  cout << "acquire" << endl;
                  std::this_thread::yield(); //任务切换
            }
            cout << "the value is " << at1 << endl;
      }

private:
      std::atomic<int> at1;
};

#endif // !__ATOMIC__HPP__#define __ATOMIC__HPP__
