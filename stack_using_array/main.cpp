
#include<iostream>

using namespace std;
struct stack {
    int size;
    int top;
    int* arr;
};
int is_Empty(struct stack);
int is_Full(struct stack);
void push(struct stack* s,int x);
int pop(struct stack* s);
int peek(struct stack s,int position);
void create(struct stack* st);
void display(struct stack st);
int main(){
    struct stack st;
    create(&st);
    push(&st,0);
    push(&st,1);
    push(&st,2);
    push(&st,3);
    push(&st,4);

   // cout<<"Popped:"<<pop(&st)<<endl;
    cout<<"Peek:"<<peek(st,5)<<endl;

  
    display(st);
    return 0;
}
int is_Empty(struct stack s){
    if(s.top==-1)
        return 1;
    return 0;
}
int is_Full(struct stack s){
    if(s.top==s.size-1)
        return 1;
    return 0;
}
void push(struct stack* s,int x){
    if(is_Full(*s))
        cout<<"Stack Overflow"<<endl;
    else{
        s->top++;
        s->arr[s->top]=x;
    }
}
int pop(struct stack* s){
    int x=-1;
    if(is_Empty(*s))
        cout<<"Stack Underflow"<<endl;
    else
        x=s->arr[s->top--];
    return x;
}
int peek(struct stack s,int position){
    int x=-1;
    if(s.top-position+1<0)
        cout<<"Invalid position"<<endl;
    else
        x=s.arr[s.top-position+1];
    return x;
}
void create(struct stack* st){
    cout<<"Enter size of stack";
    cin>>st->size;
    st->top=-1;
    st->arr=new int[st->size];
}
void display(struct stack st){
    for(int i=st.top;i>=0;i--)
        cout<<st.arr[i]<<" ";
    cout<<endl;
}
