#include<iostream>
#include<stdlib.h>

using namespace std;

const int c = 100;


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


void bfs(int a[][c],int n)
{
    int pi[n],d[n],vis[n];

    for(int i=0;i<n;i++)
    {
        pi[i] = -1;
        d[i] = vis[i] =0;
    }

    int current;
    qu * q = new(qu);
    init(q);
    push(q,0);
    d[0] = 0; pi[0] = -1;
    vis[0] =1;

    while (q ->head != NULL)
    {
        current = pop(q);
        cout<<current<<" ";
        for(int i=0;i<n;i++)
            if(a[current][i] == 1 && vis[i] == 0)
            {
                vis[i] = 1;
                d[i] = d[current] + 1;
                pi[i] = current;
                push(q,i);
            }   
    }

}

int main()
{
    int n;
    cin>>n;
    int a[n][c];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            a[i][j] =0;
    
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        int from, to;
        cin>>from>>to;
        to--;
        from--;
        a[from][to] = 1;
        a[to][from] = 1;
    }

//cout<<"sdfas";
    for(int i=0;i<n;i++)
    {    for(int j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }       
    bfs(a,n);
}