#ifndef __MAKETHREAD_HPP__
#define __MAKETHREAD_HPP__

#include <iostream>
#include <string>
#include <thread>
#include <unistd.h>

#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ > 7)
#define SLEEP_MS(time_ms) std::this_thread::sleep_for(std::chrono::milliseconds(time_ms))
#else
#define SLEEP_MS(time_ms) usleep((time_ms)*1000)
#endif

using namespace std;
// ① 创建函数作为线程入库函数
void mkThreadFun_nPar();
// {
//       cout << "Entry Function of mkThread without parm" << endl;
// }
//② 创建类，作为线程的入口地址
class mk_Th_Class
{
private:
      /*data*/
public:
      mk_Th_Class(int i) : m_i(i)
      {
      }
      ~mk_Th_Class()
      {
      }
      void operator()(int mm) ////也可以不带参数“void operator()()”    创建线程 方法②中，线程的入口地址
      {
            while (1)
            {
                  cout << "线程的类入库--开始"
                       << "--" << mm << "--" << endl;
                  // sleep(1);
                  // SLEEP_MS(2000);
                  std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                  std::this_thread::get_id(); //获取线程id
            }
      }
      void threadFun1()
      {
            cout << "方法③——1" << endl;
      }
      void threadFun2()
      {
            cout << "方法③——2" << endl;
      }

      mutable int m_i; //m_i即使实在const中也可以被修改
};

void mkThreadFun_Par_1(const int &i, char *pmybuf);
void mkThreadFun_Par_2(const int i, const string &pmybuf);
void mkThreadFun_Par_3(const mk_Th_Class &pmybuf);
void mkThreadFun_Par_3(unique_ptr<int> ptn);
#endif

/*----------------------------------------------------------
int main(int argc,char const *argv[])
{
      //----------------------------------------方法①：普通创建------------------------------------------------//
      //(1)创建了线程，线程执行起点（入口）是mkThreadFun_nPar；(2)执行线程
      thread myFirstThread(mkThreadFun_nPar);

      //(2)阻塞主线程并等待mkThreadFun_nPar执行完，当mkThreadFun_nPar执行完毕，join()就执行完毕，主线程继续往下执行
	//join意为汇合，子线程和主线程回合
      myFirstThread.join();
	//设置断点可看到主线程等待子线程的过程
	//F11逐语句，就是每次执行一行语句，如果碰到函数调用，它就会进入到函数里面
	//F10逐过程，碰到函数时，不进入函数，把函数调用当成一条语句执行

	//(3)传统多线程程序中，主线程要等待子线程执行完毕，然后自己才能向下执行
	//detach:分离，主线程不再与子线程汇合，不再等待子线程
	//detach后，子线程和主线程失去关联，驻留在后台，由C++运行时库接管
	//myThread.detach();

	//(4)joinable()判断是否可以成功使用join()或者detach()
	//如果返回true，证明可以调用join()或者detach()
	//如果返回false，证明调用过join()或者detach()，join()和detach()都不能再调用了
      if(myFirstThread.joinable()){
            cout<< "could be .. join() or detach()"<<endl;
      }
      else{
            cout<< "could not .. join() or detach()"<<endl;
      }
      //---------------------------------------方法②：使用类名作为线程入口-------------------------------------------//
      mk_Th_Class th_C;
      thread classthread(th_C,11);
      
      //------------------------------------------方法③：使用类成员函数作为入口函数-----------------------------------//
      mk_Th_Class threadObj3;
      //第一个&意思是取址，第二个&意思是引用，相当于std::ref(s)
      //thread threadC_3_1(&mk_Th_Class::threadFun1,threadObj3)传值也是可以的
      //在其他的构造函数中&obj是不会代表引用的，会被当成取地址
      //调用方式：对象成员函数地址，类实例，[成员函数参数]
	//第二个参数可以传递对象s，也可以传递引用std::ref(threadObj3)或&threadObj3
	//传递threadObj3，会调用拷贝构造函数在子线程中生成一个新的对象
	//传递&，子线程中还是用的原来的对象，所以就不能detach，因为主线程运行完毕会把该对象释放掉
      thread threadC_3_1(&mk_Th_Class::threadFun1,&threadObj3);
      thread threadC_3_2(&mk_Th_Class::threadFun2,&threadObj3);
//--------------------------- 第3讲  避坑和 线程传参----------------------//
      //--------------避坑---------------//
      int mvar1 = 1;
	int& mvary1 = mvar1;
	char mybuf1[] = "this is a test1";
	thread mynotDetach_Thread1(mkThreadFun_Par_1, mvar1, mybuf1);//第一个参数是函数名，后两个参数是函数的参数
      // mynotDetach_Thread1.detach();    线程脱离主线程“main”  后台独立运行
            //---------------------//
      int mvar2 = 1;
	int& mvary2 = mvar2;
	char mybuf2[] = "this is a test2";
      //如果detach了，这样仍然是不安全的
	//因为存在主线程运行完了，mybuf被回收了，系统采用mybuf隐式类型转换成string
	//推荐先创建一个临时对象thread myThread(myPrint, mvar, string(mybuf));就绝对安全了。。。。
	thread mynotDetach_Thread2(mkThreadFun_Par_2, mvar2, mybuf2);
	mynotDetach_Thread2.join();
	//mynotDetach_Thread2.detach();
      //-------------线程传参--------------//
            //------------传参1-----//
      mk_Th_Class myObj(10);
	//myPrint(const mk_Th_Class& pmybuf)中引用不能去掉，如果去掉会多创建一个对象
	//const也不能去掉，去掉会出错
	//即使是传递的const引用，但在子线程中还是会调用拷贝构造函数构造一个新的对象，
	//所以在子线程中修改m_i的值不会影响到主线程
	//如果希望子线程中修改m_i的值影响到主线程，可以用thread myThread(myPrint, std::ref(myObj));
	//这样const就是真的引用了，myPrint定义中的const就可以去掉了，类A定义中的mutable也可以去掉了
	thread chuanCanThread(mkThreadFun_Par_3, myObj);
	chuanCanThread.join();
	//myThread.detach();
            //----------智能指针-----//
      unique_ptr<int> up(new int(10));    //智能指针
	//独占式指针只能通过std::move()才可以传递给另一个指针
	//传递后up就指向空，新的ptn指向原来的内存
	//所以这时就不能用detach了，因为如果主线程先执行完，ptn指向的对象就被释放了
	thread ptrThread(mkThreadFun_Par_4, std::move(up));      //std::move 强制左值变右值
	ptrThread.join();
	//myThread.detach();

      threadC_3_1.join();
      threadC_3_2.join();
      classthread.join();
      mynotDetach_Thread1.join();
      cout<<"hello world"<<endl;

      return 0;
}

---------------------------------------------------------*/