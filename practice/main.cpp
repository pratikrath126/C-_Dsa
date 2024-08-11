
#include<iostream>

//1.array inside structure is call by value if pased inside a function
//(is copied);
int main(){
    int * arr=new int[10];
    arr[0]=0;
    arr[1]=1;
    arr[2]=2;
    arr++;
    arr++;
   std::cout<<*arr;
    return 0;
}