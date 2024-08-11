
#include<iostream>

using namespace std;

template <class t>
class arithmetic{
     private:
         t a;
         t b;
      public:
          arithmetic(t a,t b);
          t add();
          t sub();
             
};
template<class t>
arithmetic<t>::arithmetic(t a,t b){
    this->a=a;
    this->b=b;
}
template<class t>
t arithmetic<t>::add(){
    return a+b;
}
template<class t>
t arithmetic<t>::sub(){
    return a-b;
}

int main(){
    arithmetic<float> x(10.5,10);
    cout<<x.add()<<endl;
    cout <<x.sub()<<endl;
    return 0;
}