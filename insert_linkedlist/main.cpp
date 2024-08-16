
#include<iostream>

using namespace std;
using namespace std;
struct node{
   int data;
   struct node* next; 
}*first=NULL,*start=NULL,*last=NULL;
void create(int arr[],int n);
void display(struct node* first);
void insert(int pos,int key);
void insert_last(int);
void insert_sorted(struct node*,int);
void insert_sorted_2(struct node* p,int value);
int delete_node(int position);
int is_sorted(struct node* p);
void remove_duplicates(struct node* p);
void reverse(struct node* p);
void reverse_1(struct node*);
void reverse_2(struct node*,struct node*);
void concatenate(struct node*,struct node*);
int main(){
    int arr[] {1,1,2,3,3,4,5,6,7,7,7,8,9,10,10};

    create(arr,15);

    if(is_sorted(first))
      cout<<"LIST IS SORTED"<<endl;
    else
          cout<<"LIST IS NOT SORTED"<<endl;
    remove_duplicates(first);
    reverse_2(NULL,first);
  //  display(first);
  // insert(0,0);
 //   insert_sorted(first,91);
 //   insert_sorted(first,12);
//insert_sorted(first,7);
 //   cout<<"DELETED ELEMENT:"<<delete_node(1)<<endl;
   // display(first);
    cout<<endl;
    insert_last(0);
    insert_last(1);
    insert_last(2);
    insert_last(3);
    insert_last(4);
    insert_last(5);
    cout<<"LIST 2"<<endl;
   // display(start);
    concatenate(first,start);
    display(first);
    
    return 0;
}
void create(int arr[],int n){
    struct node* last,*t;
    first=new struct node;
    first->data=arr[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=new struct node;
        t->data=arr[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void display(struct node* first){
   struct node* p=first;
   while(p!=NULL){
       cout<<p->data<<"\t";
       p=p->next;
   }
   cout<<endl;
}
void insert(int pos,int key){
    struct node* p,*temp;
    if(pos==0){
        p= new struct node;
        p->data=key;
        p->next=first;
        first=p;
    }
    else if(pos>0){
        temp=first;
        for(int i=0;i<pos-1 && temp!=NULL;i++){
            temp=temp->next;
        }
        if(temp){
            p=new struct node;
            p->data=key;
            p->next=temp->next;
            temp->next=p;
        }
        else
            cout<<"INVALID POSITION"<<endl;
    }
    else if(pos<0)
          cout<<"INVALID POSITION"<<endl;
}
void insert_last(int value){
    struct node*p =new struct node;
    p->data=value;
    p->next=NULL;
    if(start==NULL)
        start=last=p;
    else{
        last->next=p;
        last=p;
    }
}
void insert_sorted(struct node* p,int value){
    struct node* x,*prev=NULL;
    x=new struct node;
    x->data=value;
    x->next=NULL;
    if(first==NULL)
        first=x;
    else{
        while(p!=NULL && p->data<value){
            prev=p;
            p=p->next;
        }
        if(p==first){
            x->next=first;
            first=x;
        }
        else{
            x->next=prev->next;
            prev->next=x;
        }
    }
}
void insert_sorted_2(struct node* p,int value){
    struct node* x;
    x=new struct node;
    x->data=value;
    x->next=NULL;
    if(first==NULL)
        first=x;
    else if(first->data>value){
        x->next=first;
        first=x;
    }
    else{
        while(p->next!=NULL && p->next->data <value){
            p=p->next;
        }
        x->next=p->next;
        p->next=x;
    }
}
int delete_node(int position){
    struct node* q,*p;
    if(first==NULL){
        cout<<"LIST EMPTY"<<endl;
        return -1;
    }
   else if(position<=0){
       cout<<"INVALID POSITION"<<endl;
       return -1;
   }
else if(position==1){
    q=first;
    first=first->next;
    int x=q->data;
    delete q;
    return x;
}  
else{
    q=NULL;
    p=first;
    for(int i=0;i<position-1 && p!=NULL ;i++){
        q=p;
        p=p->next;
    }
    if(p){
        q->next=p->next;
        int x=p->data;
        delete p;
        return x;
    }
    else{
        cout<<"INVALID POSITION"<<endl;
        return -1;
    }
}
}
int is_sorted(struct node* p){
    int x=INT_MIN;
    while(p!=NULL){
        if(p->data<x)
            return 0;
        x=p->data;
        p=p->next;
    }
    return 1;
}
void remove_duplicates(struct node* p){
    if(p==NULL)
        cout<<"LIST IS EMPTY"<<endl;
    else{
        struct node* prev=p,*after=p->next;
        while(after!=NULL){
            if(prev->data!=after->data){
                prev=after;
                after=after->next;
            }
            else{
                prev->next=after->next;
                delete after;
                after=prev->next;
            }
        }
    }
}
void reverse(struct node* p){
    int count=0;
    struct node*q=p;
    while(q!=NULL){
        count++;
        q=q->next;
    }
    int * arr=new int[count];
    int i=0;
    q=p;
    while(q!=NULL){
        arr[i++]=q->data;
        q=q->next;
    }
    i--;
    q=p;
    while(q!=NULL){
        q->data=arr[i--];
        q=q->next;
    }
}
 void reverse_1(struct node*p){
     struct node*r=NULL,*q=NULL;
     while(p!=NULL){
         r=q;
         q=p;
         p=p->next;
         q->next=r;
     }
     first=q;
 }
 void reverse_2(struct node* p,struct node* n){
     if(n!=NULL){
         reverse_2(n,n->next);
         n->next=p;
     }
     else{
         first=p;
     }
 }
 void concatenate(struct node* p,struct node* q){
     while(p->next!=NULL)
         p=p->next;
    p->next=q;
    q=NULL;
 }
 