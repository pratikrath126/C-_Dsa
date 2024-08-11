
#include<iostream>

using namespace std;

class lower_trimatrix{
   private:
      int* mat;
      int n;
   public:
       lower_trimatrix(): mat{new int[2*(2+1)/2]}, n{2}{}
       lower_trimatrix(int m): mat{new int[m*(m+1)/2]} ,n{m}{}
       void set_rowmajor(int i,int j,int x){
           if(i>=j)
           mat[i*(i-1)/2+j-1]=x;
       }
       void set_coloummajor(int i,int j,int x){
           if(i>=j)
               mat[n*(j-1)-(j-2)*(j-1)/2+i-j]=x;
       }
       int get_coloummajor(int i,int j,int x){
           return mat[n*(j-1)-(j-2)*(j-1)/2+i-j];
       }
       int get_rowmajor(int i,int j){
           if(i>=j)
               return mat[i*(i-1)/2+j-1];
          else
              return 0;
       }
       void display_coloummajor(){
           cout<<endl;
           for(int i=1;i<=n;i++){
               for(int j=1;j<=n;j++){
                   if(i>=j)
                       cout<< mat[n*(j-1)-(j-2)*(j-1)/2+i-j]<<" ";
                   else
                       cout<<"0 ";
           }
           cout<<endl;
       }
       }
       void display_rowmajor(){
           cout<<endl;
           for(int i=1;i<=n;i++){
               for(int j=1;j<=n;j++){
                   if(i>=j)
                       cout<<mat[i*(i-1)/2+j-1]<< " ";
                   else
                       cout<<"0 ";
           }
           cout<<endl;
       }
       }
       ~lower_trimatrix(){
           delete [] mat;
       }
};
int main(){
    int n,i,j,x;
    printf("Enter n:");
    cin>>n;
    lower_trimatrix p(n);
    printf("Enter elements:");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>x;
            p.set_coloummajor(i,j,x);
        }
    }
    
    p.display_rowmajor();
    
    
  
    return 0;
}