#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;

int lcs(int a[][100], char a1[], char a2[], int i, int j)
{
    
    if(i<0)
    {
        //a[i][j] = 0;
        return 0;
    }
    if(j<0)
    {   
        //a[i][j] = 0; 
        return 0;
    }
    
    if(a[i][j]!=-1)
        return a[i][j];

    if( a1[i] == a2[j] )
    {   
        a[i][j] = 1 + lcs(a,a1,a2,i-1,j-1);
        cout<<a[i][j]<<" "<<i<<" "<<j<<"\n";
    }
    else
    {
        int val1 = lcs(a,a1,a2,i,j-1);
        int val2 = lcs(a,a1,a2,i-1,j);
        if( val1>val2)
            a[i][j] = val1;
        else
            a[i][j] = val2;
    }

    return a[i][j];
}


int main()
{
    int n1,n2;
    cin>>n1>>n2;

    char a1[n1], a2[n2];
    cin>>a1>>a2;

    int A[n1][100];

    for(int i=0;i<n1;i++)
        for(int j=0;j<n2;j++)
            A[i][j] = -1;

    lcs(A,a1,a2,n1-1,n2-1);

    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
            cout<<A[i][j]<<" ";
        cout<<"\n";
    }
}