
#include<iostream>

using namespace std;
struct Array{
    int arr[10];
    int size;
    int length;
};
void missing_natural_number(struct Array);
int main(){
    struct Array p {{1,2,3,5,6,7,8,9,10},10,9};
    
missing_natural_number(p);
    
    
    return 0;
}

void missing_natural_number(struct Array p){
    int sum=0,s,n;
    for(int i=0;i<p.length;i++)
        sum+=p.arr[i];
  n=p.arr[p.length-1];
s=n*(n-1)/2;
  if(s-sum==0){
      cout<<"No missing element"<<endl;
  }
  else{
      cout<<s-sum<< "  is missing"<<endl;
  }
}
