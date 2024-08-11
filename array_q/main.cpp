
#include<iostream>

using namespace std;

int main(){
    int n;
    cout <<"Enter the size of array:";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
      int arr1[n];
    for(int i=0;i<n;i++){
       int multi=1;
       for(int j=0;j<n;j++){
           if(i!=j){
              multi*=arr[j];
           }
           
       }
       arr1[i]=multi;
    }
     cout<< "[ ";
      for(int i=0;i<n;i++){
        cout<<arr1[i]<< " ";
    }
     cout<< "] ";
    
    return 0;
}