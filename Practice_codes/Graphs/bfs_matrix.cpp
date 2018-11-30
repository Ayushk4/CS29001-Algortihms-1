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



void bfs(int **a,int n)
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

        for(int i=1;i<n;i++)
        {
            if( a[index][i] == 1)
                if(visited[i] == 0)
                {
                    push(q,i);
                    visited[i]=1;
                    p[i] = index;
                    d[i] = d[index] +1;
                }
        }
    }

    cout<<"\n";
    for(int i=1;i<n;i++)
        cout<<visited[i]<<" "<<d[i]<<" "<<p[i]<<"\n";

}

int main()
{
    int v,n; //no of nodes
    cin>>v;
    v++;
    n = v;

    int **a = (int **) malloc(sizeof(int*) * n);

    for(int i=0;i<n;i++)
        a[i] = (int *) malloc (sizeof (int) * n);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            a[i][j] = 0;

    int l; //edge
    cin>>l;
    for (int i=0;i<l;i++)
    {
        int from, to;
        cin>>from>>to;
        
        a[from][to] = 1;
        //a[to][from] = 1;
    }

    bfs(a,n);

}