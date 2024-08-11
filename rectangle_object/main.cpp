
#include<iostream>

using namespace std;

class rectangle{
    private:
        int length;
        int width;
    public:
        rectangle(int l,int b): length{l},width{b}{
        }
        int area(){
            return length*width;
        }
        void change_length(int l){
            length=l;
        }
};
int main(){
    rectangle r(10 ,20 );
   cout<<r.area()<<endl;
    return 0;
}