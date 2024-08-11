
#include<iostream>

using namespace std;

struct Array{
    int arr[20];
    int size;
    int length;
};
void pair_sum(struct Array,int);
void hash_pair_sum(struct Array,int,int);
void sorted_pair_sum(struct Array,int);
void max_min(struct Array);
int main(){
   struct Array a{{7,2,3,6,4,8,1,5,10,11,1,3,9},20,13};
   pair_sum(a,10);
   cout<<endl;
   hash_pair_sum(a,12,10);
    struct Array b{{-3,-2,-1,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},20,18};
    cout<<endl;
    sorted_pair_sum(b,10);
    max_min(a);
    max_min(b);
    return 0;
}
void pair_sum(struct Array p,int sum){
    int i,j;
    for(i=0;i<p.length-1;i++){
        for(j=i+1;j<p.length;j++){
            if(p.arr[i]+p.arr[j]==sum)
                cout<<p.arr[i]<<"+"<<p.arr[j]<<"="<<sum<<endl;
        }
    }
}
void hash_pair_sum(struct Array p,int max,int sum){
    int i;
    int arr[max+1] {0};
    for(i=0;i<p.length;i++){
        if(arr[sum-p.arr[i]]!=0 && sum-p.arr[i]>=0)
              cout<<p.arr[i]<<"+"<<sum-p.arr[i]<<"="<<sum<<endl;
        arr[p.arr[i]]++;
    }
}
void sorted_pair_sum(struct Array p,int sum){
    int i=0,j=p.length-1;
    while(i<j){
        if(p.arr[i]+p.arr[j]==sum){
            cout<<p.arr[i]<<"+"<<p.arr[j]<<"="<<sum<<endl;
            i++;
            j--;
        }
        else if(p.arr[i]+p.arr[j]<sum)
            i++;
        else
            j--;
    }
}
void max_min(struct Array p){
    int max=p.arr[0];
    int min=p.arr[0];
    for(int i=0;i<p.length;i++){
        if(p.arr[i]<min)
            min=p.arr[i];
        else if(p.arr[i]>max)
            max=p.arr[i];
    }
    cout<<endl<<"Max:"<<max<< " and "<<"Min:"<<min<<endl;
}