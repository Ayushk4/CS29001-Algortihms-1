#include<iostream>

using namespace std;

struct node 
{
    int data;
    node * left, * right;
};

node * insert(node * root, int a)
{
    if( root == NULL)
    {
        node * ptr = new node;
        ptr->left = ptr->right = NULL;
        ptr->data = a;
        return ptr;
    }

    if( root->data == a)
        return root;
    if( root->data > a)
        root->left = insert (root->left, a);
    else
        root->right = insert (root->right, a);

    return root;
}

node * minim(node * root)
{

    node *ptr = root, *prev = NULL;
    while( ptr->left!=NULL)
    {
        //cout<<"\na";
        prev = ptr;
        ptr = ptr->left;
    }
    prev->left = NULL;
    return ptr;
}

node * del(node * root, int a)
{
    if( a == root->data)
    {
        node * ptr = root;
        if( root->left == NULL)
            return root->right;
        else
            if( root->right == NULL)
                return root->left;
            else 
            {        
                node * mini = minim (root->right);
                mini-> left = root->left;
                mini->right = root->right;
                return mini;
            }
        
    }

    if(a<root->data)
        root->left = del(root->left, a);
    else
        root->right = del(root->right, a);

    return root;
}


void succ(node * root, int a)
{
    if(a == root->data)
    {
        if(root->right != NULL)
            cout<<minim (root->right);
        else
    }
    else
    {
        if(a<root.data))
        {
            succ(root->left, a);
        }
        else
        {
            succ(root->right, a);
        }
    }
}
void inorder( node * root)
{
    if( root == NULL)
        return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    int n;
    cin>>n;

    node * root = new node;
    root = NULL;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;

        root = insert(root,a);
    }

    inorder(root);
    cout<<"\n";

    root = del(root,221);
    inorder(root);
    cout<<"\n";
}