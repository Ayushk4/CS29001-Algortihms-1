#include<iostream>
#include<stdlib.h>

using namespace std;

struct node{
    int val,w;
};

int partition(node items[],int low, int high)
{
    int i=low, j=high-1, piv = low;

    while(i<j)
    {
        while(i<high && ((float(items[i].w)/items[i].val) <= (float(items[piv].w)/items[piv].val)) ) i++;
        while( (float(items[j].w)/items[j].val) > (float(items[piv].w)/items[piv].val) ) j--;
        if(i<j)
        {
            node tmp = items[i];
            items[i] = items[j];
            items[j] = tmp;
            
            j--;
        }
    }

    node tmp = items[piv];
    items[piv] = items[j];
    items[j] = tmp;

    return j;
}

void sort_quick(node items[], int low, int high)
{
    if((high - low)<=1)
        return;
    
    int parti = partition(items,low,high);
    return;
    sort_quick(items,low,parti);
    sort_quick(items,parti+1,high);
}

int main()
{
    int n,weight;
    cin>>n>>weight;

    node items[n];

    for(int i=0;i<n;i++)
        cin>>items[i].w>>items[i].val;
    
    sort_quick(items,0,n);

    for(int i=0;i<n;i++)
        cout<<items[i].val<<" "<<items[i].w<<"\n";

    int i=0,profit =0;

    while(i<n && weight>0)
    {
        if(items[i].w<weight)
        {
            profit +=items[i].val;
            weight -=items[i].w;
        }

        else
        {
            profit += int(float(items[i].val)/items[i].w)*weight;
            weight =0;
        }
        i++;
    }

    cout<<profit<<"\n";
}