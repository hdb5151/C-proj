#ifndef __CONDITION_VAR_HPP__
#define __CONDITION_VAR_HPP__

#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <list>
#include <mutex>
#include <condition_variable>

using namespace std;

class CONDITION_VAR
{
public:
      void inMsgRecvQueue()
      {
            for (int i = 0; i < 10000; i++)
            {
                  cout << "inMsgRecvQueue()执行，插入一个元素" << i << endl;

                  std::unique_lock<std::mutex> sbguard(my_mutex);
                  msgRecvQueue.push_back(i);

                  //假如outMsgRecvQueue（）正在处理一个事务，需要一段时间，而不是正卡在wait()那里等待你的唤醒，
                  //那么此时这个notify_one（）这个调用也许就没效果；
                  my_cond.notify_one(); //我们尝试把wait()线程唤醒,执行完这行，那么outMsgRecvQueue()里面的wait()就会被唤醒
                                        //唤醒之后的事情后续研究；
                                        //my_cond.notify_all(); //通知所有线程
                                        //...
                                        //其他处理代码
            }
      }

      //把数据从消息队列取出的线程
      void outMsgRecvQueue()
      {
            int command = 0;

            while (true)
            {
                  std::unique_lock<std::mutex> sbguard(my_mutex);

                  //wait()用来等一个东西
                  //如果第二个参数lambda表达式返回值是true,那么wait()直接返回；
                  //如果第二个参数lambda表达式返回值是false,那么wait()将解锁互斥量，并且堵塞到本行
                  //那堵到什么时候为止？堵塞到其他线程调用notify_one()成员函数为止。
                  //如果wait()没有第二个参数：my_cond.wait(sbguard）；那么就跟第二个参数返回false效果一样，
                  //那么wait()将解锁互斥量，并且堵塞到本行，堵塞到其他线程调用notify_one()成员函数为止。

                  //但其他线程用notify_one()将本wait(原来是睡着/堵塞)的状态唤醒后，wait()就开始恢复干活了，那恢复后的
                  //wait()干什么活？
                  //a)wait()不断的尝试重新获取互斥量锁，如果获取不到，那么流程就卡在wait()这里等着获取，如果获取到了互斥锁，
                  //那么wait()就继续执行b
                  //b)上锁（实际上获取锁了就等于上了锁）
                  //b.1)如果wait有第二个参数（lamdba）,就判断这个lamdba表达式，如果表达式为false,
                  //那么wait()又对互斥量解锁然后又休眠，这里继续等待再次被notify_one()唤醒
                  //b.2)如果lamdba表达式为true,则wait()返回，流程走下来（此时互斥锁被锁着）
                  //b.3)如果wait()没有第二个参数,则wait()返回，流程走下来
                  //为防止虚假唤醒：wait()中要有第二个参数（lambda）并且这个lambda中要正确处理公共数'
                  // 据是否存在
                  my_cond.wait(sbguard, [this] { //一个lambda就是一个可调用对象（函数）
                        if (!msgRecvQueue.empty())
                              return true;
                        return false;
                  });
                  //流程能走到 这里来，这个互斥锁一定是锁着的。同时msgRecvQueue至少有一条数据的
                  command = msgRecvQueue.front();
                  msgRecvQueue.pop_front();
                  sbguard.unlock(); //因为unique_lock的灵活性，所以我们可以随时解锁，以免锁住太长时间

                  cout << "outMsgRecvQueue()执行，取出一个元素" << command << endl;
            } //end while
      }

private:
      std::list<int> msgRecvQueue;     //容器（消息队列），代表玩家发送过来的命令。
      std::mutex my_mutex;             //创建一个互斥量（一把锁）
      std::condition_variable my_cond; //生成一个条件变量对象
};
#endif // !_      std::chrono::time_point  = std::chrono::hight_resolution_clock::now() +
/*    std::condition_variable::wait_for(std::unique_lock,std::chrono::duration)           //std::chrono::duration = std::chrono::milliseconds(num)
 *    std::condition_variable::wait_until(std::unique_lock,std::chrono::time_point)       //std::chrono::time_point = td::chrono::steady_clock::now()+
 *
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */
