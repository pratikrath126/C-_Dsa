
#include<iostream>

using namespace std;
struct node{
    int data;
    struct node* next;
}*first,*second;
struct node* create(int arr[],int n);
void display(struct node* first);
struct node* merge(struct node*first,struct node* second);
int main(){
  int arr[]{1,5,7,9,10,15,20,25,45,78,99};
  int arr2[]{3,8,11,23,32,34,56,64,71,101,111};
  first=create(arr,11);
  second=create(arr2,11);
   struct node* third=merge(first,second);
   display(third);
   second=first=NULL;
    return 0;
}
struct node* create(int arr[],int n){
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
    return start;
}
void display(struct node* first){
   struct node* p=first;
   while(p!=NULL){
       cout<<p->data<<" ";
       p=p->next;
   }
   cout<<endl;
}
struct node* merge(struct node*first,struct node* second){
    struct node*third,*last;
    if(first->data<second->data){
        third=last=first;
        first=first->next;
        third->next=NULL;
    }
    else{
         third=last=second;
        second=second->next;
        third->next=NULL;
    }
    while(first!=NULL && second!=NULL){
        if(first->data<second->data){
            last->next=first;
            last=first;
            first=first->next;
            last->next=NULL;
        }
        else{
            last->next=second;
            last=second;
            second=second->next;
            last->next=NULL;
        }
    }
    if(first!=NULL)
        last->next=first;
     if(second!=NULL)
        last->next=second;
return third;
}
