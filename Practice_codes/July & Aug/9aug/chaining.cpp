#include <iostream>

using namespace std;

struct node {
    int a;
    node * next;
};

void insert(node * a[], int hashed_index, int val)
{
    node * ptr = (node *) malloc(sizeof(node));
    ptr->next = a[hashed_index];
    ptr->a = val;

    a[hashed_index] = ptr; 
}

void print_index(node * a[], int i)
{
    node * ptr = a[i];

    while( ptr!= NULL)
    {
        cout<< ptr->a<< " ";
        ptr = ptr->next;
    }
}
int main()
{
    int n,i;
    cin>>n;

    node  * a[n];
    for(i = 0; i < n; i++)
        a[i] = NULL;
    

    for(i = 0;i< n;i++)
    {
        int hashed, in;
        cin>>in;
        insert (a, in % n, in);
    }



    for( i = 0; i < n; i++)
    {
        if(a[i] == NULL)
            cout<<"N ";
        else
            print_index(a,i);
    }


    cout<<"\n";
}