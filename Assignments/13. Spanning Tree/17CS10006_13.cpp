//Ayush Kaushal
//17CS10006

#include<iostream>
#include<stdlib.h>

using namespace std;

typedef int **graph;

struct node 
{
    int val;
    node* next;
};

struct edge
{
	int u, v, weight;
};

struct qu{
	node *head, *rear;
};

void init(qu* q)
{
	q->head = q->rear = NULL;
}
void push(qu *q, int val)
{
	node * ptr = (node*)malloc(sizeof(node));
	ptr->val = val;
	ptr->next = NULL;
	if(q->rear == NULL )
	{
		q->head = q->rear = ptr;
		return;
	}

	q->rear->next =ptr;
	q->rear = ptr;
}
int pop (qu* q)
{
	if( q->head == NULL)
		return -1;

	node * ptr= q->head;
	q->head = q->head->next;
	int val = ptr->val;

	if( q->head == NULL)
		q->rear = NULL;

	free(ptr);
	return val;
}


int isConnectedUsingBFS(graph g, int NumberOfNodes)
{
	int n= NumberOfNodes;

	int * vis = new int[n];
	int * d = new int[n];
	int * pi = new int[n];
	
	for(int i=0;i<n;i++)
	{
		vis[i] = 0;
		d[i] = -1;
		pi[i] = -1;
	}

	qu * q = new qu;
	init(q);

	d[4] = 0;
	vis[4] = 1;
	push(q,4);

	while(q->head!= NULL)
	{
		int u = pop(q);
		
		for(int j=0;j<n;j++)
		{
			if(g[u][j] > 0)
				if( vis[j] ==0 )
				{
					vis[j] = 1;
					d[j] = d[u] +1;
					pi[j] = u;
					push(q,j);
				}
		}
	}
/*
	cout<<"\n";
	for(int i=0;i<n;i++)
		cout<<vis[i]<<" ";
	cout<<"\n";
	for(int i=0;i<n;i++)
		cout<<d[i]<<" ";
	cout<<"\n";
	for(int i=0;i<n;i++)
		cout<<pi[i]<<" ";
	cout<<"\n";
*/
	int isconnected = 1;
	
	for(int i=0;i<n;i++)
		if(vis[i] !=1)
		{
			isconnected = 0;
			break;
		}	

	return isconnected;
}





void merge(edge a[], int low, int mid, int high)
{
	int l=low, r= mid, i=0;
	edge *b = new edge[high - low];
	while( l<mid && r< high)
	{
		if( a[l].weight  > a[r].weight)
		{
			b[i] = a[l];
			l++;
			i++;
		}
		else
		{
			b[i] = a[r];
			r++;
			i++;
		}        
	}
	while( r<high)
	{
		b[i] = a[r];
		r++;
		i++;
	}
	while( l<mid)
	{
		b[i] = a[l];
		l++;
		i++;
	}
	for(int j=0;j<i;j++)
		a[low+j] = b[j];

	free(b);
}

void mergesort(edge a[], int low, int high)
{
	if(  (high -low) <2)
		return ;

	int mid = (low + high)/2;
	mergesort(a, low ,mid);
	mergesort(a, mid, high);
	merge (a, low, mid, high);
	return;
}


void findMST(graph G, int numberOfNodes)
{
	graph g = G;
	int n = numberOfNodes;

	//count number of edges
	int e =0; 
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(g[i][j]>0)
				e++;

	e = e/2;

	//Make an array for edges and sort them as per their weight in non - decreasing order

	edge * edges = new edge[e];
	int k = 0;
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++)
			if(g[i][j]>0)
			{
				edges[k].u = i;
				edges[k].v = j;
				edges[k].weight = g[i][j];
				k++;
			}

	mergesort(edges,0,k);

//	for(int i=0;i<k;i++)
//		cout<<edges[i].u<<" "<<edges[i].v<<" "<<edges[i].weight<<"\n";

	for(int i=0;i<k;i++)
	{
		g[edges[i].u][edges[i].v] = 0;
		g[edges[i].v][edges[i].u] = 0;
		if(isConnectedUsingBFS(g, n) == 0)
		{
			g[edges[i].u][edges[i].v] = edges[i].weight;
			g[edges[i].v][edges[i].u] = edges[i].weight;
		}
	}

	free(edges);
}

int main()
{
	int n,m;
	cout<<"Enter the number of nodes and edges";
	cin>>n>>m;

	graph g = new int *[n];
	
	for(int i=0;i<n;i++)
		g[i] = new int[n];

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			g[i][j] = 0;

	cout<<"\nEnter the neighbours of each node and corresponding weights";
	for(int i=0;i<n;i++)
	{
		int deg;
		cout<<"\nDegree of Vertex "<<i<<": ";
		cin>>deg;
		cout<<"\nNeighbours of "<<i<<": ";
		
		for(int j=0;j<deg;j++)
		{
			int to, weight;
			cin>>to>>weight;
			g[i][to] = weight;
		}
	}

	cout<<"\nThe neighbours of each node in the input graph and the corresponding weights";
	for(int i=0;i<n;i++)
	{
		cout<<"\nVertex "<<i<<": ";
		for(int j=0;j<n;j++)
			if( g[i][j] >0)
				cout<<j<<" "<<g[i][j]<<" ";
	}
	//cout<<"\n";
	//cout<<	isConnectedUsingBFS(g,n);
	findMST(g,n);

	cout<<"\nThe neighbours of each node of the MST you compute and the corresponding weights";
	for(int i=0;i<n;i++)
	{
		cout<<"\nVertex "<<i<<": ";
		for(int j=0;j<n;j++)
			if( g[i][j] >0)
				cout<<j<<" "<<g[i][j]<<" ";
	}
	cout<<"\n";
/*
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<g[i][j]<<" ";
		cout<<"\n";
	}
*/
	for(int i=0;i<n;i++)
		free(g[i]);

	free(g);
}

