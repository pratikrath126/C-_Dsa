#include<iostream>

using namespace std;

// Define the element structure
struct element {
    int i;  // Row index
    int j;  // Column index
    int x;  // Value of the element
};

// Define the sparse matrix structure
struct sparse {
    int m;  // Number of rows
    int n;  // Number of columns
    int num;  // Number of non-zero elements
    struct element* ele;  // Array of elements
};

// Function prototypes
void display(const struct sparse& s);
void create_sparse(struct sparse* s);
struct sparse* add_sparse(struct sparse*,struct sparse*);
int main() {
    struct sparse p;
    struct sparse p1;

    // Create and display sparse matrix
    create_sparse(&p);
    create_sparse(&p1);
    display(p);
    struct sparse* p2=add_sparse(&p,&p1);
    if(p2==NULL){
        cout<<"Cannot add dimension mismatch"<<endl;
    }
    else{
    display(*p2);
    }

    // Free the dynamically allocated memory
    if(p2!=NULL){
    delete[] p.ele;
    delete []p2->ele;
    delete p2;
    }

    return 0;
}

// Function to create a sparse matrix
void create_sparse(struct sparse* p) {
    cout << "Enter the number of rows and columns in the sparse matrix: ";
    cin >> p->m >> p->n;

    cout << "Enter the number of non-zero elements: ";
    cin >> p->num;

    p->ele = new struct element[p->num];  // Dynamically allocate memory for elements

    for (int i = 0; i < p->num; i++) {
        cout << "Enter row, column, and value for element " << i + 1 << ": ";
        cin >> p->ele[i].i >> p->ele[i].j >> p->ele[i].x;
    }
}

// Function to display a sparse matrix
void display(const struct sparse& s) {
    int k = 0;  // Index for non-zero elements array
    for (int i = 0; i < s.m; i++) {
        for (int j = 0; j < s.n; j++) {
            // Check if the current position matches a non-zero element
            if ( k<s.num  && s.ele[k].i == i && s.ele[k].j == j)
                cout << s.ele[k++].x << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}
struct sparse* add_sparse(struct sparse* p,struct sparse* p1){
    if(p->m!=p1->m ||p->n!=p1->n)
        return NULL;
    struct sparse* p2=new struct sparse;
    p2->m=p->m;
    p2->n=p->n;
    p2->ele=new struct element[p->num+p1->num];
    int i=0,j=0,k=0;
    while(i<p->num && j<p1->num){
        if(p->ele[i].i<p1->ele[j].i)
            p2->ele[k++]=p->ele[i++];
        else if(p->ele[i].i>p1->ele[j].i)
             p2->ele[k++]=p1->ele[j++];
        else{
            if(p->ele[i].j<p1->ele[j].j)
                 p2->ele[k++]=p->ele[i++];
            else if(p->ele[i].j>p1->ele[j].j)
                p2->ele[k++]=p1->ele[j++];
            else{
                p2->ele[k]=p->ele[i];
                p2->ele[k++].x=p->ele[i++].x+p1->ele[j++].x;
            }
        }
    }
    while(i<p->num)
         p2->ele[k++]=p->ele[i++];
    while(j<p1->num)
        p2->ele[k++]=p1->ele[j++];
p2->num=k;
return p2;
}
