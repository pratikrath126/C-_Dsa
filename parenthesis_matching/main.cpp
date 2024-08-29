
#include<iostream>
#include<string.h>
using namespace std;
struct stack{
    int top;
    int size;
    char * arr;
};
void push(struct stack*,char);
char pop(struct stack*);
int is_Empty(struct stack);
int pMatching(char []);
int pMatching_1(char *exp);
int main(){
    char arr[50];
while(1){
    cout<<"Enter string:";
    cin>>arr;
    if(pMatching_1(arr))
        cout<<"Balanced Expression"<<endl;
    else
                cout<<"Unbalanced Expression"<<endl;
}
    return 0;
}
void push(struct stack* st, char s) {
    if(st->top==st->size-1)
        cout<<"Stack Overflow"<<endl;
    else{
        st->top++;
        st->arr[st->top]=s;
    }
}
char pop(struct stack * st){
    char x=-'\0';
    if(st->top==-1)
        cout<<"Stack Underflow"<<endl;
else{
    x=st->arr[st->top];
    st->top--;
}
return x;
}
int is_Empty(struct stack st){
    if(st.top==-1)
        return 1;
    return 0;
}
int pMatching(char *exp){
    int i;
    struct stack s1;
    s1.top=-1;
    s1.size=strlen(exp);
    s1.arr=new char[s1.size];
    for(i=0;exp[i]!='\0';i++){
        if(exp[i]=='(' )
            push(&s1,exp[i]);
        else if(exp[i]==')'){
            if(is_Empty(s1)){
                delete [] s1.arr;
                return 0;
            }
            pop(&s1);
        }
    }
    int bal=is_Empty(s1);
    delete [] s1.arr;
    return bal;
}
int pMatching_1(char *exp){
    int i;
    struct stack s1;
    s1.top=-1;
    s1.size=strlen(exp);
    s1.arr=new char[s1.size];
    for(i=0;exp[i]!='\0';i++){
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
            push(&s1,exp[i]);
        else if(exp[i]==')' || exp[i]==']'||exp[i]=='}'){
            if(is_Empty(s1)){
                delete [] s1.arr;
                return 0;
            }
           char s= pop(&s1);
           if((s=='(' && exp[i]==')') ||(s=='{' && exp[i]=='}') ||( s=='[' && exp[i]==']'))
               continue;
            else{
                delete [] s1.arr;
                return 0;
            }
        }
    }
    int bal=is_Empty(s1);
    delete [] s1.arr;
    return bal;
}