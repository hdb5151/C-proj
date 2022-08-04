#include "makeThread.hpp"
using namespace std;
// ① 创建函数作为线程入库函数
void mkThreadFun_nPar()
{
      cout << "Entry Function of mkThread without parm" << endl;
}

/*----避坑-------传参-1-----*/
void mkThreadFun_Par_1(const int &i, char *pmybuf)
{
      //如果线程从主线程detach了
      //i不是mvar真正的引用，实际上值传递，即使主线程运行完毕了，子线程用i仍然是安全的，但仍不推荐传递引用
      //推荐改为const int i
      cout << i << endl;
      //pmybuf还是指向原来的字符串，所以这么写是不安全的
      cout << pmybuf << endl;
}
void mkThreadFun_Par_2(const int i, const string &pmybuf)
{
      cout << i << endl;
      cout << pmybuf << endl;
}

void mkThreadFun_Par_3(const mk_Th_Class &pmybuf)
{
      pmybuf.m_i = 199;
      cout << "子线程myPrint的参数地址是" << &pmybuf << "thread = " << std::this_thread::get_id() << endl;
}

/*----传智能指针-----*/
void mkThreadFun_Par_4(unique_ptr<int> ptn)
{
      cout << "thread = " << std::this_thread::get_id() << endl;
}