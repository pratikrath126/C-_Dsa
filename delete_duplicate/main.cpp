
#include<iostream>

using namespace std;

void delete_duplicate(int*,int*);
int main(){
    int size,i;
    
    cout<<"Enter size of array:";
    cin>>size;
    int* arr=new int[size];
    cout<<"Enter elements of sorted array:";
    for(i=0;i<size;i++){
          cin>>arr[i];
    }
    delete_duplicate(arr,&size);
     for(i=0;i<size;i++){
          cout<<arr[i]<<"  ";
    }
    return 0;
}
void delete_duplicate(int* arr,int* size){
  int i,j;
  for(i=0;i<*size-1;i++){
        if(arr[i]==arr[i+1]){
            for(j=i;j<*size-1;j++){
                 arr[j]=arr[j+1];
            }
            *size=*size-1;
            i--;
        }
  }
}