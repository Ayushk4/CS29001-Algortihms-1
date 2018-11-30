#include<iostream>
#include<stdlib.h>

using namespace std;

struct edge
{
    int from, to, val;

};

void krus()

int main()
{
    int n,e;
    cin>>n>>e;
    edge edges[e];

    for(int i=0;i<e;i++)
        cin>>edges[i].from>>edges[i].to>>edges[i].val;

    for(int i=0;i<e;i++)
        cout<<edges[i].from<<" "<<edges[i].to<<" "<<edges[i].val<<"\n";
}
