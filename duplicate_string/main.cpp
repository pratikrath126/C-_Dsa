
#include<iostream>

using namespace std;

int main(){
    char string[]="AAaaBB bbCCcc";
    int hash[52] {0};
    int i;
    for(i=0;string[i]!='\0';i++){
        if(string[i]>='A' && string[i]<='Z')
            hash[string[i]-65]++;
        else if(string[i]>='a' && string[i]<='z')
            hash[string[i]-97+26]++;
    }
    for(i=0;i<52;i++){
        if(hash[i]>1){
            if(i<=25)
                cout<<static_cast<char>(i+65)<<" appearing "<<hash[i]<<" times"<<endl;
            else
                cout<<static_cast<char>(i+97-26)<<" appearing "<<hash[i]<<" times"<<endl;
        }
    }
    return 0;
}