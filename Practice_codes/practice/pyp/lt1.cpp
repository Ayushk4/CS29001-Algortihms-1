#include<iostream>
#include<stdlib.h>
#include<climits>

using namespace std;

int find(int a[], int b[], int n, int t, int c[][100000], int max_sum, int my[])
{
    int i=n, j=t+max_sum;

//    cout<<"a"<<i<<" "<<j<<" \n\n";

    if (i == 0)
    {
        if (t==a[i] ||t == b[i])
            {
                if(t == b[i] )
                    my[i] = 1;

                c[i][j] = 1;
                //cout<<"yippeekiyay"<<i<<" "<<j<<"\n";
                return c[i][j];
            }
        else
            {
                //cout<<"baab\n";
                return 0;
            }
    }

    //cout<<"baab\n";
    //if( i == -1 && j == 10)
    //    return 0;

    if (c[i][j]>-1)
    {
        //cout<<"a\n\n\n";
        return c[i][j];
    }
    else
    {
        int indexa = find(a,b,i-1,t-a[n],c,max_sum,my);

        if( indexa == 1)
        {
//            cout<<indexa<<"\n";
            c[i][j] = indexa;
            return c[i][j];            
        }
        int indexb = find(a,b,i-1,t-b[n],c,max_sum,my);

        if( indexb == 1)
        {
            c[i][j] = indexb;
            my[i] = 1;
            return c[i][j];
        }
        else
        {
            c[i][j] = 0;
        }
    }
}

int issolvable(int a[],int b[],int n,int t)
{

    int min_sum = 0,min = 100000;
    int max_sum = 0, max= -100000;

    for(int i=0;i<n;i++)
        if(a[i]>b[i])
        {
            min_sum += b[i];
            max_sum += a[i];

            if( min>min_sum)
                min = min_sum;
            if( max<max_sum)
                max = max_sum;
        }
        else
        {
            min_sum += a[i];
            max_sum += b[i];

            if( min>min_sum)
                min = min_sum;
            if( max<max_sum)
                max = max_sum;
        }

    int c[n][100000];

    int my[n];

    for(int i=0;i<n;i++)
        my[i] = 0;

    //cout<<max<<" "<<min<<"\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<=100000;j++)
            c[i][j] = -1;

    int ds= find(a,b,n-1,t,c,max-t,my);
/*
    for(int i=0;i<n;i++)
    {
        for(int j=t-min;j<=t-min+max;j++)
            cout<<c[i][j]<<" ";//"a"<<j<<" ";
        cout<<"\n";
    }
*/

    for(int i=0;i<n;i++)
        cout<<my[i]<<" ";
    
    cout<<"\n";
    return ds;
}

int main()
{
    int n;
    cin>>n;
    int a[n],b[n];

    for(int i=0;i<n;i++)
        cin>>a[i];

    for(int i=0;i<n;i++)
        cin>>b[i];

    int t;
    cin>>t;

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    cout<<"\n";

    for(int i=0;i<n;i++)
        cout<<b[i]<<" ";

    cout<<"\n";
    cout<<issolvable(a,b,n,t)<<"\n";
}