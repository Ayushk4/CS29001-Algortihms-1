#include<iostream>
#include<stdlib.h>

using namespace std;

struct node {
    int data;
    node * next;
};

struct qu{
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

void bfs(int n ,int  e, int m[][100])
{
    int pi[n], vis[n],d[n];

    for(int i=0;i<n;i++)
    {
        vis[i] = 0;
        pi[i] = -1;
        d[i] = 0;
    }


    qu * q = new qu;
    init(q);
    //node * ptr ;//= new node;
    //ptr->data =0;
    push(q,0);
    vis[0] = 1;

    while(q->head != NULL)
    {
        int popped = pop(q);

        for(int i=0;i<n;i++)
        {
            if(m[popped][i] == 1)
                if(vis[i] == 0)
                {
                    vis[i] = 1;
                    d[i] = d[popped] +1;
                    pi[i] = popped + 1;
                    push(q,i);
                }
        }
    }

    cout<<"\nvis\n";
    for(int i=0;i<n;i++)
        cout<<vis[i]<<" ";

    cout<<"\npi\n";
    for(int i=0;i<n;i++)
        cout<<pi[i]<<" ";

    cout<<"\nd:\n";
    for(int i=0;i<n;i++)
        cout<<d[i]<<" ";

}

int main()
{
    int n,s,e;
    cin>>n>>s>>e;

//    node *ptr = new node[e];

    int m[n][100];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            m[i][j] = 0;

    for(int i=0;i<e;i++)
    {
        int from, to;

        cin>>from>>to;
        from--;to--;
        m[from][to] = 1;
        m[to][from] = 1;
    }

    bfs(n,e,m);  
}
