#include<iostream>


using namespace std;

int partition(int *A, int p, int r)
{
    int pivot, i,j,temp;
    pivot = A[p];
    i = p; j = r;

    while(i < j){
        while(A[i] <= pivot && i<=r) i++;
        while(A[j] > pivot) j--;

        if (i < j){
        temp = A[i]; A[i] = A[j];
        A[j] = temp;
        j--;
        }
    }
    cout<<i<<" "<<j<<"\n";
    temp = A[j]; A[j] = A[p]; A[p] = temp;
    return j;
}

int main()
{
    int n = 3, a[3];
    a[0] = 8;
    a[1] = 23; 
    a[2] = 42;
    partition(a,0,2);

    for(int i=0;i<3;i++)
        cout<<a[i]<<" ";
    
    cout<<"\n";
}