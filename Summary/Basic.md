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