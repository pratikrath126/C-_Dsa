
#include<iostream>
#include<string.h>
using namespace std;
struct node{
    char data;
    struct node* next;
}*top=NULL;
void push(struct node* p,int data);
char pop(struct node* p);
int is_Empty(struct node* s);
int is_Full(struct node* s);
int peek(struct node* s,int position);
char stack_top(struct node* s);
void display(struct node* s);
char* infix_to_postfix(char* exp);
int is_operand(char o);
int precedence(char p);
int main(){
    char  exp[100];
   
    cout<<"Enter expression";
    scanf("%[^\n]s",exp);
    char *postfix=infix_to_postfix(exp);
    cout<<postfix;

    return 0;
}
void push(struct node* p,char data){
    struct node* q=new struct node;
    if(q==NULL)
        cout<<"Stack FULL"<<endl;
    else{
        q->data=data;
        q->next=top;
        top=q;
    }
}
char pop(struct node* p){
    char x=-'\0';
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
char stack_top(struct node* s){
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
char* infix_to_postfix(char* exp){
    int length=strlen(exp);
    exp[length]=')';
    exp[length+1]='\0';
    push(top,'(');
     char* postfix=new char[strlen(exp)+1];
     int j=0,i=0;
    while(exp[i]!='\0'){
        if(is_operand(exp[i]))
          postfix[j++]=exp[i++];
        else if( exp[i]=='('){
             push(top,'(');
             i++;
        }
        else if(exp[i]==')'){
            while(stack_top(top)!='(')
                postfix[j++]=pop(top);
            pop(top);
            i++;
        }
        else if(precedence(stack_top(top))>=precedence(exp[i]))
                postfix[j++]=pop(top);
        else
               push(top,exp[i++]);
    }
    
  
     postfix[j]='\0';
     return postfix;
}
int is_operand(char o){
    if(o=='+' || o=='-' || o=='*' || o=='/' || o=='(' ||o==')' || o=='^'  )
        return 0;
    return 1;
}
int precedence(char p){

    if(p=='+' || p=='-' )
      return 1;
    else if(p=='*' || p=='/')
        return 3;
    else if(p=='^')
        return 6;
    else 
        return -1;

}


