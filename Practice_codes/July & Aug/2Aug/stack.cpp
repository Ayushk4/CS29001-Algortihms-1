#include<iostream>
using namespace std;

struct node 
{
    int a;
    node * next;
};

struct stack
{
    node * top;
};

void init(stack *s )
{
    s->top =NULL;
}

void push(stack * s , int a)
{
    node * q = (node* ) malloc(sizeof(node));
    q->next = NULL;
    q-> a = a;
    
    if( s->top== NULL)
        s->top = q;
    
    else
    {
        q->next = s->top;
        s->top = q;
    }
}

void traverse(stack * s)
{
    node * t = s->top;
    while (t!=NULL)
    {
        cout<<t->a<<" ";
        t = t->next;
    }

}

node * pop(stack * s)
{
    node *t = s->top;
    if( s->top ==NULL)
        return NULL;
    s->top = s->top->next;
    cout<<t->a<<" ";
    return t;
}

int main()
{
    int n;
    cin>>n;
    stack *s = (stack *) malloc(sizeof(stack));
    init(s);
    int a;

    for( int i=0; i<n;i++)
    {
        cin>>a;
        push(s, a);
    }
    cout<<"\n";
    traverse(s);
    cout<<"\n\n";

    node * p =NULL;

    do
    {
        p = pop(s);
    }while(p!=NULL);

}