
#include<iostream>
#include<math.h>
using namespace std;
struct polynomial{
    int coeff;
    int exp;
    struct polynomial* next;
}*first=NULL,*second=NULL;
struct polynomial* create(struct polynomial* p);
void display(struct polynomial*);
long int evaluate(struct polynomial*,int);
struct polynomial* add(struct polynomial* p1,struct polynomial* p2);
int main(){
   first= create(first);
   second=create(second);
   struct polynomial* third=add(first,second);
   display(first);
   display(second);
   display(third);
    return 0;
}
struct polynomial* create(struct polynomial* p){
    int n,i;
    struct polynomial* last=NULL;
    cout<<"Enter no of terms in polynomial:";
    cin>>n;
    for(i=0;i<n;i++){
        cout<<"Enter coeffecient and exponent of term "<<i+1<<":";
        if(p==NULL){
            p=new struct polynomial;
            p->next=NULL;
            cin>>p->coeff>>p->exp;
            last=p;
        }
      else{
          struct polynomial* q=new struct polynomial;
          q->next=NULL;
          cin>>q->coeff>>q->exp;
          last->next=q;
          last=q;
      }
    }
    return p;
}
void display(struct polynomial* p){
    while(p){
        cout<<p->coeff<<"x^"<<p->exp<<"+";
        p=p->next;
    }
    cout<<endl;
}
long int evaluate(struct polynomial* p,int x){
    long int result=0; 
    while(p){
        result+=(p->coeff)*pow(x,p->exp);
        p=p->next;
    }
    return result;
}
struct polynomial* add(struct polynomial* p1,struct polynomial* p2){
    struct polynomial* p3=new struct polynomial,*last=NULL;
    p3->next=NULL;
    if(p1->exp>p2->exp){
        p3->coeff=p1->coeff;
        p3->exp=p1->exp;
        p1=p1->next;
        last=p3;
    }
    else if(p2->exp>p1->exp){
         p3->coeff=p2->coeff;
        p3->exp=p2->exp;
        p2=p2->next;
        last=p3;
    }
    else{
        p3->exp=p1->exp;
        p3->coeff=p1->coeff+p2->coeff;
        last=p3;
        p1=p1->next;
        p2=p2->next;
    }
    while(p1 && p2){
        struct polynomial* q=new struct polynomial;
        q->next=NULL;
         if(p1->exp>p2->exp){
              q->coeff=p1->coeff;
               q->exp=p1->exp;
             last->next=q;
             last=q;
             p1=p1->next;
    }
    else if(p2->exp>p1->exp){
            q->coeff=p2->coeff;
               q->exp=p2->exp;
             last->next=q;
             last=q;
             p2=p2->next;
    }
    else{
        q->exp=p1->exp;
        q->coeff=p1->coeff+p2->coeff;
        last->next=q;
        last=q;
        p1=p1->next;
        p2=p2->next;
    }
    }
    if(p1)
        last->next=p1;
    if(p2)
        last->next=p2;
return p3;
}