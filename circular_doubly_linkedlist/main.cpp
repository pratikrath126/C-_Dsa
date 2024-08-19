
#include<iostream>

using namespace std;
struct node{
    struct node* prev;
    int data;
    struct node* next;
}*head;
void create(int arr[],int n);
void display(struct node* p);
int count(struct node* p);
void display_1(struct node* p);
int main(){
    int arr[] {1,2,3,4,5,6,7,8,9,10};
    create(arr,10);
    display_1(head);
    cout<<endl;
    cout<<count(head);
    return 0;
}
void create(int arr[],int n){
    head=new struct node;
    head->prev=head;
    head->next=head;
    head->data=arr[0];
    int i=1;
    struct node* last=head;
    while(i<n){
        struct node* p=new struct node;
        p->data=arr[i++];
        last->next=p;
        p->prev=last;
        p->next=head;
        head->prev=p;
        last=p;
    }
}
void display(struct node* p){
    if(p==NULL)
        return;
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);
}
int count(struct node* p){
    int count=0;
    if(p==NULL)
        return count;
    do{
        count++;
        p=p->next;
    }while(p!=head);
    return count;
}
void display_1(struct node* p){
    if(p==NULL)
        return;
    struct node* prev=p->prev;
    p=p->prev;
    do{
        cout<<p->data<<" ";
        p=p->prev;
    }while(p!=prev);
}
void insert(struct node* p,int position,int data){
    
}