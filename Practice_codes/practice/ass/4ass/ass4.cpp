#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct node{
    int value;
    node * left, * right, * parent;
} NODE, *NODEPTR;

node * l_rot(node * root, node * ptr)
{
    if(ptr->right == NULL)
        return root;

    if(ptr == root)
        root = root->right;

    node * tmp = ptr->right;
    ptr->right = tmp->left;
    if( tmp->left!= NULL)
        tmp->left->parent = ptr;
    tmp->left = ptr;
    tmp->parent = ptr->parent;
    ptr->parent = tmp;


    if(tmp->parent!= NULL)
    {
        if(tmp->parent->left == ptr)
            tmp->parent->left = tmp;
        else
            tmp->parent->right = tmp;
    }

    return root;
}


node * r_rot(node * root, node * ptr)
{
    
    if(ptr->left == NULL)
        return root;

    if(ptr == root)
        root = root->left;

    node * tmp = ptr->left;
    ptr->left = tmp->right;
    if( tmp->right!= NULL)
        tmp->right->parent = ptr;
    
    tmp->right = ptr;
    tmp->parent = ptr->parent;
    ptr->parent = tmp;
    

    if(tmp->parent!= NULL)
    {
        if(tmp->parent->left == ptr)
            tmp->parent->left = tmp;
        else
            tmp->parent->right = tmp;
    }
    return root;
}

NODEPTR makeroot(NODEPTR root, NODEPTR n)
{
    if(root->right == n)
        root = l_rot(root,root);

    else
        root = r_rot(root,root);

    return root;
}

NODEPTR sameorientation(NODEPTR root, NODEPTR n)
{
    if(n->parent->right == n)
    {
        root = l_rot(root,n->parent->parent);
        root = l_rot(root,n->parent);
    }
    else
    {
        root = r_rot(root,n->parent->parent);
        root = r_rot(root,n->parent);
    }
    return root;
}

NODEPTR oppositeorientation(NODEPTR root, NODEPTR n)
{
    if(n->parent->right == n)
    {
        root = l_rot(root,n->parent);
        root = r_rot(root,n->parent);
    }
    else
    {
        root = r_rot(root,n->parent);
        root = l_rot(root,n->parent);
    }
    return root;
}

node * lift(node * root, node * ptr)
{
    if(ptr== NULL)
        return root;

    while(root != ptr)
    {
        //cout<<"asfd\n"<<ptr;
        node * par = ptr->parent;

        if(par == root)
            root = makeroot(root, ptr);
        else if(par->left == ptr)
            {
                if(par->parent->left == par)
                    root = sameorientation(root,ptr);
                else
                    root = oppositeorientation(root,ptr);
            }
        else
        {
            if(par->parent->right == par)
                root = sameorientation(root,ptr);
            else
                root = oppositeorientation(root,ptr);
        
        }
    }
}

NODEPTR insert(NODEPTR root, int key)
{
    node * ptr = new node;
    ptr->left= ptr->right = ptr->parent = NULL;
    ptr->value = key;

    if (root == NULL)
        return ptr;

    node * tmp = NULL, *q = root;

    while(q != NULL)
    {
        tmp = q;
        if( q->value > key)
            q = q->left;
        else
            q = q->right;
    }

    if(tmp->value > key)
        tmp->left = ptr;
    else
        tmp->right = ptr;

    ptr->parent = tmp;

    root = lift(root,ptr);

    return root;
}


node * minim(node * ptr)
{
    node * prev = NULL;

    while( ptr != NULL)
    {
        prev = ptr;
        ptr = ptr->left;
    }
    return prev;
}


NODEPTR delet(NODEPTR root, int key)
{
    node * ptr = root;

    while(ptr->value != key)
    {
        if(ptr->value>key)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }

    node * q = ptr->parent, *rep= NULL;

    if(ptr->left == NULL && ptr->right == NULL)
        rep = NULL;
    else if (ptr->left == NULL)
        rep = ptr->right;
    else if (ptr->right == NULL)
        rep = ptr->left;
    else
    {
        rep = minim(ptr->right);
        
        if( rep->parent->left == rep )
            rep->parent->left = rep->right;
        else
            rep->parent->right = rep->right;

        rep->left = ptr->left;
        rep->right = ptr->right;
    
        //rep = min_node;
    }

    if( ptr->parent->left == ptr )
        ptr->parent->left = rep;
    else
        ptr->parent->right = rep;

    root = lift(root,ptr->parent);
    return root;

}


void printtree(node * root, int i=0)
{
    if( root == NULL)
        return;

    i++;
    printtree(root->left, i);

    for(int j=0; j<1-1; j++)
        cout<<"      ";
    cout<<root->value<<" ";//\n\n";

    printtree(root->right, i);
}

void preorder(node * root)
{
    if (root == NULL)
        return;
    
    cout<<root->value<<" ";

    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int n;
    cin>>n;

    node* root = NULL;

    for(int i=0;i<n;i++)
    {
        int key;
        cin>>key;
        //cout<<"Inserting "<<key<<" :\n";
        root = insert(root,key);
        //printtree(root);
        //cout<<"\n\n\n";
    }
    preorder(root);
    cout<<"\n";
    printtree(root);
    cout<<"\n\n\n";

    //root = makeroot(root,root->right);
    //root = sameorientation(root,root->left->right->right);
    //printtree(root);
    //root = oppositeorientation(root,root->left->right);
    //cout<<"\n\n\n\n";
    //printtree(root);

    preorder(delet(root,4));

}