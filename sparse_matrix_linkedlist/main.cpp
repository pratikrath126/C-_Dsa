
#include<iostream>

using namespace std;
struct node{
    int col;
    int value;
    struct node* next;
};
void insert(struct node** arr,int r,int c,int v);
void display(struct node**,int,int);
int main(){
    int m,n,i,nonzero;
    cout<<"Enter no of row and columns in sparse matrix:";
    cin>>m>>n;
    struct node** arr=(struct node**)malloc(m*sizeof(struct node*));
    for(i=0;i<m;i++)
        arr[i]=NULL;
    cout<<"Enter no of nonzero elements in sparse matrix:";
    cin>>nonzero;
    for(i=0;i<nonzero;i++){
        int r,c,v;
        cout<<"Enter row coloumn and value :";
        cin>>r>>c>>v;
        insert(arr,r,c,v);
    }
    display(arr,m,n);
    return 0;
}
void insert(struct node** arr,int r,int c,int v){
    if(arr[r]==NULL){
        arr[r]=new struct node;
        arr[r]->next=NULL;
        arr[r]->col=c;
        arr[r]->value=v;
    }
    else{
        struct node *q=new struct node;
        q->col=c;
        q->value=v;
        q->next=NULL;
        struct node* x=arr[r];
        while(x->next!=NULL)
            x=x->next;
        x->next=q;
    }
}
void display(struct node** arr,int m,int n){
    int i,j;
    for(i=0;i<m;i++){
        struct node* q=arr[i];
        for(j=0;j<n;j++){
            if(q!=NULL && q->col==j){
                cout<<q->value<<" ";
                q=q->next;
            }
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}