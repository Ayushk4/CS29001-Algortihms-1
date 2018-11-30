#include <iostream>

using namespace std;

struct node 
{
    int a;
    char color;
    node * left, *right, *parent;
};

node * NIL;

node * insert(node * root,int a )
{
    node *q = (node *)malloc(sizeof(node));
    q->left = NIL;
    q->right = NIL;
    q->a = a;
    q->parent = NIL;
    if(root == NIL)
        return q;

    node * tmp = NIL, *ptr =root;

    while(ptr!=NIL)
    {
        tmp = ptr;
        if(ptr->a == a)
            return root;
        if(ptr->a > a)
            ptr = ptr->left;

        else   
            ptr = ptr->right;
    }

    q->parent = tmp ; 
    if(tmp->a > a)
        tmp->left = q;
    else   
        tmp->right = q;

    q->color = 'r';
    fix_color(root, q);
    return root ;
}

void fix_color(node * root, node * q)
{
    node * y = NIL;
    while (q!= root && q->parent->color == 'r')
    {
        if(q->parent == q->parent->parent->left)
        {
            y = q->parent->parent->right;
            
            if(y.color == 'b')
            {
                q->parent->color = 'r';
                y->color = 'r';
                q->parent->parent->color = 'r';
                q = q->parent->parent;
            }
            else
            {
                if( q == q->parent->right)
                {
                    q = q->parent;
                    l_rotate (root, q->parent);
                }
                z->parent->color = 'b';
                z->parent->parent->color = 'r';
                r_rotate (root, z->parent->parent);
            }
        }
        else
        {
            y = q->parent->parent->left;
            
            if(y.color == 'b')
            {
                q->parent->color = 'r';
                y->color = 'r';
                q->parent->parent->color = 'r';
                q = q->parent->parent;
            }
            else
            {
                if( q == q->parent->left)
                {
                    q = q->parent;
                    r_rotate (root, q->parent);
                }
                z->parent->color = 'b';
                z->parent->parent->color = 'r';
                l_rotate (root, z->parent->parent);
            }
        }
    }
}

void l_rotate(node *root, node * ptr)
{
    /*if(root->right == NIL)
        return root ;
    */

    node *tmp = root, *parent = NIL, *q;
    while(tmp != ptr)
    {
        parent = tmp;
        if(tmp->a > ptr->a)
            tmp = tmp->left;
        else if( tmp->a < ptr->a)
            tmp = tmp->right;
    }

    if(parent!= NIL)
    {   
        if(parent->a > tmp-> a)
            parent->left = tmp->right;
        else
            parent->right = tmp->right;

        q = tmp ;
        tmp= tmp-> right;
        q->right = tmp->left;
        tmp->left = q;
        //return root;
    }
/*
    else
    {
        q = tmp ;
        tmp = tmp-> right;
        q->right = tmp->left;
        tmp->left = q;
        return tmp;
    }*/
}

void r_rotate(node * root, node * ptr)
{
    /*
    if(root== NIL || root->left ==NIL)
        return root ;
    */

    node *tmp = root, *parent = NIL, *q = NIL;
    while(tmp != ptr)
    {
        parent = tmp;
        if(tmp->a > ptr->a)
            tmp = tmp->left;
        else if( tmp->a < ptr->a)
            tmp = tmp->right;
    }

    if(parent!= NIL)
    {   
        if(parent->a > tmp-> a)
            parent->left = tmp->left;
        else
            parent->right = tmp->left;

        q = tmp ;
        tmp= tmp-> left;
        q->left = tmp->right;
        tmp->right = q;
        q->color = 'r';
        fix_color(root, q);
        //return root;

    }
/*
    else
    {
        q = tmp ;
        tmp = tmp-> left;
        q->left = tmp->right;
        tmp->right = q;

        return tmp;
    }

*/
}


void print(node* root,int i = 0)
{
    if(root ==NIL)
        return;

    int j=i;

    i++;
    print(root->right,i);
    
    cout<<"\n\n";
    while(j--)
        cout<<"\t";
    cout<<root->a;

    print(root->left ,i);

}

void inorder(node * root)
{
    if(root!=NIL)
    {
        inorder(root->left);
        cout<<root->a<<" ";
        inorder(root->right);
    }
}

int main()
{
    NIL = (node * )malloc(sizeof(node));
    NIL->left =NIL->right =NIL;
    NIL->parent = NIL;

    int n;
    cin>>n;

    int i,a;
    node *root = NIL;

    for(i=0;i<n;i++)
    {
        cin>>a;
        root = insert(root,a);
    }

    inorder(root);

    cout<<"\n";
    print(root);
    root = l_rotate(root, root);
    cout<<"\n\n";
    print(root);

    root = l_rotate(root, root);
    cout<<"\n\n";
    print(root);

    root = r_rotate(root, root);
    cout<<"\n\n";
    print(root);
    cout<<"\n";
}