
#include<iostream>

using namespace std;
struct node{
    struct node* prev;
    int data;
    struct node* next;
}*first=NULL;
void create(int arr[] ,int n);
void display(struct node* p);
int count(struct node* p);
void insert(struct node* p,int position,int data);
int delete_node(struct node*,int);
void reverse(struct node*);
int main(){
   int arr[] {1,2,3,4,5,6,7,8,9,10};
create(arr,1);
 //  insert(first,0,0);
  // delete_node(first,1);
   cout<<count(first)<<endl;
   reverse(first);
   display(first);
    return 0;
}
void create(int arr[] ,int n){
    struct node* last;
    struct node* q=new struct node;
    q->data=arr[0];
    first=last=q;
    first->prev=first->next=NULL;
    for(int i=1;i<n;i++){
         struct node* p=new struct node;
         p->data=arr[i];
         p->next=last->next;
         last->next=p;
         p->prev=last;
         last=p;
    }
}
void display(struct node* p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
}
int  count(struct node* p){
    int count=0;
    while(p!=NULL){
        count ++;
        p=p->next;
    }
    return count;
}
void insert(struct node* p,int position,int data){
    if(position==0){
        struct node* q=new struct node;
        q->data=data;
        q->prev=NULL;
        q->next=p;
        if(first)
            first->prev=q;
        first=q;
    }
    else if(position<0)
         cout<<"Invalid position"<<endl;
    else{
        for(int i=1;i<position && p!=NULL;i++)
            p=p->next;
    
    if(p){
         struct node* q=new struct node;
        q->data=data;
        q->next=p->next;
        q->prev=p;
        if(p->next)
            q->next->prev=q;
        p->next=q;
    }
    else
        cout<<"Invalid position"<<endl;
    }
}
int delete_node(struct node* p,int position){
    if(position<=0 || position >count(p))
        return -1;
    else if(p==NULL)
        return -1;
    else if(position==1){
        int x=p->data;
        first=first->next;
        delete p;
        if(first)
            first->prev=NULL;
        return x;
    }
    else{
        for(int i=1;i<position;i++)
            p=p->next;
        p->prev->next=p->next;
        if(p->next)
            p->next->prev=p->prev;
        int x=p->data;
        delete p;
        return x;
    }
}
void reverse(struct node* p){
    struct node* temp;
    if(p==NULL)
        return;
    while(p){
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
         p=p->prev;
        if(p && p->next==NULL)
            first=p;
    }
}