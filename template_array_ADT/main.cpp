
#include<iostream>

using namespace std;

template<class x>
class Array{
    private:
        x* arr;
        int size;
        int length;
    public:
Array()
           : arr{new x[10]},size{10},length{0} {
}
Array(int sz)
           :arr{new x[sz]},size{sz},length{0}{
}
void display();
void insert(int index,x element);
x remove(int index);
        
    ~Array(){
        delete [] arr;
    }    
};

template <class x>
void Array<x>::display(){
    for(int i=0;i<length;i++)
      cout<<arr[i]<<"  ";
}
template<class x>
void Array<x>::insert(int index,x element){
    int i;
    if(index>=0 && index<=length){
    for(i=length;i>index;i++)
        arr[i]=arr[i-1];
    length++;
    }
    arr[index]=element;
}
template <class x>
x Array<x>::remove(int index){
    int i;
     x element=arr[index];
     if(index>=0 && index<length){
    for(i=index;i<length-1;i++)
        arr[i]=arr[i+1];
    length--;
     }
    
    return element;
}

int main(){
    Array<float> q(100);
    q.insert(0,1.0);
     q.insert(1,2.4);
      q.insert(2,3.6);
      q.insert(3,1.0);
      q.remove(3);
      q.display();
    
    return 0;
}