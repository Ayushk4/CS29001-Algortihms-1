#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct rm {
    int hind;
    int vind;
} room;

typedef struct node{
    room data;
    struct node * next;
} *list;


typedef struct{
    struct node * head;
}STACK,stack;

typedef struct{
    struct node * front, * rear;
} QUEUE, qu;

void init_q(qu *q)
{
    q->front = q->rear = NULL;
}

int isempty(qu q)
{
    if( q->fron == NULL)
        return 1;

    return 0;
}

void enqueue(qu q, room data)
{

}


void init(stack *s)
{
    s->head = NULL;
}

int isempty(stack s)
{
    if( s.head == NULL)
        return 1;
    
    return 0;
}

void push(stack * s, room data)
{
    node * ptr = new node;
    ptr->next = s->head;
    ptr->data.hind = data.hind;
    ptr->data.vind = data.vind;

    s->head = ptr;
}

room pop(stack * s)
{
    room data;
    data.hind = -1;
    data.vind = -1;
    if(isempty(*s))
    {
        cout<<"UNDERFLOW";
        return data;
    }

    data.hind = s->head->data.hind;
    data.vind = s->head->data.vind;

    node * ptr = s->head;

    s->head = s->head->next;

    free(ptr);

    return data;
}

void printmaze(int H[][20], int V[][21], int n)
{

    for(int i=0;i<2*n+1;i++)
    {
        for(int j=0;j<2*n+1;j++)
        {
            if(j%2 ==0)
            {
                if(i%2==0)
                    cout<<"+";
                else
                {   if(V[i/2][j/2] == 0)
                        cout<<"|";
                    else
                        cout<<" ";
                }
            }
            else
            {
                if(i%2 ==0)
                {   if(H[i/2][j/2]==0)
                        cout<<"--";
                    else
                        cout<<"  ";
                }
                else
                    cout<<"  ";
            }
        }
        cout<<"\n";
    }
}





void insert(list maze[][20], room a, room b)
{
    node * ptr = new node;
    ptr->data.hind = b.hind;
    ptr->data.vind = b.vind;
    ptr->next = maze[a.hind][a.vind];
    maze[a.hind][a.vind] = ptr;
}

void createmaze(list maze[][20], int n, int h[][20], int v[][21])
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            room a = {i,j};
            room b;
            if(i>=0)
            {
                if(h[i][j]== 1)
                {
                    b.hind = i-1;
                    b.vind = j;
                    insert(maze,a,b);
                }
            }
            if(i+1<n)
            {
                if(h[i+1][j]== 1)
                {
                    b.hind = i+1;
                    b.vind = j;
                    insert(maze,a,b);
                }
            }
            if(j-1>=0)
            {
                if(v[i][j]== 1)
                {
                    b.hind = i;
                    b.vind = j-1;
                    insert(maze,a,b);
                }
            }
            if(j+1<n)
            {
                if(v[i][j+1]== 1)
                {
                    b.hind = i;
                    b.vind = j+1;
                    insert(maze,a,b);
                }
            }
        }

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            cout<<"\n("<<i<<","<<j<<")::";

            node * ptr = maze[i][j];

            while(ptr!= NULL)
            {
                cout<<"-->"<<"("<<ptr->data.hind<<","<<ptr->data.vind<<")";
                ptr = ptr->next;

            }
        }
}

int strategy1(list maze[][20], int n, room start, room end)
{

    stack *s = new stack;
    init(s);

    int vis[20][20];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            vis[i][j] = 0;

    room data;
    data.hind = start.hind;
    data.vind = start.vind;
    push(s,data);
    vis[data.hind][data.vind] = 1;
    while(!isempty(*s))
    {
        data = pop(s);
        if( data.hind == end.hind && data.vind == end.vind)
            return 1;

        node * ptr =maze[data.hind][data.vind];

        while(ptr!=NULL)
        {
            if(vis[ptr->data.hind][ptr->data.vind] == 0)
            {
                push(s,ptr->data);
                vis[ptr->data.hind][ptr->data.vind] = 1;
            }
            ptr = ptr->next;
        }
    }

    return 0;
}


int main()
{
    int n;
    cout<<"\nEnter the value of n";
    cin>>n;
    int h[n+1][20];
    int v[n][21];

    cout<<"\nEnter the horizontal doors H";

    for(int i=0;i<n+1;i++)
        for(int j=0;j<n;j++)
            cin>>h[i][j];

    cout<<"\nEnter the vertical doors V";
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n+1;j++)
            cin>>v[i][j];

    for(int j=0;j<n;j++)
    {   
        h[0][j] = 0;
        h[n][j] = 0;
    }

    for(int j=0;j<n;j++)
    {   
        v[j][0] = 0;
        v[j][n] = 0;
    }

    room start,end;
    cout<<"\nEnter the start vertex";
    cin>>start.hind>>start.vind;
    cout<<"\nEnter the end vertex";
    cin>>end.hind>>end.vind;
    cout<<"\n\n";
    printmaze(h,v,n);


    list maze[20][20];
    for(int i=0;i<20;i++)
        for(int j=0;j<20;j++)
            maze[i][j] = NULL;

    createmaze(maze,n,h,v);
    cout<<"\n";
    int strat1 = strategy1(maze,n,start,end);
    cout<<strat1<<"\n";

}