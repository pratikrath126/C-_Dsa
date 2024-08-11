
#include<iostream>

using namespace std;

int main(){
    char a[] {"william shakespeare"};
    char b[] {"i'll make a wise phrase"};
    int hash[26] {0};
    int i;

for(i=0;a[i]!='\0' ;i++){
    if(a[i]>='a' && a[i]<='z')
        hash[a[i]-97]++;
}
for(i=0;b[i]!='\0';i++){
     if(b[i]>='a' && b[i]<='z')
       hash[b[i]-97]--;
}

for(i=0;i<26;i++){
    if(hash[i]!=0){
        cout<<"Not Anagram"<<endl;
        break;
    }
}
if(i==26)
    cout<<"STRING ANAGRAM"<<endl;
        
return 0;
}