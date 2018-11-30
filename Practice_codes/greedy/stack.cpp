#include<iostream>
#include<stdlib.h>

using namespace std;

struct node 
{
    int val;
    node* next;
};

struct stack{
    node * top;
};

void init(stack *s)
{
    s->top =NULL;
}

void push(stack *s, int val)
{
    node * ptr = (node * )malloc( sizeof(node));
    ptr->next = s->top;
    ptr->val = val;
    s->top = ptr;
}

int pop(stack *s)
{
    if( s->top == NULL)
        return -1;

    node * ptr = s->top;
    s->top = ptr->next;
    int val = ptr->val;
    free(ptr);
    return val;
}

int main()
{
    int n;
    cin>>n;

    stack *s = (stack *)malloc(sizeof(stack));

    init(s);

    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        push(s,val);
    }

    for(int i=0;i<n;i++)
    {
        cout<<pop(s)<<"\n";
    }
}