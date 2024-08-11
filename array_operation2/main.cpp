
#include<iostream>

using namespace std;

struct Array{
    int  arr[50];
    int size {50};
    int length {0};
};
void display(struct Array);
void display_1(struct Array* );
void insert(struct Array*,int);
bool is_sorted(struct Array);
void negative_positive(struct Array*);
void swap(int*,int*);
struct Array* merge(struct  Array*,struct Array*);
struct Array*  Union(struct Array* ,struct Array* );
struct Array* Intersection(struct Array*,struct Array*);
struct Array* Difference(struct  Array* ,struct Array* );
int main(){
    struct Array p{{1,5,10,15,20,27,29,45,65,76},50,10};
    display(p);
    insert(&p,30);
      insert(&p,0);
     display(p);
     cout<<endl<<is_sorted(p)<<endl;
      struct Array x{{-1,-5,10,15,-20,27,29,-45,65,-76},50,10};
      negative_positive(&x);
      display(x);
      struct Array a{{10,15,20,30,45},50,5};
      struct Array b{{21,31,37,65,75},50,5};
      struct Array* c=merge(&a,&b);
      display(a);
      display(b);
      display(*c);
      struct Array a1{{10,15,20,30,45},50,5};
      struct Array b1{{8,10,12,30,50,80},50,6};
      struct Array* d=Union(&a1,&b1);
      display(a1);
      display(b1);
      cout<<endl<<"UNION"<<endl;
      display(*d);
    cout<<endl<<"INTERSECTION"<<endl;
    struct Array* e=Intersection(&a1,&b1);
    display(*e);
    cout<<e->length<<endl;
     cout<<endl<<"DIFFERENCE"<<endl;
    struct Array* f=Difference(&a1,&b1);
    display(*f);
    cout<<f->length<<endl;
    
      
     
    
    
    
    return 0;
}
void insert(struct Array * p,int element){
    int i=p->length-1;
    if(p->length==p->size)
        return;
    while( i>=0 && p->arr[i]>element){
        p->arr[i+1]=p->arr[i];
        i--;
    }
    p->arr[i+1]=element;
    p->length++;
}

void display(struct Array p){
    cout<<endl;
    for(int i=0;i<p.length;i++){
        cout <<p.arr[i]<<" ";
    }
    cout<<endl;
}
bool is_sorted(struct Array p){
    int i;
    for(i=0;i<p.length-1;i++){
        if(p.arr[i]>p.arr[i+1])
            return false;
    }
    return true;
}

void negative_positive(struct Array* p){
    int i=0;
    int j=p->length-1;
    while(i<j){
        
        while(p->arr[i]<0){
            i++;
        }
          while(p->arr[j]>=0){
            j--;
        }
        if(i<j){
            swap(&p->arr[i],&p->arr[j]);
        }
        
    }
    
}
void swap(int* a,int* b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

struct Array* merge(struct  Array* a,struct Array* b){
     struct Array* c=new struct Array;
     int i=0,j=0,k=0;
     while(i<a->length && j<b->length){
         if(a->arr[i]<b->arr[j]){
             c->arr[k++]=a->arr[i++];
         }
        else{
             c->arr[k++]=b->arr[j++];
        }
}
         while(i<a->length){
             c->arr[k++]=a->arr[i++];
         }
          while( j<b->length){
             c->arr[k++]=b->arr[j++];
          }
          
          c->length=a->length+b->length;
          
          return c;
}

struct Array*  Intersection(struct Array* a,struct Array* b){
     struct Array* c=new struct Array;
     int i=0,j=0,k=0;
     while(i<a->length && j<b->length){
        if(a->arr[i]<b->arr[j])
             i++;
        else if(b->arr[j]<a->arr[i])
             j++;
        else{
             c->arr[k++]=a->arr[i++];
             j++;
            }
     }

         
        c->length=k;
return c; 
}
struct Array* Union(struct  Array* a,struct Array* b){
     struct Array* c=new struct Array;
     int i=0,j=0,k=0;
     while(i<a->length && j<b->length){
         if(a->arr[i]<b->arr[j]){
             c->arr[k++]=a->arr[i++];
         }
        else if(b->arr[j]<a->arr[i]){
             c->arr[k++]=b->arr[j++];
        }
        else{
            c->arr[k++]=a->arr[i++];
            j++;
        }
}
         while(i<a->length){
             c->arr[k++]=a->arr[i++];
         }
          while( j<b->length){
             c->arr[k++]=b->arr[j++];
          }
          
          c->length=k;
          
          return c;
}
struct Array* Difference(struct  Array* a,struct Array* b){
     struct Array* c=new struct Array;
     int i=0,j=0,k=0;
     while(i<a->length && j<b->length){
         if(a->arr[i]<b->arr[j]){
             c->arr[k++]=a->arr[i++];
         }
        else if(b->arr[j]<a->arr[i]){
             j++;
        }
        else{
            i++;
            j++;
        }
}
         while(i<a->length){
             c->arr[k++]=a->arr[i++];
         }          
          c->length=k;
          
          return c;
}
