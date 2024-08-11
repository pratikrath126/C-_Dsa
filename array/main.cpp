
#include<iostream>

using namespace std;

int main(){
      int arr[] {1,2,4,6};
      cout<<2[arr]<<endl;
      cout<<*(arr+3)<<endl;
    for(int i=0;i<4;i++){
        cout<<&arr[i]<<endl;
    }
         //increasing array size;
         int* arr1=new int[5];
    arr1[0]=1;
     arr1[1]=2;
      arr1[2]=3;
       arr1[3]=4;
        arr1[4]=5;
    int* arr2=new int[10];
        for(int i=0;i<5;i++){
        arr2[i]=arr1[i];
    }
    delete [] arr1;
    arr1=arr2;
    arr2=NULL;
    for(int i=0;i<10;i++){
        cout <<arr1[i]<<endl;
    }
    
    return 0;
}