#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<math.h>

using namespace std;

typedef struct _wordR {
    char word[100];
    double x, y;
} wordR, wordr;

typedef struct _node{
    wordR w;
    _node *next;
} node, *nodePointer;

typedef nodePointer **hashTable, *nodeptrptr;


void insertH(hashTable h, int m, wordr w)
{
    node * newword = new node;
    newword->w = w;
    int i = floor(m*w.x), j = floor(m*w.y);

    newword->next = h[i][j];
    h[i][j] = newword;
}

void printH(hashTable h, int m)
{
    node * ptr;
    ofstream out;
    out.open("output.txt");

    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
        {
            ptr = h[i][j];
            out<<"["<<i<<","<<j<<"]::(";
            while(ptr!= NULL)
            {
                out<<ptr->w.word<<" ";
                ptr = ptr->next;
            }
            out<<")\n";
        }
}

void findnn(hashtable h,int m, wordr w)
{
    
}

int main()
{
    ifstream in;
    in.open("input.txt"); 

    char ch;
    int i,n,m;
    wordr w;

    in>>n>>ch;
    cout<<n<<"\n";

//     in.getline(word,100);
//     cout<<i<<"\n";

    m = ceil(sqrt(n));

    nodePointer ** h = new nodeptrptr[n];
    for(int i=0;i<n;i++)
        h[i] = new nodePointer[n];
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            h[i][j] = NULL;

    for(int i=0;i<n;i++)
    {
        in>>w.word>>w.x>>w.y;
        insertH(h,m,w);
    }

    printH(h,m);
}