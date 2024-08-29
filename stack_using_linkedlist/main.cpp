
#include<iostream>

using namespace std;
struct node{
    int data;
    struct node* next;
}*top=NULL;
void push(struct node* p,int data);
int pop(struct node* p);
int is_Empty(struct node* s);
int is_Full(struct node* s);
int peek(struct node* s,int position);
int stack_top(struct node* s);
void display(struct node* s);
int main(){
    push(top,1);
    push(top,2);
    push(top,3);
    push(top,4);
    push(top,5);
    push(top,6);
    cout<<"Popped:"<<pop(top)<<endl;
    cout<<"Stack top:"<<stack_top(top)<<endl;
    cout<<is_Empty(top)<<endl;
    cout<<is_Full(top)<<endl;
    display(top);
    return 0;
}
void push(struct node* p,int data){
    struct node* q=new struct node;
    if(q==NULL)
        cout<<"Stack FULL"<<endl;
    else{
        q->data=data;
        q->next=top;
        top=q;
    }
}
int pop(struct node* p){
    int x=-1;
    if(top==NULL)
        cout<<"Stack Underflow"<<endl;
    else{
        struct node* q=top;
        top=top->next;
        x=q->data;
        delete q;
    }
    return x;
}
int is_Empty(struct node* s){
    if(top==NULL)
        return 1;
    return 0;
}
int is_Full(struct node* s){
    struct node* q=new struct node;
    if(q==NULL)
        return 1;
    else{
        delete q;
        return 0;
    }
}
int peek(struct node* s,int position){
    int i;
    for(i=1;i<position && s!=NULL;i++){
        s=s->next;
    }
    if(s)
        return s->data;
    return -1;
}
int stack_top(struct node* s){
    if(s==NULL)
        return -1;
    return s->data;
}
void display(struct node* s){
    while(s){
        cout<<s->data<<" ";
        s=s->next;
    }
}