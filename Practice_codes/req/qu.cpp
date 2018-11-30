#include<iostream>
#include<stdlib.h>

using namespace std;

struct node 
{
    int val;
    node* next;
};

struct qu{
    node *head, *rear;
};

void init(qu* q)
{
    q->head = q->rear = NULL;
}

void push(qu *q, int val)
{
    node * ptr = (node*)malloc(sizeof(node));
    ptr->val = val;
    ptr->next = NULL;
    if(q->rear == NULL )
    {
        q->head = q->rear = ptr;
        return;
    }

    q->rear->next =ptr;
    q->rear = ptr;
}

int pop (qu* q)
{
    if( q->head == NULL)
        return -1;

    node * ptr= q->head;
    q->head = q->head->next;
    int val = ptr->val;

    free(ptr);
    return val;
}

int main()
{
    int n;
    cin>>n;
    int val;

    qu *q =( qu*) malloc(sizeof(q));
    init(q);

    for(int i=0;i<n;i++)
    {
        cin>>val;
        push(q,val);
    }

    for(int i=0;i<n;i++)
    {
        cout<<pop(q)<<"\n";
    }
}