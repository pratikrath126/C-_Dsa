
#include<iostream>

using namespace std;
struct node{
   int data;
   struct node* next; 
}*first;
void create(int [],int);
void display(struct node*);
void display_recursive(struct node*);
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    create(arr,10);
    display(first);
    display_recursive(first);
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
void display_recursive(struct node* p){

   if(p==NULL)
       return;
    cout<<p->data<<"\t";
    display_recursive(p->next);
}