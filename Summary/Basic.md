# 指针

## 数组指针和指针数组
>* 数组指针 （int (*p)[10]）:表示指向 lenof(int)为10的数组的首地址
```
int (*p)[10];
int a[10];
p=a;
```
>* 指针数组： (int *p[10]): p={int*,int*,......int*}

## 字符串指针
>* 字符串复制
```
void copystr(char* from,char* to){
      for(;from!='\0';from++,to++){ // for 的一种 应用；
            *to=*from;
      }
      *to='\0';
}
```

## 函数指针 和 指针函数
>* 函数指针： int (*fun)(int x,int y):    本质是一个指针、其指向一个函数
```
int max(int a,int b){
      return a:b?a>=b;
}

int min(int a,int b){
      return a:b?a<=b;
}
// 声明 函数指针：
int (*p)(int,int);

void test(){
      int m=6,n=9;
      p=max;
      int result=p(m,n);
      
      p=min;
      result=p(m,n);

}
```
>* 指针函数： int *fun(int x,int y):      本质是一个函数，其返回值为指针

# Cpp11 for循环的使用
```
int v[]{1,3,5,7,9}
//--> 1: x首先依次复制 v中的数据 然后打印
for(auto x:v){
      std::cout<<x<<std::endl;
}

// -->2：   x首先依次复制 数组中的数据然后打印
for(auto x:{2,4,6,8,10}){
      std::cout<<x<<std::endl;
}

// -->3:    使用“引用”，此时x只是v成员的别名，不会再复制数据， 直接打印v中的数据git
for(auto &x:v){
      std::cout<<x<<std::endl;
}
```