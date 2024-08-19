
#include<iostream>

using namespace std;
struct node{
    int data;
    struct node* next;
}*first;
struct node* create_loop(int [],int ,int);
int is_loop(struct node*);
int main(){
    int arr[]{1,2,3,4,5,6,7,8,9,10};
    first=create_loop(arr,10,10);
    if(is_loop(first))
        cout<<"LIST IS LOOPED"<<endl;
    else
         cout<<"LIST IS NOT LOOPED"<<endl;
    
    return 0;
}
struct node* create_loop(int arr[],int n,int pos){
    struct node*start,*last;
    start=new struct node;
    last=start;
  start->data=arr[0];
    start->next=NULL;
    int i=1;
    while(i<n){
        struct node* p=new struct node;
        p->data=arr[i++];
        p->next=NULL;
        last->next=p;
        last=p;
    }
    struct node*p=start;
    while(p->next!=NULL)
        p=p->next;
   i=1;
   struct node*q=start;
   while(i<pos){
       q=q->next;
       i++;
   }
    p->next=q;
    
    return start;
}
int is_loop(struct node* start){
    if(start->next==NULL)
        return 0;
    else{
        struct node* q=start;
        do{
            q=q->next;
            start=start->next;
            start=start!=NULL?start->next:NULL;
        }while(start!=NULL && q!=NULL && start!=q);
        if(start==q)
            return 1;
        return 0;
}
}