#include<iostream>

using namespace std;

struct node {
    int a;
    node * next;
};

struct que{
    node * front, *rear;
};

int isempty(que *q)
{
    if( q->front == NULL && q->rear ==NULL)
        return  1;
    
    return 0;
}

void init(que *qu)
{
    qu->front = NULL;
    qu->rear = NULL;
}

void push(que *qu, int val)
{
    node * ptr = (node*)malloc(sizeof(node));
    ptr->next = NULL;
    ptr->a = val;

    if(qu->rear!= NULL)
        qu->rear->next = ptr;
    
    qu->rear = ptr;

    if( qu->front == NULL)
        qu->front = qu->rear;

}

int pop(que *qu)
{
    if( qu->front ==NULL)
    {
        cout<<"Underflow\n";
        return -1;
    }    

    node * ptr= qu->front;
    qu->front = qu->front->next;
    int a = ptr->a;
    free(ptr);

    return a;
}

int main()
{
    int n;
    cin>>n;
    que * qu = (que*)malloc(sizeof(que));
    init(qu);

    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        push(qu,val);
    }

    for(int i=0;i<n;i++)
       cout<<pop(qu)<<" ";
}