#include<iostream>
#include<fstream>
#include<stdlib.h>

using namespace std;

struct node
{
    int data;
    float marks;
    char roll[10];
};

void merge(node a[], int low, int mid, int high)
{
    int l=low, r= mid, i=0;
    node b[high - low + 1];

    while( l<mid && r< high)
    {
        if( a[l].marks > a[r].marks)
        {
            b[i] = a[l];
            l++;
            i++;
        }
        else
        {
            b[i] = a[r];
            r++;
            i++;
        }        
    }

    while( r<high)
    {
        b[i] = a[r];
        r++;
        i++;
    }
    while( l<mid)
    {
        b[i] = a[l];
        l++;
        i++;
    }


    for(int j=0;j<i;j++)
        a[low+j] = b[j];
}

void mergesort(node a[], int low, int high)
{
    if(  (high -low) <2)
        return ;
    
    int mid = (low + high)/2;

    mergesort(a, low ,mid);
    mergesort(a, mid, high);

    merge (a, low, mid, high);

    return;

}


int main()
{

    ifstream fin;
    fin.open("in.txt");

    int n;
    fin>>n;

    node * a = new node[n];


    for(int i=0;i<n;i++)
        fin>>a[i].data>>a[i].roll>>a[i].marks;

    ofstream fout;
    fout.open("out.txt");

    mergesort(a,0,n);

    for(int i=0;i<n;i++)
        fout<<i<<"\t"<<a[i].roll<<"\t"<<a[i].marks<<"\n";

    float sum = 0;
    for(int i=0;i<n;i++)
        sum+=a[i].marks;

    cout<<sum/n;
    fin.close();
    fout.close();
}