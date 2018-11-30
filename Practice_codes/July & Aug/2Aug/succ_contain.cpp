#include<iostream>

using namespace std;

struct node {
    int a;
    node *left,*right,*succ;
};


node * min(node *q)
{
    while(q->left!=NULL)
        q=q->left;

    return q;
}

node * successor(node *root, node * ptr)
{
    if(ptr->right!=NULL)
        return(min(ptr->right));
    
    node * tmp=NULL;
    
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

node * insert(node *root, int a)
{
    node * q,*p=root;
    q=(node*)malloc(sizeof(node));
    q->a = a;
    q->left = NULL;
    q->right = NULL;
    q->succ = NULL;

    if(root == NULL)
    {
        return q;
    }

    node * tmp = NULL;

    while(p != NULL)
    {
        tmp = p;
        if(p->a == a)
            return root;
        else if(p->a > a)
            p = p->left;
        else   
            p = p->right;
    }

    //q->parent=tmp;
    
    if(tmp->a > a)
        tmp->left = q;
    else
        tmp->right = q;

    return root;
}

void traversalandsucc(node * root,node * ptr)
{
    if(ptr!=NULL)
    { 
        traversalandsucc(root,ptr->left);
        ptr->succ = successor(root, ptr);
        cout<<ptr->a<<" ";
        traversalandsucc(root,ptr->right);
    }
}


void inorder(node * root)
{
    if(root!=NULL)
    { 
        inorder(root->left);
        cout<<root->a<<" ";
        inorder(root->right);
    }
}

void inordersuccessive(node * root)
{
    root =min(root);

    while(root!=NULL)
    {
        cout<<root->a<<" ";
        root=root->succ;
    }
}

int main()
{
    int n;
    cin>>n;

    int i,a;
    node* root=NULL;

    for(i=0;i<n;i++)
    {
        cin>>a;
        root = insert(root,a);
    }

    inorder(root);
    cout<<"\n\n";

    traversalandsucc(root,root);
    cout<<"\n\n";

    inordersuccessive(root);
}
