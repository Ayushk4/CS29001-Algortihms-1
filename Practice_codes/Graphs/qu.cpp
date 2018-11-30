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

int main()
{
    int n;
    cin>>n;

    qu * q = (qu *) malloc(sizeof(q));
    init(q);

    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        push(q,val);
    }

    for(int i=0;i<n;i++)
    {
        cout<<pop(q)<<" ";
    }


}