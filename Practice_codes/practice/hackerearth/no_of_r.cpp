#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;

int f(char a[], int n)
{
    if(n <0)
        return 0;

    int max_far = 0, max_here = 0,k=0,l;

    for (int i=0;i<n;i++)
    {
        if(a[i] == 'R')
            max_here--;
        else
            max_here++;

        if(max_here < 0)
        {
            max_here = 0;
            k=i+1;
            //cout<<"a";
        }

        if(max_here > max_far )
        {    
            max_far = max_here;
            l=i;
            //1cout<<"b";
        }
    }

    cout<<k<<" "<<l<<" ";//<<max_far;
    return max_far;
}

int main()
{
    int n;
    cin>>n;

    char a[n];

    for(int i=0;i<n;i++)
        cin>>a[i];

    cout<<f(a,n)<<"\n";

    cin>>n;

//    char a[n];

    for(int i=0;i<n;i++)
        cin>>a[i];

    cout<<f(a,n)<<"\n";
}

// j
//
