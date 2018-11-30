//MIN_DAY (n, i) where n = no of painters, i = 0 to i jobs are to be assigned
// = min( for j = 0 to i : (max(time from k to i, MIN_DAY (n-1,j)))
// if n =1 : = sum of time of jobs upto i
// if i =0 : return time of job[0]

#include<iostream>
#include<stdlib.h>

using namespace std;



int main()
{
    int n, k;
    cin>>n>>k;
    int job[n];

    for(int i=0;i<n;i++)
        cin>>job[i];

    cout<<min_days(k,n-1);
}