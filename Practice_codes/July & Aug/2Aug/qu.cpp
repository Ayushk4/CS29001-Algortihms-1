#include<iostream>

using namespace std;

struct node 
{
    int a;
    node * next;
};

struct qu
{
    node * front ;
    node * rear;
};

void init( qu* q)
{
    q->front = q->rear = NULL;
}

void push(qu * q , int a)
{
    node * ptr = (node * )malloc( sizeof(node));
    ptr-> next = NULL;
    ptr-> a = a;

    if(q->rear  == NULL)
    {
        q->front = q->rear = ptr;
        return;
    }

    q-> rear -> next = ptr;
    q->rear = q-> rear->next;

}
void traverse(qu *q)
{
    node* p = q-> front;

    while( p!=NULL)
    {
        cout<<p->a<<" ";
        p= p->next;
    }
}

node* pop(qu *q)
{
    if(q->front == NULL)
        return NULL;
    else if( q->front == q->rear)
        q->rear = NULL;
    
    node * tmp = q->front;
    q->front = q->front->next;
    cout<<tmp->a<<" ";
    return tmp;
}
int main()
{
    int n,a;
    qu * q= (qu*)malloc(sizeof(qu));
    cin>>n;
    init(q);
    for( int i=0; i<n;i++)
    {
        cin>>a;
        push(q,a);
    }
    cout<<"\n";
    traverse(q);
    cout<<"\n\n";

    node * tmp;
    do
    {
        tmp = pop(q);
    }while (tmp!=NULL);

    cout<<"\n";

}