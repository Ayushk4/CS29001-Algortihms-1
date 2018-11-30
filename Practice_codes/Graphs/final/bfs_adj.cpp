#include<iostream>
#include<stdlib.h>

using namespace std;

struct node {
    node * next;
    int from, to;
};

struct adj{
    node * next;
};

struct qu_node{
    qu_node * next;
    int val;
};

struct qu{
    qu_node * head, *rear;
};


void init (qu * q)
{
    q->head = q->rear = NULL;
}

void push (qu * q, int val)
{
    qu_node * ptr = new (qu_node);

    ptr->val = val;
    ptr->next = NULL;
    if( q->head == NULL)
        q->head = ptr;
    else
        q->rear->next = ptr;
    
    q->rear = ptr;

}

int pop(qu * q)
{
    qu_node * ptr = q->head;
    int data = ptr->val;

    q->head = q->head->next;
    if(q->head == NULL)
        q->rear = NULL;
    
    free(ptr);
    return data;
}

void bfs(adj a[], int n, int s)
{
    int vis[n], pi[n], d[n];

    for(int i=0;i<n;i++)
    {
        vis[i] = 0;
        pi[i] = -1;
        d[n] = 0;
    }

    qu * q = new (qu);
    init (q);

    push(q,s);
    vis[s] = 1;

    while ( q->head != NULL)
    {
        node * ptr = a[pop(q)].next;
        cout<<ptr->from + 1<<" ";
        while(ptr != NULL)
        {
            if( vis[ ptr->to] ==0)
            {
                d[ptr->to] = d[ptr->from] + 1;
                pi[ptr->to] = ptr->from;
                vis[ptr->to] =1;
               
                push(q,ptr->to);
            }

            ptr = ptr->next;
        }
    }
}

void insert(adj a[], int from, int to)
{
    node * ptr = new node;
    ptr->from = from;
    ptr->to = to;
    ptr->next = a[from].next;
    a[from].next = ptr;
}

int main()
{
    int n;
    cin>>n;

    adj *a = new adj[n];

    for(int i =0 ;i<n;i++)
        a[i].next = NULL;

    int s;
    cin>>s;
    s--;

    int l;
    cin>>l;
    for(int i=0;i<l;i++)
    {
        int from, to;
        cin>>from>>to;
        from--;
        to--;
        //cout<<"a ";
        insert(a,from,to);
        insert(a,to,from);
    }

    bfs(a,n,s);
}