#include<iostream>
#include<stdlib.h>

using namespace std;

struct adj_node {
    adj_node *next;
    int index;
};

struct graph_node {
    int data;
    adj_node * next;
};

struct node {
    int data;
    node * next;
};

struct qu {
    node * head, *rear;
};

void init (qu * q)
{
    q->head = q->rear = NULL;
}

void push (qu * q, int val)
{
    node * ptr = (node *)malloc(sizeof(node));
    ptr->data = val;
    ptr->next = NULL;
    if( q->head == NULL)
        q->head = ptr;
    else
        q->rear->next = ptr;

    q->rear = ptr;
}

int pop(qu * q)
{
    node * ptr = q->head;
    int data = ptr->data;

    q->head = q->head->next;
    if(q->head == NULL)
        q->rear = NULL;

    free(ptr);

    return data;
}

void bfs(graph_node a[],int n)
{
    int visited[n], p[n], d[n];
    for(int i=0;i<n;i++)
    {   visited[i] = 0;
        p[i] = -1;
        d[i] = 10000;
    }
    qu * q = (qu *)malloc(sizeof(qu));

    int start = 1;
    visited[start] =1;
    d[start] = 0;
    push(q,1);

    while(q->head!= NULL)
    {
        int index = pop(q);
        cout<<index<<" ";

        adj_node * ptr = a[index].next;
        //cout<<i<<" : ";
        while( ptr!=NULL )
        {
            if(visited[ptr->index] == 0)
            {
                push(q,ptr->index);
                visited[ptr->index]=1;//index
                p[ptr->index] = index;
                d[ptr->index] = d[index] +1;
            }
           ptr = ptr->next;
        }
    }

    cout<<"\n";
    for(int i=1;i<n;i++)
        cout<<visited[i]<<" "<<d[i]<<" "<<p[i]<<"\n";
}


void insert_edge(graph_node a[], int from, int to)
{
    adj_node * edge = (adj_node * )malloc(sizeof(adj_node));
    edge->next = a[from].next;
    edge->index = to;

    a[from].next = edge;
}

int main()
{
    int n;
    cin>>n;
    n++;
    graph_node *a = (graph_node *)malloc(sizeof (graph_node) * n);

    for(int i=0;i<n;i++)
    {   a[i].data = i;
        a[i].next = NULL;
    }

    int l;
    cin>>l;

    for(int i=0;i<l;i++)
    {
        int from, to ;
        cin>>from>>to;

        insert_edge(a,from,to);
        //insert_edge(a,to,from); //for unordered
    }

/*    for(int i=1;i<n;i++)
    {
        adj_node * ptr = a[i].next;
        cout<<i<<" : ";
        while( ptr!=NULL )
        {
            cout<<ptr->index<<" ";
            ptr = ptr->next;

        }
        cout<<"\n";
    }
*/
    bfs(a,n);

}