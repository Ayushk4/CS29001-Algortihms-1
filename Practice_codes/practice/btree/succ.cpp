#include<iostream>
#include<stdlib.h>

using namespace std;

////////either min(node->right)
////////parent jiska ye left child hai

struct node{
    int val;
    node * left, *right, * parent;
};

node * insert(node * root, int val)
{
    if(root == NULL)
    {
        node *ptr = new node;
        ptr->left = ptr->right = ptr->parent = NULL;
        ptr->val =val;
        return ptr;
    }

    if(root->val > val)
    {
        if( root->left == NULL)
        {
            node *ptr = new node;
            ptr->left = ptr->right = NULL;
            ptr->parent = root;
            ptr->val =val;
            root->left = ptr;   
        }
        else
            root->left = insert(root->left,val);
    }

    if( root->val < val)
    {
        if(root->right == NULL)
        {
            node *ptr = new node;
            ptr->left = ptr->right = NULL;
            ptr->parent = root;
            ptr->val =val;
            root->right = ptr;  
        }
        else
            root->right = insert(root->right,val);
    }

    return root;
}


void inorder(node * root, int i)
{
    if(root==NULL)
        return;
    i++;

    inorder(root->right,i);

    for(int j=0;j<i-1;j++)
        cout<<"\t  ";
    cout<<root->val<<"\n\n";

    inorder(root->left,i);
}

int min(node * root)
{
    node * ptr =root, *q= root;

    while(ptr!= NULL)
    {
        q = ptr;
        ptr = ptr->left;
    }

    return q->val;
}

void succ(node * root, int val)
{
    if(root == NULL)
    {
        cout<<"Not found\n";
        return;
    }
    
    if( root->val> val)
        succ(root->left, val);
    else if( root->val<val)
        succ(root->right, val);
    else
    {
        if(root->right == NULL)
        {
            node * ptr = root;
            while(ptr->parent!= NULL)
            {
                if(ptr->parent->left == ptr)
                {
                    cout<<ptr->parent->val<<"\n";
                    return;
                }
                ptr = ptr->parent;
            }

            cout<<"Not found\n";
            return;
        }
        else
            cout<<min(root->right)<<"\n";
    }
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

    inorder(root,0);

    succ(root, 492);

    //for(int i=0;i<n;i++)
    //{

    succ(root, 221);
    
    //cout<<"\n"
}