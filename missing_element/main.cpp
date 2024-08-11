
#include<iostream>

using namespace std;
struct Array{
    int arr[20];
    int size;
    int length;
};
void missing_natural_number(struct Array);
void specific_range(struct Array);
void multiple_specific_range(struct Array );
void unsorted_findnum(struct Array ,int );
void display(struct Array);
int main(){
    struct Array p {{1,2,3,5,6,7,8,9,10},10,9};
     struct Array q {{6,7,8,9,10,12,13,14,15},10,9};
    struct Array r {{6,7,8,9,11,12,15,16,19},10,9};
missing_natural_number(p);
specific_range(q);
multiple_specific_range(r);
//unsorted
 struct Array t {{20,7},20,2};
 display(t);
 int max=20;
unsorted_findnum(t,max);
    
    
    return 0;
}

void missing_natural_number(struct Array p){
    int sum=0,s,n;
    for(int i=0;i<p.length;i++)
        sum+=p.arr[i];
  n=p.arr[p.length-1];
s=n*(n+1)/2;
  if(s-sum==0){
      cout<<"No missing element"<<endl;
  }
  else{
      cout<<s-sum<< "  is missing"<<endl;
  }
}

void specific_range(struct Array p){
    int i;
    int diff=p.arr[0]-0;
    for(i=0;i<p.length;i++){
        if(p.arr[i]-i!=diff){
            cout<<"Missing element is:"<<i+diff<<endl;
            break;
        }
    }
}
void multiple_specific_range(struct Array p){
    int i;
    int diff=p.arr[0]-0;
    for(i=0;i<p.length;i++){
        if(p.arr[i]-i!=diff){
            while(p.arr[i]-i>diff){
                cout<<"Missing element:"<<i+diff<<endl;
                diff++;
            }
        }
    }
}

void unsorted_findnum(struct Array p,int max){
    int* arr=new int[max+1];
    int i;
    for(i=0;i<max+1;i++){
        arr[i]=0;
    }
    for(i=0;i<p.length;i++){
        arr[p.arr[i]]=p.arr[i];
    }
    for(i=1;i<max+1;i++){
        if(arr[i]==0)
            cout<<"Missing elment:"<<i<<endl;
    }
    delete [] arr;
}
void display(struct Array p){
    cout<<endl;
    for(int i=0;i<p.length;i++){
        cout <<p.arr[i]<<" ";
    }
    cout<<endl;
}