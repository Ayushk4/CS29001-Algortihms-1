#include <iostream>

using namespace std;

struct node {
    int a;
    node *left , *right, *parent;
};

node * insert(node *root, int a)
{
    node * q,*p=root;
    q=(node*)malloc(sizeof(node));
    q->a = a;
    q->left= NULL;
    q->right=NULL;
    q->parent=NULL;

    if(root==NULL)
    {
        return q;
    }

    node * tmp=NULL;

    while(p!=NULL)
    {
        tmp=p;
        if(p->a==a)
            return root;
        else if(p->a>a)
            p=p->left;
        else   
            p=p->right;
    }

    q->parent=tmp;
    if(tmp->a>a)
        tmp->left = q;
    else
        tmp->right =q;

    return root;
}

node * suc(node * q)
{
    if(q->right!=NULL)
    {
        q = q->right;
        while(q->left!=NULL)
            q=q->left;

        return q;
    }

    else
    {
        while(q!=NULL && q->parent!=NULL && q->a > q->parent->a)
            q=q->parent;

        if(q==NULL||q->parent==NULL)
            return NULL;

        return q->parent;
    }
}

node * min(node *q)
{
    while(q->left!=NULL)
        q=q->left;

    return q;
}

node * max(node *q)
{
    while(q->right!=NULL)
        q=q->right;

    return q;
}

node * succ(node *root, node * ptr)
{
    if(ptr->right!=NULL)
        return(min(ptr->right));
    
    node * tmp=root;
    
    while(root!=ptr)
    {
        if(root->a > ptr->a)
        {
            tmp = root;
            root = root->left;
        }

        else
            root= root->right;
    }

    return tmp;
}

void inorderr(node * root)
{
    if(root==NULL)
        return ;

    node * maxim = max (root),*top =root;
    root = min(root);

    cout<<root->a<<" ";
    while(root!=maxim)
    {
        root = succ(top,root);
        cout<<root->a<<" ";
    }
    
}

void inorder(node * root)
{
    if(root==NULL)
        return ;

    node * maxim = max (root);
    root = min(root);

    cout<<root->a<<" ";
    while(root!=maxim)
    {
        root = suc(root);
        cout<<root->a<<" ";
    }
    
}

void recur_inorder(node * root)
{
    if(root==NULL)
        return;

    recur_inorder(root->left);
    cout<<root->a<<" ";
    recur_inorder(root->right);
}

int main()
{
    int n,a;
    cin>>n;

    node *root=NULL;
    for(int i=0;i<n;i++)
    {       cin>>a;
            root = insert(root,a);
    }
    
    recur_inorder(root);
    //cout<<"\n\n"<<suc(max(root));
    cout<<"\n\n";
    inorder(root);
    cout<<"\n";

    cout<<"\n\n";
    inorderr(root);
    cout<<"\n";
}