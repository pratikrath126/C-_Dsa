
#include<iostream>

using namespace std;
struct Array{
    int* arr;
    int size;
    int length;
};

void display(struct Array);
void append(struct Array*,int);
void insert(struct Array*,int,int);
int del(struct Array*,int);
int linearsearch(struct Array,int);
int linearsearch_1(struct Array*,int);
int linearsearch_2(struct Array*,int);
void swap(int*,int*);
int binarysearch(struct Array,int);
int Rbinarysearch(int*,int,int,int);
int get(struct Array ,int );
void set(struct Array*,int,int);
int max(struct Array);
int min(struct Array);
int sum(struct Array);
float average(struct Array);
void reverse(struct Array*);
void reverse_1(struct Array*);


int main(){
    struct Array a;
    int i,n;
    cout<<"Enter the size of array:";
    cin>>a.size;
    a.arr=new int[a.size];
    a.length=0;
    cout <<"Enter number of numbers :";
    cin>>n;
    cout<<"Enter elements of array:";
    for(i=0;i<n;i++){
        cin>>a.arr[i];
        a.length++;
    }
       display(a);
       append(&a,6);
       display(a);
       insert(&a,5,0);
       display(a);
       del(&a,5);
       display(a);
       cout<<endl<<a.length<<endl;;
       cout<<endl<<"Elemnent found at index:"<<linearsearch(a,3)<<endl;
     //   cout<<endl<<"Elemnent found at index:"<<linearsearch_1(&a,3)<<endl;
      //  display(a);
     //    cout<<endl<<"Elemnent found at index:"<<linearsearch_2(&a,3)<<endl;
       //  display(a);
        cout<<endl<<"Elemnent found at index:"<<binarysearch(a,2)<<endl;
        cout<<endl<<"Elemnent found at index:"<<Rbinarysearch(a.arr,0,a.length-1,2)<<endl;
        cout<<endl<<"Element :"<<get(a,0)<<endl;
      //    set(&a,0,0);
           cout<<endl<<"Element :"<<get(a,0)<<endl;
           cout <<endl<<"MAX:"<<max(a)<<endl;
             cout <<endl<<"MIN:"<<min(a)<<endl;
               cout <<endl<<"SUM:"<<sum(a)<<endl;
                 cout <<endl<<"AVERAGE:"<<average(a)<<endl;
                 reverse(&a);
                  display(a);
                  reverse_1(&a);
                    display(a);
                  
           
         
        
       
    
    
    return 0;
}
void display(struct Array p){
    cout<<endl;
    for(int i=0;i<p.length;i++){
        cout <<p.arr[i]<<" ";
    }
    cout<<endl;
}

void append(struct Array* p,int element){
    if(p->length<p->size){
        p->arr[p->length++]=element;
    }
    else{
        cout<<"Array Full:";
    }
}

void insert(struct Array* p,int index,int element){
    int i;
    if(index>=0 && index<=p->length){
        for( i=p->length;i>index;i--)
            p->arr[i]=p->arr[i-1];
        p->arr[i]=element;
        p->length++;
    }
    else{
        cout<<endl<<"Invalid Index"<<endl;
    }
}
int del(struct Array* p,int index){
    int x=-1,i;
    if(index>=0 && index< p->length){
        x=p->arr[index];
        for(i=index;i<p->length-1;i++){
            p->arr[i]=p->arr[i+1];
        }
        p->length--;
        return x;
    }
    else{
        cout<<endl<<"Enter Valid INDEX!!!"<<endl;
        return x;
    }
    
}

int linearsearch(struct Array  p ,int key){
    int i;
    for(i=0;i<p.length;i++){
        if(key==p.arr[i])
            return i;
    }
    cout<<endl<<"Element not Found"<<endl;
    return -1;
}

int linearsearch_1(struct Array*  p ,int key){
    int i;
    for(i=0;i<p->length;i++){
        if(key==p->arr[i]){
            swap(&p->arr[i],&p->arr[i-1]);
              return i;
        }
    }
    cout<<endl<<"Element not Found"<<endl;
    return -1;
}

int linearsearch_2(struct Array*  p ,int key){
    int i;
    for(i=0;i<p->length;i++){
        if(key==p->arr[i]){
            swap(&p->arr[i],&p->arr[0]);
              return i;
        }
    }
    cout<<endl<<"Element not Found"<<endl;
    return -1;
}

void swap(int* a,int* b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int binarysearch(struct Array p,int key){
    int  mid;
    int l=0;
    int h=p.length-1;
    while(l<=h){
        mid=(l+h)/2;
        if(p.arr[mid]==key)
            return mid;
        else if(p.arr[mid]<key)
            l=mid+1;
        else
            h=mid-1;
    }
    cout<<endl<<"Element not found!!"<<endl;
    return -1;
}

int Rbinarysearch(int* arr,int l,int h,int key){
    int mid;
    if(l<=h){
        mid=(l+h)/2;
        if(arr[mid]==key)
            return mid;
        else if(arr[mid]<key)
            return Rbinarysearch(arr,mid+1,h,key);
        else
            return Rbinarysearch(arr,l,mid-1,key);
    }
    cout<<endl<<"Element not found"<<endl;
    return -1;
}

int get(struct Array p,int index){
    return p.arr[index];
}

void set(struct Array* p,int index,int element){
    p->arr[index]=element;
}

int max(struct Array p){
    int max=p.arr[0];
    int i;
    for(i=1;i<p.length;i++){
        if(p.arr[i]>max)
            max=p.arr[i];
    }
    return max;
}

int min(struct Array p){
    int min=p.arr[0];
    int i;
    for(i=1;i<p.length;i++){
        if(p.arr[i]<min)
            min=p.arr[i];
    }
    return min;
}

int sum(struct Array p){
    int sum=0;
    for(int i=0;i<p.length;i++){
        sum+=p.arr[i];
    }
    return sum;
}

float average(struct Array p){
    return static_cast<float>(sum(p))/p.length;
}

void reverse(struct Array* p){
    int* b=new int[p->length];
    int i,j;
    for(i=0,j=p->length-1;i<p->length;i++,j--){
        b[i]=p->arr[j];
    }
    for(i=0;i<p->length;i++)
        p->arr[i]=b[i];
    delete [] b;
    
}

void reverse_1(struct Array* p){
    int i,j;
    for(i=0,j=p->length-1;i<j;i++,j--){
        swap(&p->arr[i],&p->arr[j]);
    }
}


