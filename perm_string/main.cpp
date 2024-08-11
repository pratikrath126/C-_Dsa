
#include<iostream>

using namespace std;

void perm(char [],int);
void perm_1(char[],int,int);
void swpa(int*,int*);
int main(){
    char s[]="ABC";
    perm(s,0);
    cout<<endl;
    perm_1(s,0,2);
    return 0;
}
void perm(char s[],int k){
    static int m[10] {0};
    static char result[10];
    if(s[k]=='\0'){
        result[k]='\0';
        cout<<result<<endl;
    }
    else{
        int i;
        for(i=0;s[i]!='\0';i++){
            if(m[i]==0){
                result[k]=s[i];
                m[i]=1;
                perm(s,k+1);
                m[i]=0;
            }
        }
    }
}
void perm_1(char s[],int low,int high){
    if(low==high)
        cout<<s<<endl;
    else{
        int i;
        for(i=low;i<=high;i++){
            swap(s[i],s[low]);
            perm_1(s,low+1,high);
            swap(s[i],s[low]);
        }
    }
}
void swap(int*a,int*b){
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
}