
#include<iostream>

using namespace std;
class upper_trimatrix{
    private:
        int* mat;
        int n;
    public:
        upper_trimatrix(): mat{new int[2*(2+1)/2]},n{2}{}
        upper_trimatrix(int m):mat{new int[m*(m+1)/2]},n{m}{}
        void set_rowmajor(int i,int j,int x){
            if(i<=j)
                mat[n*(i-1)-(i-2)*(i-1)/2+j-i]=x;
        }
        void set_coloummajor(int i,int j,int x){
            if(i<=j)
                mat[j*(j-1)/2+i-1]=x;
        }
        int get_rowmajor(int i,int j){
            if(i<=j)
                return mat[n*(i-1)-(i-2)*(i-1)/2+j-i];
        }
         int get_coloummajor(int i,int j){
            if(i<=j)
                return mat[j*(j-1)/2+i-1] ;
        }
         void display_coloummajor(){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(i<=j)
                        cout<<mat[j*(j-1)/2+i-1]<<" ";
                    else
                        cout<<"0 ";
                }
                cout<<endl;
            }
        }
        void display_rowmajor(){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(i<=j)
                        cout<<mat[n*(i-1)-(i-2)*(i-1)/2+j-i]<<" ";
                    else
                        cout<<"0 ";
                }
                cout<<endl;
            }
        }
        ~upper_trimatrix(){
            delete [] mat;
        }
};
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    upper_trimatrix x(n);
     for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                   int q;
                   cin>>q;
                   x.set_coloummajor(i,j,q);
                }
            }
          x.display_coloummajor();   
            
    
    return 0;
}