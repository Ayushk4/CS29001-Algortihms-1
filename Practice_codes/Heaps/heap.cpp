#include<iostream>

using namespace std;



void swap(int *x,int*y)
{
    int tmp =*x;
    *x =*y;
    *y = tmp;
}

int violates(int a[],int i)
{
    if( i/2 <1)
        return 1;
    
    return 0;
}

void insert(int a[], int val,int i)
{
    a[i] = val;
    while(!violates(a,i))
    {
        if(a[i] < a[i/2])
            swap (&a[i],&a[i/2]);
        else 
            break;

        i= i/2;
    }
}

void adjustshift(int a[],int size, int i)
{
    int minchild;

    while(2*i +1<size)
    {
        minchild = 2*i;
        if(a[2*i +1]<a[minchild])
            minchild = 2*i +1;

        if(a[i]> a[minchild])
        {   swap(&a[i],&a[minchild]);
            i = minchild;
        }
        else
            break;
    }

    if( 2*i < size)
        if(a[i]> a[2 *i])
            swap(&a[i],&a[2*i]);
}

int extract_min(int a[],int size)
{
    int min = a[1];
    a[1] = a[size-1];
    size--;
    adjustshift(a,size,1);
    cout<<"The min is :"<<min<<"\n";
    return size;
}

int main()
{
    int n;
    cin>>n;
    n++;
    int a[n];

    for(int i=1;i<n;i++)
    {
        int val;
        cin>>val;
        insert(a,val,i);
        
    }

    for(int i=1;i<n;i++)
        cout<<a[i]<<" ";

    cout<<"\n";
    n = extract_min(a,n);
    
    for(int i=1;i<n;i++)
        cout<<a[i]<<" ";
    
    cout<<"\n";

}