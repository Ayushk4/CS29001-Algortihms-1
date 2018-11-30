#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n;
    
    char *a = new char[n];

    for(int i=0;i<n;i++)
        cin>>a[i];

    cin>>k;

    int *t = new int[n], t_count = 0;
    for(int i=0;i<n;i++)
    {
        if( a[i] == 'T')
            t[t_count++] = i; 
    }

    int p =0;
    
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    
    cout<<"\n";

    for(int i=0;i<n;i++)
    {
        if( a[i] == 'P')
        {
            while(p<t_count)
            {

                if(abs(t[p] -i )<= k)
                {
                    cout<<i<<" catches "<< t[p]<<"\n";
                    p++;
                    break;
                }

                else
                    p++;
            }
        }
    }
}