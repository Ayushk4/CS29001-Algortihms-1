#include<iostream>
#include<stdlib.h>

using namespace std;

struct node
{
    int val;
    char color;
    node * left, * right, * parent;
};

node * NIL = new node;

node * l_rot(node * root, node * ptr)
{
    if(ptr->right == NIL)
        return root;

    if(ptr == root)
        root = root->right;

    node * tmp = ptr->right;
    ptr->right = tmp->left;
    if( tmp->left!= NIL)
        tmp->left->parent = ptr;
    tmp->left = ptr;
    tmp->parent = ptr->parent;
    ptr->parent = tmp;
    if(tmp->parent->left == ptr)
        tmp->parent->left = tmp;
    else
        tmp->parent->right = tmp;

    return root;
}


node * r_rot(node * root, node * ptr)
{
    
    if(ptr->left == NIL)
        return root;

    if(ptr == root)
        root = root->left;

    node * tmp = ptr->left;
    ptr->left = tmp->right;
    if( tmp->right!= NIL)
        tmp->right->parent = ptr;
    tmp->right = ptr;
    tmp->parent = ptr->parent;
    ptr->parent = tmp;
    if(tmp->parent->left == ptr)
        tmp->parent->left = tmp;
    else
        tmp->parent->right = tmp;

    return root;
}

node * fix(node * root, node *ptr)
{
    node * y= NIL;
    while(ptr!= NIL && ptr->parent->color == 'r')
    {
        if(ptr->parent == ptr->parent->parent->left)
        {
                    //
            y = ptr->parent->parent->right;
            if(y->color == 'r')
            {
                y->color = 'b';
                y->parent->color = 'r';
                ptr->parent->color = 'b';
                ptr = y->parent;
            }
            else
            {
                if(ptr == ptr->parent->right)
                {
                    ptr = ptr->parent;
                    root = l_rot(root, ptr);
                }
                ptr->parent->color = 'b';
                ptr->parent->parent->color ='r';
                root = r_rot(root, ptr->parent->parent);

            }
        }
    
        else
        {
            y = ptr->parent->parent->left;
            if(y->color == 'r')
            {
                y->color = 'b';
                y->parent->color = 'r';
                ptr->parent->color = 'b';
                ptr = y->parent;
            }
            else
            {
                if(ptr == ptr->parent->left)
                {
                    ptr = ptr->parent;
                    root = r_rot(root, ptr);
                }
                ptr->parent->color = 'b';
                ptr->parent->parent->color ='r';
                root = l_rot(root, ptr->parent->parent);
            }
        }  
    }
    root->color = 'b';
    return root;
}


node * insert(node * root, int val)
{
    node * q = new node;
    q->left = q->right = q->parent = NIL;
    q->color = 'r';
    q->val = val;

    if(root == NIL)
    {
        q->color = 'b';
        return q;
    }
    node * prev = NIL,*ptr = root;

    while(ptr != NIL)
    {
        prev = ptr;

        if(ptr->val>val)
            ptr = ptr->left;
        else if( ptr->val<val)
            ptr = ptr->right;
        else
            return root;
    }

    q->parent = prev;
    if( q->parent->val > q->val)
        q->parent->left = q;
    else
        q->parent->right = q;


    root = fix(root,q);
    //cout<<"a\n";
    return root;
}

void inorder(node * root, int i=0)
{
    if( root == NIL)
        return;
    i++;

    inorder(root->right,i);
    for(int j=0;j<-1;j++)
        cout<<"\t";
    cout<<root->val<<root->color<<"\n\n";
    inorder(root->left,i);
}

void preorder(node * root)
{
    if (root == NULL)
        return;
    
    cout<<root->val<<" ";

    preorder(root->left);
    preorder(root->right);
}
int main()
{
    int n;
    cin>>n;

    NIL-> left = NIL-> right = NIL -> parent = NIL;
    NIL-> color ='b';

    node * root = NIL;

    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        root = insert(root,val);

//        inorder(root,0);
//        cout<<"\n\n\n";
    }

    preorder(root);
    inorder(root);

}