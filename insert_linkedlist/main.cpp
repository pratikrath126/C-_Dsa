
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
int main(){
    int arr[] {1,2,3,4,5,6,7,8,9,10};
    
    insert(0,0);
    insert_sorted(first,-1);
    insert_sorted(first,12);
    insert_sorted(first,7);
    display(first);
    cout<<endl;
    insert_last(0);
    insert_last(1);
    insert_last(2);
    insert_last(3);
    insert_last(4);
    insert_last(5);
    cout<<"LIST 2"<<endl;
    display(start);
    
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