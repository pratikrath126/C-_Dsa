
#include<iostream>
#include<math.h>
using namespace std;
struct term{
   int coeff;
   int exp; 
};
struct polynomial{
   int n;
   struct term* t; 
};
int evaluate_polynomial(struct polynomial,int);
struct polynomial* add_polynomial(struct polynomial,struct polynomial);
void display(struct polynomial);
int main(){
    int i;
    struct polynomial p;
    cout<<"Enter number of terms:";
    cin>>p.n;
    p.t=new struct term[p.n];
    for(i=0;i<p.n;i++){
        cout<<"Enter term data(Coeffecient and Exponenet) of term "<<i+1<<":";
        cin>>p.t[i].coeff>>p.t[i].exp;
    }
    int x;
    cout<<"Enter value of x:";
    cin>>x;
    
    int result=evaluate_polynomial(p,x);
    cout<<"Result of polynomial with value "<<x<< " is "<<result<<endl;
     struct polynomial p1;
    cout<<"Enter number of terms:";
    cin>>p1.n;
    p1.t=new struct term[p1.n];
    for(i=0;i<p1.n;i++){
        cout<<"Enter term data(Coeffecient and Exponenet) of term "<<i+1<<":";
        cin>>p1.t[i].coeff>>p1.t[i].exp;
    }
    int y;
    cout<<"Enter value of x:";
    cin>>y;
    
    result=evaluate_polynomial(p1,y);
    cout<<"Result of polynomial with value "<<y<< " is "<<result<<endl;
    struct polynomial *p3=add_polynomial(p,p1);
    int z;
    cout<<"Enter value of x:";
    cin>>z;
    result=evaluate_polynomial(*p3,z);
    cout<<"Result of polynomial with value "<<z<< " is "<<result<<endl;
    display(p);
    display(p1);
    display(*p3);
    
    
    return 0;
}
int evaluate_polynomial(struct polynomial p,int x){
    int i,sum=0;
    for(i=0;i<p.n;i++){
        sum+=p.t[i].coeff*pow(x,p.t[i].exp);
    }
    return sum;
}
struct polynomial* add_polynomial(struct polynomial p,struct polynomial p1){
    struct polynomial* p3=new struct polynomial;
    p3->n=p.n+p1.n;
    p3->t=new struct term[p3->n];
    int i,j,k;
    i=j=k=0;
    while(i<p.n && j<p1.n){
        if(p.t[i].exp>p1.t[j].exp)
            p3->t[k++]=p.t[i++];
        else if(p1.t[j].exp>p.t[i].exp)
            p3->t[k++]=p1.t[j++];
        else{
            p3->t[k]=p.t[i];
            p3->t[k++].coeff=p.t[i++].coeff+p1.t[j++].coeff;
        }
    }
    while(i<p.n)
        p3->t[k++]=p.t[i++];
    while(j<p1.n)
         p3->t[k++]=p1.t[j++];
    p3->n=k;
return p3;
}
void display(struct polynomial p){
    cout<<endl;
    for(int i=0;i<p.n;i++){
        cout<<p.t[i].coeff<<"x^"<<p.t[i].exp<<"+";
    }
    cout<<endl;
}