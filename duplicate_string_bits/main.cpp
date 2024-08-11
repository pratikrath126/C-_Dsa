
#include<iostream>

using namespace std;

int main(){
    char string[]="XXyy zz AA bb cc  aqbqejfvbqehfvb  qdDDDQFQQEDQDXQDQWDQD";
    long int h=0,c;
    int i=0;
    for(i=0;string[i]!='\0';i++){
       c=0;
        if(string[i]>='A' && string[i]<='Z'){
            c=1;
            c=c<<(string[i]-65);
        }
        else if(string[i]>='a' && string [i]<='z'){
            c=1;
            c=c<<(string[i]-97+26);
        }
        if((c&h)>0)
            cout<<"Duplicate character:"<<string[i]<<endl;
        else
            h=c|h;
        }
    return 0;
}