
#include<iostream>

using namespace std;
class tri_diagonalmatrix{
   private:
       int* mat;
       int n;
       public:
           tri_diagonalmatrix(int m): mat{new int[3*m-2]},n{m}{}
           void set(int i,int j,int x){
               if(i-j==1)
                   mat[j-1]=x;
                else if(i-j==0)
                    mat[n-1+j-1]=x;
                else if(i-j==-1)
                    mat[2*n-1+i-1]=x;
           }
        void display(){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                     if(i-j==1)
                  cout<< mat[j-1]<<" ";
                else if(i-j==0)
                    cout<<mat[n-1+j-1]<<" ";
                else if(i-j==-1)
                   cout<< mat[2*n-1+i-1]<<" ";
                else
                    cout<<"0 ";
           }
           cout<<endl;
                }
            }
        
};
int main(){
    tri_diagonalmatrix m(5);
                for(int i=1;i<=5;i++){
                for(int j=1;j<=5;j++){
                           int x;
                           cin>>x;
                           m.set(i,j,x);
                }
            }
        
     
    m.display();
    return 0;
}