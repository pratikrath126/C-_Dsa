
#include<iostream>

using namespace std;

#include<iostream>

using namespace std;

class symetric_matrix{
   private:
      int* mat;
      int n;
   public:
       symetric_matrix(): mat{new int[2*(2+1)/2]}, n{2}{}
       symetric_matrix(int m): mat{new int[m*(m+1)/2]} ,n{m}{}
       void set(int i,int j,int x){
           if(i>=j)
           mat[i*(i-1)/2+j-1]=x;
       }
    
       void display(){
           cout<<endl;
           for(int i=1;i<=n;i++){
               for(int j=1;j<=n;j++){
                   if(i>=j)
                       cout<<mat[i*(i-1)/2+j-1]<< " ";
                   else
                       cout<<mat[j*(j-1)/2+i-1];
           }
           cout<<endl;
       }
       }
       ~symetric_matrix(){
           delete [] mat;
       }
};
int main(){
    int n,i,j,x;
    printf("Enter n:");
    cin>>n;
    symetric_matrix p(n);
    printf("Enter elements:");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>x;
            p.set(i,j,x);
        }
    }
    
    p.display();
    
    
  
    return 0;
}

int main(){
    cout << "Hello World"<<endl;
    return 0;
}