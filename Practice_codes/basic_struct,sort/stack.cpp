#include<iostream>

using namespace std;
#define MAX_SIZE 100

struct node{
    int val;
    node * next;
};

int isempty(node *s)
{
    if (s==NULL)
        return 1;
    return 0;
}

void init(node ** s)
{
    s= NULL;
}

void push(node ** s, int value)
{
    node *ptr= (node*)malloc(sizeof(node));
    ptr->val = value;
    ptr->next = *s;
    *s = ptr;
}

int pop(node **s)
{
    if(isempty(*s))
    {
        cout<<"\nunderflow\n";
        return 0;
    }
    node *ptr = *s;
    *s = (*s)->next;
    ptr->next = NULL;
    
    int val = ptr->val;
    free(ptr);
    return (val);
}


int main()
{
    int n;
    cin>>n;

    node * stack;
    init(&stack);    

    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        push(&stack,val);
    }

    for(int i=0;i<n;i++)
        cout<<pop(&stack)<<" ";
/**/

    //free(stack);
}