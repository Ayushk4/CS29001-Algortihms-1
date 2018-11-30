#include<iostream>
#include<stdlib.h>

using namespace std;

struct node {
    int from, to;
    node * next;
};

struct adj_list {
    node * next;
};

struct qu_node {
    int val;
    qu_node * next;
};

struct qu{
    qu_node * head, *rear;
};

void init (qu * q)
{
    q->head = q->rear = NULL;
};

void push (qu * q, int val)
{
    qu_node * ptr = (qu_node *)malloc(sizeof(node));
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


void bfs(adj_list a[], int n)
{
    int vis[n],pi[n],d[n];
    for(int i=0;i<n;i++)
    {
        vis[i] = 0;
        pi[i] = -1;
        d[i] = 0;
    }

    qu * q = (qu*)malloc(sizeof(qu));
    init(q);

    push(q,0);
    vis[0] = 1;

    while( q->head != NULL)
    {
        node * ptr = a[pop(q)].next;
        cout<<ptr->from + 1<<" ";

        while(ptr != NULL)
        {
            if(vis[ptr->to] == 0)
            {
                d[ptr->to] = d[ptr->from] + 1;
                pi[ptr->to] = ptr->from;
                vis[ptr->to] = 1;
                push(q,ptr->to);
            }
            ptr = ptr->next;
        }
    }
}


void insrt_adj_list( adj_list a[], int from, int to)
{
    node * new_ptr = new node;
    new_ptr->from = from;
    new_ptr->to = to;
    new_ptr->next = a[from].next;

    a[from].next = new_ptr;
}

int main()
{
    int n;
    cin>>n;

    adj_list * a = new adj_list[n];

    for(int i=0;i<n;i++)
        a[i].next = NULL;

    int l;
    cin>>l;

    for(int i=0;i<l;i++)
    {
        int from, to;
        cin>>from>>to;
        from--;to--;
        insrt_adj_list(a,from,to);
        insrt_adj_list(a,to,from);
    }

    bfs(a,n);
}