#include<iostream>
#include<stdlib.h>

using namespace std;

struct job{
    int start, end;
};

void sort_according_end_time()
{

}

int main()
{
    int n;
    cin>>n;

    job a[n];
    for(int i = 0 ; i < n ; i++)
        cin>>a[i].start>>a[i].end;

    sort_according_end_time();

    int i = 0, currtime = 0, count_jobs = 0;

    while(i<n)
    {
        while(a[i].start<currtime)
        {
            i++;
        }    
        currtime = a[i].end;
        count_jobs++;
        i++;
    }

    cout<<count_jobs<<"\n";
}