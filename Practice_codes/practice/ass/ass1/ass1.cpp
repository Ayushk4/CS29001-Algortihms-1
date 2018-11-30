#include<iostream>

using namespace std;


struct node {
    int val;
    node *xorr;
};

struct  linky {
    node * head, * tail;
};

void init(linky * l)
{
    l->head = NULL;
    l->tail = NULL;
}

void insert( linky * l, int val)
{
    node * ptr = new node;
    ptr->val = val;
    ptr->xorr = l->head;

    if( l->head == NULL)
    {
        l->head = ptr;
        l->tail = ptr;
    }
    else
    {
        l->head->xorr = ((unsigned long int) l->head->xorr ^ (unsigned long int) ptr);
        l->head = ptr;
    }

}

void reverse(node ** head, node **tail)
{
    node * tmp = *tail;
    *tail = *head;
    *head = tmp;
}


void traverse_from_front(node * head)
{
    node * ptr = head, * prev = NULL;

    while(ptr!= NULL)
    {
        cout<<ptr->val<<" ";
        node * tmp = ptr;
        ptr = (unsigned long int) prev ^ (unsigned long int) ptr->xorr;
        prev = tmp;
    }
}

void traverse_from_end(node * head)
{
    node * ptr = head, * prev = NULL;

    while(ptr!= NULL)
    {
        //cout<<ptr->val<<" ";
        node * tmp = ptr;
        ptr = (unsigned long int) prev ^ (unsigned long int) ptr->xorr;
        prev = tmp;
    }

    traverse_from_front(prev);

}



void * sortt(node ** head, node ** tail)
{
//use mergeeeee


//    while(ptr != NULL)
// divide
// call individ
// call indiv
// merge

//    if

}

int main()
{
    int n;
    cin>>n;

    linky * l = new linky;
    init(l);

    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;

        insert(l, a);
    }
    
    node * head = l->head, * tail = l->tail;
    reverse(&(l->head), &(l->tail));
    //l->head = head;
    //l->tail = tail;

    traverse_from_front(l->head);
    cout<<"\n";
    traverse_from_end(l->head);
    cout<<"\n";

//    cout
}