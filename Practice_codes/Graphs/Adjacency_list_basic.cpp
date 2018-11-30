#include<iostream>
#include<stdlib.h>

using namespace std;

struct node {
    node *next;
    int index;
};

struct graph_node {
    int data;
    node * ptr;
};



void insert_edge(graph_node a[], int from, int to)
{
    node * edge = (node * )malloc(sizeof(edge));
    edge->next = a[from].ptr;
    edge->index = to;

    a[from].ptr = edge;
}

int main()
{
    int n;
    cin>>n;
    n++;
    graph_node *a = (graph_node *)malloc(sizeof (graph_node) * n);

    for(int i=0;i<n;i++)
    {   a[i].data = i;
        a[i].ptr = NULL;
    }

    int l;
    cin>>l;

    for(int i=0;i<l;i++)
    {
        int from, to ;
        cin>>from>>to;

        insert_edge(a,from,to);
        insert_edge(a,to,from); //for unordered
    }

    for(int i=1;i<n;i++)
    {
        node * ptr = a[i].ptr;
        cout<<i<<" : ";
        while( ptr!=NULL )
        {
            cout<<ptr->index<<" ";
            ptr = ptr->next;

        }
        cout<<"\n";
    }

}