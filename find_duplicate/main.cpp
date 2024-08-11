
#include<iostream>

using namespace std;
struct Array{
    int arr[20];
    int size;
    int length;
};
  void find_duplicate(struct Array);
  void find_duplicate_withcount(struct Array );
  void   duplicate_withcount_hashing(struct Array);
  void unsorted_duplicate(struct Array);
int main(){
  struct Array p{{3,6,8,8,10,12,15,15,15,20},20,10};
  //sorted
  find_duplicate(p);
  cout<<endl;
  find_duplicate_withcount(p);
  cout<<endl;
  duplicate_withcount_hashing(p);
  
  //unsorted
  struct Array q {{10,5,2,4,10,3,2,12,45,12,2,7,1,2,3,4,1,11,11},20,19};
  cout<<endl;
  unsorted_duplicate(q);
  // duplicate with hashing unsorted also

    
    
    return 0;
}
void find_duplicate(struct Array p){
    int i;
    int last_duplicate=-1;
    for(i=0;i<p.length-1;i++){
        if(p.arr[i]==p.arr[i+1]  && last_duplicate!=p.arr[i]){
            cout<<"Duplicate Element:"<<p.arr[i]<<endl;
            last_duplicate=p.arr[i];
        }
    }
}
void find_duplicate_withcount(struct Array p){
    int i;
    for(i=0;i<p.length-1;i++){
        if(p.arr[i]==p.arr[i+1] ){
            int j=i+1;
            while(p.arr[j]==p.arr[i])
                j++;
        cout<<"Duplicate element:"<<p.arr[i]<<" appearing "<<j-i<<" times"<<endl;
        i=j-1;
        }
    }
}
 void   duplicate_withcount_hashing(struct Array p){
     int * arr=new int[p.arr[p.length-1]+1];
     int i;
     for(i=0;i<p.arr[p.length-1]+1;i++)
         arr[i]=0;
    for(i=0;i<p.length;i++)
        arr[p.arr[i]]++;
      for(i=1;i<  p.arr[p.length-1]+1;i++){
          if(arr[i]>1)
              cout<<"Duplicate element:"<<i<<" appearing "<<arr[i]<<" times"<<endl;
      }
      delete [] arr;
 }
 
 void unsorted_duplicate(struct Array p){
     int i,j;
     for(i=0;i<p.length-1;i++){
         int count=1;
         if(p.arr[i]!=-1){
         for(j=i+1;j<p.length;j++){
             if(p.arr[i]==p.arr[j]){
                 count++;
                 p.arr[j]=-1;
             }
         }
         if(count>1){
             cout<<"Duplicate element:"<<p.arr[i]<<" appearing "<<count<<" times"<<endl;
         }
         
         }
     }
 }