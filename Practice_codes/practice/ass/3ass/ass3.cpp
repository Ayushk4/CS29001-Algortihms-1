#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;


typedef struct treenode
{
    char word[100];
    treenode *left,*right,*parent;
} NODE, *NODEPTR, node, *nodeptr;

NODEPTR insert(NODEPTR root)
{
    node * newptr = new node;
    cin>>newptr->word;
    newptr->left = newptr->right = NULL;

    if(root == NULL)
    {
        newptr->parent = NULL;
        return newptr;
    }

    node * tmp = NULL, *ptr = root;

    while(ptr!= NULL)
    {

        tmp = ptr;
        if(strcmp(ptr->word,newptr->word) == 0)
            return NULL;
        if(strcmp(ptr->word,newptr->word) >0)
            ptr = ptr->left;
        else
            ptr = ptr->right;
       
    }

    if(strcmp(tmp->word,newptr->word) >0)
        tmp->left = newptr;
    else
        tmp->right = newptr;

    newptr->parent = tmp;
    return root;
}

void inorder(node * root, int i)
{
    if( root == NULL)
        return;
    i++;

    inorder(root->right,i);
    for(int j=0;j<i-1;j++)
        cout<<"\t";
    cout<<root->word<<"\n";
    inorder(root->left,i);
}

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
        if(strcmp(root->word, ptr->word))
        {
            tmp = root;
            root = root->left;
        }

        else
            root= root->right;
    }

    return tmp;
}

int match_str(char w1[100],char w2[100])
{
    int i=0;
    //char ch=w2[i];
    
    while(w2[i] != '\0'&& w1[i] != '\0')
    {
        if(w1[i]>w2[i])
            return -1;
        else if(w1[i]<w2[i])
            return 1;
        i++;
    }
    if(w2[i]=='\0')
        return 0;
    else
        return 1;
}


void find_extensions(NODEPTR root, char pattern[100])
{
//COMING FROM LEFT/RIGHT
//PRINT AS YOU COME UP
//EXPLORE TILL DEPTH WHERE REASONABLE
//start from root
//for each node reached
//if(node != prefix match)
//  explore left or right whichever relevant
//else
//  explore left first, and right while coming up.else

//basically go down till relevant. do the checking and stuff while coming up.

//-1 , l/r go up
//-1,  p go left
//1, p go right
//1, l/r go up
//0, l print and go right
//0, r, go up
//0, p, go left


    if(root == NULL)
        return;

    node *ptr = root->left, *lim = root, *prev= root, * last_leaf;
    int match;
    char comin_from = 'p';

    while(ptr!= lim)
    {
        if(ptr == NULL)
        {
            if(last_leaf != prev)
                comin_from = 'l';
            else
                comin_from = 'r';        
            ptr = prev;
            last_leaf = prev;
            continue;
        }

        prev = ptr;
        match = match_str(ptr->word, pattern);

        if( match == -1)
        {
            if(comin_from == 'p')
            {
                comin_from = 'p';
                ptr = ptr->left;
            }
            else
            {
                if(ptr->parent->left == ptr)
                    comin_from = 'l';
                else
                    comin_from = 'r';

                ptr = ptr->parent;
            }
        }
        if( match == 1)
        {
            if(comin_from == 'p')
            {
                comin_from = 'p';
                ptr = ptr->right;
            }
            else
            {
                if(ptr->parent->left == ptr)
                    comin_from = 'l';
                else
                    comin_from = 'r';

                ptr = ptr->parent;
            }
        }
        if( match == 0)
        {
            if( comin_from == 'l')
            {
                cout<<ptr->word<<"\n";
                comin_from = 'p';
                ptr = ptr->right;
            }
            else if( comin_from == 'r')
            {
                if(ptr->parent->left == ptr)
                    comin_from = 'l';
                else
                    comin_from = 'r';

                ptr = ptr->parent;
            }
            else if( comin_from == 'p')
            {
                comin_from = 'p';
                ptr = ptr->left;
            }
        }
    }

    comin_from = 'p';

    if(match_str(root->word, pattern) == 0)
        cout<<root->word<<"\n";

    ptr = root->right;

    while(ptr!= lim)
    {




    //if(i==5)
        //cout<<ptr->word<<"aaaaaaaaaa";
    
        if(ptr == NULL)
        {
            if(last_leaf != prev)
                comin_from = 'l';
            else
                comin_from = 'r';

            ptr = prev;
            last_leaf = prev;
            continue;
        }
    
        prev = ptr;
        match = match_str(ptr->word, pattern);
        //cout<<ptr->word<<" "<<comin_from<<"\n";
        if( match == -1)
        {
            if(comin_from == 'p')
            {
                comin_from = 'p';
                ptr = ptr->left;
            }
            else
            {
                if(ptr->parent->left == ptr)
                    comin_from = 'l';
                else
                    comin_from = 'r';

                ptr = ptr->parent;
            }
        }
        if( match == 1)
        {
            if(comin_from == 'p')
            {
                comin_from = 'p';
                ptr = ptr->right;
            }
            else
            {
                if(ptr->parent->left == ptr)
                    comin_from = 'l';
                else
                    comin_from = 'r';

                ptr = ptr->parent;
            }
        }
        if( match == 0)
        {
            if( comin_from == 'l')
            {
                cout<<ptr->word<<" ";
                comin_from = 'p';
                ptr = ptr->right;
             //   cout<<ptr->word<<"\n";
            }
            else if( comin_from == 'r')
            {
                if(ptr->parent->left == ptr)
                    comin_from = 'l';
                else
                    comin_from = 'r';

                ptr = ptr->parent;
            }
            else if( comin_from == 'p')
            {
                comin_from = 'p';
                ptr = ptr->left;
            }
        }
        //if(ptr!=NULL)
        //    cout<<ptr->right->word<<" "<<comin_from<<" ";
        //cout<<"\n";
    }
    cout<<"\n";
}

node * del(node * root,char patt[100])
{
    if(root == NULL)
        return NULL;

    root->left = del(root-left,patt);
    root->right = del(root-right,patt);

    int match = str_match(root->word,patt);

    if(match == 0)
    {
        if(root->right == NULL)
            return root->left;
        else if(root->left == NULL)
            return root->right;
        else if{
            node * ptr = min(root->right);
            ptr->
        }
    }
}

int main()
{
    int n;
    cin>>n;

    node * root = NULL;

    for(int i=0;i<n;i++)
        root = insert(root);

    inorder(root,0);
    cout<<"\n";

    char pre[100];
    cin>>pre;

    find_extensions(root,pre);
}