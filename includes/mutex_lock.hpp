#ifndef __MUTEX_LOCK_HPP__
#define __MUTEX_LOCK_HPP__

#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <list>
#include <mutex>

using namespace std;
class MUTEX_LOCK
{
public:
      MUTEX_LOCK(){};
      ~MUTEX_LOCK(){};
      //把收到的消息入到一个队列的线程
      void inMsgRecvQueue()
      {
            for (int i = 0; i < 10000; i++)
            {
                  cout << "inMsgRecvQueue()执行，插入一个元素" << i << endl;
                  my_mutex.lock();
                  msgRecvQueue.push_back(i); //假设这个数字i就是收到的命令，直接弄到消息队列里边来；
                  my_mutex.unlock();
            }
      }

      bool outMsgLULProc(int &command)
      {
            my_mutex.lock();
            if (!msgRecvQueue.empty())
            {
                  //消息不为空
                  command = msgRecvQueue.front(); //返回第一个元素，但不检查元素是否存在
                  msgRecvQueue.pop_front();       //移除第一个元素。但不返回；
                  my_mutex.unlock();              //所有分支都必须有unlock()
                  return true;
            }
            my_mutex.unlock();
            return false;
      }
      //把数据从消息队列取出的线程
      void outMsgRecvQueue()
      {
            int command = 0;
            for (int i = 0; i < 10000; i++)
            {
                  bool result = outMsgLULProc(command);

                  if (result == true)
                  {
                        cout << "outMsgRecvQueue()执行，取出一个元素" << endl;
                        //处理数据
                  }
                  else
                  {
                        //消息队列为空
                        cout << "inMsgRecvQueue()执行，但目前消息队列中为空！" << i << endl;
                  }
            }
            cout << "end!" << endl;
      }

private:
      std::list<int> msgRecvQueue; //容器（消息队列），代表玩家发送过来的命令。
      std::mutex my_mutex;
};

class MUTEX_LOCK_GUARD
{
public:
      //把收到的消息入到一个队列的线程
      void inMsgRecvQueue()
      {
            for (int i = 0; i < 10000; i++)
            {
                  cout << "inMsgRecvQueue()执行，插入一个元素" << i << endl;
                  { //大括号提前结束lock_guard生命周期
                        std::lock_guard<std::mutex> sbguard(my_mutex);
                        //my_mutex.lock();
                        msgRecvQueue.push_back(i); //假设这个数字i就是收到的命令，直接弄到消息队列里边来；
                                                   //my_mutex.unlock();
                  }
            }
      }

      bool outMsgLULProc(int &command)
      {
            std::lock_guard<std::mutex> sbguard(my_mutex); //sbguard时对象名
            //lock_guard构造函数里执行了mutex::lock()
            //lock_guard析构函数里执行了mutex::unlock()
            //my_mutex.lock();
            if (!msgRecvQueue.empty())
            {
                  //消息不为空
                  command = msgRecvQueue.front(); //返回第一个元素，但不检查元素是否存在
                  msgRecvQueue.pop_front();       //移除第一个元素。但不返回；
                  //my_mutex.unlock();  //所有分支都必须有unlock()
                  return true;
            }
            //my_mutex.unlock();
            return false;
      }
      //把数据从消息队列取出的线程
      void outMsgRecvQueue()
      {
            int command = 0;
            for (int i = 0; i < 10000; i++)
            {
                  bool result = outMsgLULProc(command);

                  if (result == true)
                  {
                        cout << "outMsgRecvQueue()执行，取出一个元素" << endl;
                        //处理数据
                  }
                  else
                  {
                        //消息队列为空
                        cout << "inMsgRecvQueue()执行，但目前消息队列中为空！" << i << endl;
                  }
            }
            cout << "end!" << endl;
      }

private:
      std::list<int> msgRecvQueue; //容器（消息队列），代表玩家发送过来的命令。
      std::mutex my_mutex;         //创建一个互斥量（一把锁
};

class LOCK_LOCK
{
      //把收到的消息入到一个队列的线程
      void inMsgRecvQueue()
      {
            for (int i = 0; i < 10000; i++)
            {
                  cout << "inMsgRecvQueue()执行，插入一个元素" << i << endl;

                  std::lock(my_mutex1, my_mutex2); //相当于每个互斥量都调用了.lock()

                  msgRecvQueue.push_back(i); //假设这个数字i就是收到的命令，直接弄到消息队列里边来；
                  my_mutex2.unlock();
                  my_mutex1.unlock();
            }
      }

      bool outMsgLULProc(int &command)
      {
            std::lock(my_mutex1, my_mutex2);
            if (!msgRecvQueue.empty())
            {
                  //消息不为空
                  command = msgRecvQueue.front(); //返回第一个元素，但不检查元素是否存在
                  msgRecvQueue.pop_front();       //移除第一个元素。但不返回；
                  my_mutex2.unlock();
                  my_mutex1.unlock(); //所有分支都必须有unlock()
                  return true;
            }
            my_mutex2.unlock();
            my_mutex1.unlock();
            return false;
      }
      //把数据从消息队列取出的线程
      void outMsgRecvQueue()
      {
            int command = 0;
            for (int i = 0; i < 10000; i++)
            {
                  bool result = outMsgLULProc(command);

                  if (result == true)
                  {
                        cout << "outMsgRecvQueue()执行，取出一个元素" << endl;
                        //处理数据
                  }
                  else
                  {
                        //消息队列为空
                        cout << "inMsgRecvQueue()执行，但目前消息队列中为空！" << i << endl;
                  }
            }
            cout << "end!" << endl;
      }

private:
      std::list<int> msgRecvQueue; //容器（消息队列），代表玩家发送过来的命令。
      std::mutex my_mutex1;        //创建一个互斥量（一把锁）
      std::mutex my_mutex2;        //创建一个互斥量
};

class LOCK_UNIQUE
{
      void inMsgRecvQueue()
      {
            for (int i = 0; i < 10000; i++)
            {
                  cout << "inMsgRecvQueue()执行，插入一个元素" << i << endl;
                  {
                        std::unique_lock<std::mutex> sbguard(my_mutex, std::try_to_lock); //1、std::adopt_lock --- 2、std::try_to_lock --- 3、std::defer_lock
                        if (sbguard.owns_lock())
                        {
                              //拿到了锁
                              msgRecvQueue.push_back(i);
                              //...
                              //其他处理代码
                        }
                        else
                        {
                              //没拿到锁
                              cout << "inMsgRecvQueue()执行，但没拿到锁头，只能干点别的事" << i << endl;
                        }
                  }
            }
      }

      bool outMsgLULProc(int &command)
      {
            my_mutex.lock(); //要先lock(),后续才能用unique_lock的std::adopt_lock参数
            std::unique_lock<std::mutex> sbguard(my_mutex, std::adopt_lock);

            std::chrono::milliseconds dura(20000);
            std::this_thread::sleep_for(dura); //休息20s

            if (!msgRecvQueue.empty())
            {
                  //消息不为空
                  command = msgRecvQueue.front(); //返回第一个元素，但不检查元素是否存在
                  msgRecvQueue.pop_front();       //移除第一个元素。但不返回；

                  return true;
            }
            return false;
      }
      //把数据从消息队列取出的线程
      void outMsgRecvQueue()
      {
            int command = 0;
            for (int i = 0; i < 10000; i++)
            {
                  bool result = outMsgLULProc(command);

                  if (result == true)
                  {
                        cout << "outMsgRecvQueue()执行，取出一个元素" << endl;
                        //处理数据
                  }
                  else
                  {
                        //消息队列为空
                        cout << "inMsgRecvQueue()执行，但目前消息队列中为空！" << i << endl;
                  }
            }
            cout << "end!" << endl;
      }

private:
      std::list<int> msgRecvQueue; //容器（消息队列），代表玩家发送过来的命令。
      std::mutex my_mutex;         //创建一个互斥量（一把锁|）
};
#endif // !__MUTEX_LOCK_HPP__
