
#include<iostream>

using namespace std;

int main(){
    int arr[3][4] {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            cout<<arr[i][j]<<"\t";
        }
        cout<<"\n";
    }
    int* arr_halfdynamic[3];// stack
    arr_halfdynamic[0]=new int[4];//heap
    arr_halfdynamic[1]=new int[4];//heap
    arr_halfdynamic[2]=new int[4];//heap
    cout<<endl;
    cout<<"Enter elements of array:";
    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            cin>>arr_halfdynamic[i][j];
        }
    }
     for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            cout<<arr_halfdynamic[i][j]<<"\t";
        }
        cout<<"\n";
    }
    for(i=0;i<3;i++){
        delete [] arr_halfdynamic[i];
    }
    
    
   
    int **arr_dynamic;
    arr_dynamic=new int*[3];
    arr_dynamic[0]=new int[4];
    arr_dynamic[1]=new int[4];
    arr_dynamic[2]=new int[4];
    
    cout<<"Enter elements of array:";
    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            cin>>arr_dynamic[i][j];
        }
    }
     for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            cout<<arr_dynamic[i][j]<<"\t";
        }
        cout<<"\n";
    }
    for(i=0;i<3;i++){
        delete [] arr_dynamic[i];
    }
    delete [] arr_dynamic;
    arr_dynamic=NULL;
    
    return 0;
}