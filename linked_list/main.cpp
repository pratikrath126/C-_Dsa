
#include<iostream>
#include<climits>

using namespace std;
struct node{
   int data;
   struct node* next; 
}*first;
void create(int [],int);
void display(struct node*);
void display_recursive(struct node*);
int find_max(struct node*);
struct node* search(struct node* p,int key);
struct node* search_improved(struct node** first,int key);
int main(){
    int arr[]={1,2,3,4,5,6,8,8,9,10};
    create(arr,10);
    display(first);
    display_recursive(first);
    int max=find_max(first);
    cout<<"Max:"<<max<<endl;
    struct node* target=search(first,1);
    cout<<"Target:"<<target->data<<endl;
    struct node* target_1=search_improved(&first,0);
    if(target_1)
      cout<<"Target:"<<target_1->data<<endl;
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
void display_recursive(struct node* p){

   if(p==NULL)
       return;
    cout<<p->data<<"\t";
    display_recursive(p->next);
}
int find_max(struct node* p){
    int x=0;
    if(p==0)
        return INT_MIN;
   x= find_max(p->next);
    return x>p->data?x:p->data;
}
struct node* search(struct node* p,int key){
    if(p== NULL)
        return NULL;
    if(p->data==key)
        return p;
    return search(p->next,key);
}
struct node* search_improved(struct node** first,int key){
    if(first==NULL)
        return NULL;
    else if((*first)->data==key)
        return *first;
    else{
        struct node* prev=*first;
        struct node* next=(*first)->next;
        while(next!=NULL){
            if(next->data==key){
                prev->next=next->next;
                next->next=*first;
                *first=next;
                return *first;
            } 
            prev=prev->next;
            next=next->next;
        }
             return NULL;
    }
    
    }
