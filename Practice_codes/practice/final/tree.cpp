#include<iostream>
#include<stdlib.h>

using namespace std;

struct node 
{
    int val;
    node * right, * left, * parent;
};

node * insert(node *root, int val)
{
    node * newptr = new node;
    newptr->left = newptr->right = newptr->parent = NULL;
    newptr->val = val;

    if (root == NULL)
        return newptr;
    
    node *prev = NULL, * ptr = root;

    while(ptr!= NULL)
    {
        prev = ptr;
        if( ptr->val > val)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }

    if(prev->val >val)
        prev->left = newptr;
    else
        prev->right = newptr;

    newptr->parent = prev;

    return root;
}

node * minim(node * q)
{
    node * ptr = q, * prev = NULL;

    while(ptr!= NULL)
    {
        prev = ptr;
        ptr = ptr->right;
    }

    return prev;
}

node * succ( node * q)
{
    node * ptr = q;

    if( ptr->right != NULL)
        return ( minim (ptr->right));
    
    while(ptr->parent!= NULL)
    {   if(ptr->parent->left == ptr)
            return ptr->parent;
        ptr = ptr->parent;
    }   

    return NULL;
}

void inorder(node * root, int i=0)
{
    if( root == NULL)
        return;
    i++;

    inorder( root->right,i);

    for(int j=1;j<i;j++)
        cout<<"\t";
    if( succ(root)!= NULL)
        cout<<succ(root)->val<<"\n\n";
    else    
        cout<<"a\n\n";
   // cout<<root->val<<"\n\n";

    inorder( root->left,i);
}

int main()
{
    int n;
    cin>>n;

    node * root = NULL;

    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        root = insert(root,val);

    }
        inorder(root);
        cout<<"\n";
    
}