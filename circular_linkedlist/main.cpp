
#include<iostream>

using namespace std;
struct node{
    int data;
    struct node* next;
}*head;
void create_circular(int arr[],int n);
void display(struct node* h);
void Rdisplay(struct node* h);
void insert(struct node* p,int position,int data);
void insert_1(struct node* p,int position,int data);
int delete_node(struct node* p,int position);
int count(struct node*);
int main(){
   int arr[] {1,2,3,4,5,6,7,8,9,10};
   create_circular(arr,1);
   insert_1(head,11,0);
 cout<<endl<<delete_node(head,1)<<endl;
   Rdisplay(head);
     insert_1(head,5,0);
      Rdisplay(head);
    return 0;
}
void create_circular(int arr[],int n){
    head=(struct node*)malloc(sizeof(struct node));
    struct node*last=head;
    head->data=arr[0];
    last->next=head;
   int i=1;
   while(i<n){
       struct node* q=(struct node*)malloc(sizeof(struct node));
       q->data=arr[i];
       q->next=last->next;
       last->next=q;
       last=q;
       i++;
   }
}
void display(struct node* h){
     if(h==NULL)
         return;
    do{
        cout<<h->data<<"\t";
        h=h->next;
    }while(h!=head);
}
void Rdisplay(struct node* h){
    if(h==NULL)
        return;
    static int flag=0;
    if(h!=head ||flag==0){
        flag=1;
        cout<<h->data<<"\t";
        Rdisplay(h->next);
    }
    flag=0;
}
void insert(struct node* p,int position,int data){
    if(position<0  || position > count (p))
        return;
    if(position==0 ){
        struct node* q=new struct node;
        q->data=data;
        if(p==NULL){
        q->next=q;
        head=q;
        }
        else{
       while(p->next!=  head)
           p=p->next;
        p->next=q;
        q->next=head;
        head=q;
    }
    }
    else{
        for(int i=0;i<position-1;i++)
            p=p->next;
        struct node* q=new struct node;
        q->data=data;
        q->next=p->next;
        p->next=q;
    }
}
int count(struct node* p){
   int  num =0;
    if(p==NULL)
        return num;
    do{
        num++;
        p=p->next;
    }while(p!=head);
    
    return num;
    
}
void insert_1(struct node* p,int position,int data){
    if(position<=0)
        cout<<"INVALID POSITION"<<endl;
    if(position==1 ){
        struct node* q=new struct node;
        q->data=data;
        if(p==NULL){
        q->next=q;
        head=q;
        }
        else{
       while(p->next!=  head)
           p=p->next;
        p->next=q;
        q->next=head;
        head=q;
    }
    }
    else{
        struct node* ptr=p;
        p=p->next;
        for(int i=1;i<position-1;i++){
            ptr=p;
            p=p->next;
            if(ptr==head){
                cout<<"INVALID POSITION"<<endl;
                return;
            }
        }
       
        struct node* q=new struct node;
        q->data=data;
        q->next=ptr->next;
        ptr->next=q;
    }
}
int delete_node(struct node* p,int position){
    if(position<=0){
         cout<<"INVALID POSITION"<<endl;
         return -1;
    }
    if(position==1){
        int x=p->data;
        while(p->next!=head)
            p=p->next;
        if(p==head){
            delete head;
            head=NULL;
            return x;
        }
        else{
            struct node* q=head;
            p->next=head->next;
            head=head->next;
            delete q;
        }
        return x;
    }
    else{
        int i=1;
        struct node* x=head;
        p=p->next;
        for(i=1;i<position -1 ;i++){
            x=p;
            p=p->next;
            if(p==head){
                cout<<"INVALID POSITION"<<endl;
                return -1;
            }
        }
        
       x->next=p->next;
       int zz=p->data;
        delete p;
        return zz;
    }
}