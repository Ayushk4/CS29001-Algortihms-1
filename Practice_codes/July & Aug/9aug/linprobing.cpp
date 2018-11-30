#include<iostream>

using namespace std;

int h(int key,int i, int m)
{
    return((key % m +i)% m);
}

void init(int a[],int m)
{
    for(int i=0;i<m;i++)
        a[i] = 0;
}

void insert(int a[], int m)
{
    int j, i = 0;
    int key;
    cin>>key;

    while( i!=m)
    {
        j = h(key,i,m);
        if(a[j]==0)
        {
            a[j] = key;
            return;
        }

        i++;
    }
    cout<<"Filled up\n";
}

int search (int a[],int m, int saarch)
{
    int i=0, j;
    while(i!=m)
    {
        j = h(saarch, i, m);
        if(a[j] == saarch)
        {
            return j;;
        }
        i++;
    }
    return -1;
}

int main()
{
    int m,n;
    cin>>m>>n;
    // m > n
    int a[m];
    //initinitinitinitinitinitinit
    init(a,m);
    for(int i = 0; i<n; i++)
    {
        insert(a,m);
    }

    cout<<"\n";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    int saarch;
    cin>>saarch;

    saarch = search(a, m, saarch);

    if(saarch!= -1)
        cout<<"dkhjidskfl"<<a[saarch]<<"\n";
    else
        cout<<"Not found\n";
    

}
