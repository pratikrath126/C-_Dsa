
#include<iostream>

using namespace std;

int main(){
    int size,i;
    cout<<"Enter size of array:";
    cin>>size;
    int* arr=new int[size];
    cout<<"Enter elements array:";
    for(i=0;i<size;i++){
          cin>>arr[i];
    }
    
    int j {1};
    for(i=0;i<size;i++){
         if(arr[i]==j){
             j++;
         }
    }
    cout<<"Missing positive nums is :"<<j<<endl;
    return 0;
}