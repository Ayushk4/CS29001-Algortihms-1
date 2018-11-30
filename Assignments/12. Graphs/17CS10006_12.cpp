//Ayush Kaushal
//17CS10006

#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct _node{
	int vno;
	_node * next;
} node;

typedef struct _vertex{
	node *adjlist;
} vertex;

typedef vertex *graph;


void dfs_visit(graph g, int rem, int i, int n, int vis[],int pi[],int d[],int low[],int * time)
{
	*time = *time +1;
	d[i] = *time;
	vis[i] = 1;
	//cout<<i<<" ";

	node * ptr = g[i].adjlist;
	
	while(ptr!=NULL)
	{
		int j= ptr->vno;
		if( j!= rem)
			if( vis[j] == 0)
			{
				pi[j] = i;  
				dfs_visit(g,rem,j,n,vis,pi,d,low,time);
			}
		ptr =ptr->next;
	}
}


int DFSComp(graph g, int n, int rem)
{
	int *vis = new int[n];
	int *discovery = new int [n];
	int *pi = new int [n];
	int * d = discovery;/////////////////
	int * low = new int [n];
	
	
	for(int i=0;i<n;i++)
	{
		vis[i] = 0;
		pi[i] = 0;
		low[i] = 1;
		d[i] = 1;
	}
	
	int *time = new int;
	
	*time = 0;
	int count = 0;

	for(int i=0;i<n;i++)
		if(i != rem)
			if(vis[i] ==0)
			{	dfs_visit( g,rem,i,n,vis,pi,d,low,time);
				count++;
			}

/*
	cout<<"\n";
	for(int i=0;i<n;i++)
	{
		cout<<vis[i]<<" ";
	}
	
	cout<<"\n";
	for(int i=0;i<n;i++)
	{
		cout<<pi[i]<<" ";
	}
	
	cout<<"\n";
	for(int i=0;i<n;i++)
	{
		cout<<d[i]<<" ";
	}
*/

/*
	cout<<"\n";
	for(int i=0;i<n;i++)
	{
		cout<<low[i]<<" ";
	}
	cout<<"\n";
*/

	free(vis);
	free(d);
	free(pi);
	free(low);
	
	return count;
}

void findCritical(graph G, int n)
{
	for(int i=0;i<n;i++)
	{
		int result = DFSComp(G,n,i);
		if(result >1)
			cout<<"\nVertex "<<i<<": "<<result<<" Components";
	}
}







int dfs_visit_fast(graph g, int i, int n, int vis[],int pi[],int d[],int low[],int * time)
{
	*time = *time +1;
	d[i] = *time;
	vis[i] = 1;
	if(i != 0)
		low[i] = 100000;

	//cout<<i<<" ";

	node * ptr = g[i].adjlist;
	
	while(ptr!=NULL)
	{
	
		int j= ptr->vno;
		if( j ==pi[i])
		{	
			//continue;
		}
		else
		{
			if( vis[j] == 0)
			{
				pi[j] = i;  
				int res = dfs_visit_fast(g,j,n,vis,pi,d,low,time);
				if( low[i]>res)
					low[i] = res;
				
			}
			else
			{
				int res = d[j];
					//cout<<"back"<<i<<" " <<j<<" \n";
				
				if( low[i]>res)
				{
					low[i] = res;
					//cout<<"back"<<i<<" " <<j<<" \n";
				}
			}
		}
		ptr = ptr->next;
	}
	return low[i];
}


int * DFSComp_fast(graph g, int n,int s)
{
	int *vis = new int[n];
	int *discovery = new int [n];
	int *pi = new int [n];
	int * d = discovery;/////////////////
	int * low = new int [n];
	
	
	for(int i=0;i<n;i++)
	{
		vis[i] = 0;
		pi[i] = 0;
		low[i] = 1;
		d[i] = 1;
	}
	
	
	
	int *time = new int;
	
	*time = 0;
	pi[s] =-1;
	
	dfs_visit_fast( g,s,n,vis,pi,d,low,time);


	int *is_critical = new int[n];
	int *ans = new int [n];
	
	for(int i=0;i<n;i++)
	{	is_critical[i] = -1;
		ans[i] = 0;
	}
	for(int i=1;i<n;i++)
		if( low[i]>=d[pi[i]])
			is_critical[i] = pi[i];

	for(int i=0;i<n;i++)
		if( is_critical[i] !=-1 && pi[i]!= 0)
			ans[is_critical[i]] = 1;

	
	free(vis);
	free(d);
	free(pi);
	free(low);
	free(is_critical);
	return ans;
}

void findCriticalFast(graph G, int n)
{
	int *res1 = DFSComp_fast(G,n,0);
	int *res2 = DFSComp_fast(G,n,2); // to check if the start node is critical, as in previous call it was ignored
	if( res2[0] ==1)
		cout<<"\nVertex "<<0<<" is a critical junction";


	for(int i=1;i<n;i++)
		if(res1[i]>0)
			cout<<"\nVertex "<<i<<" is a critical junction";

	free(res1);
	free(res2);
	
}


int main()
{
	int n,e;
	cout<<"Enter the number of vertices and edges";
	cin>>n>>e;
	
	int * degree = new int [n];
	
	graph g = new vertex[n];
	for(int i=0;i<n;i++)
	{	g[i].adjlist = NULL;
		degree[i] = 0;
	}

	cout<<"\nEnter the neighbours for each of the vertex";
	for(int i=0;i<n;i++)
	{
		cout<<"\nDegree of Vertex "<< i <<" : "; 
		cin>>degree[i];
		cout<<"\nNeighbours of Vertex "<< i << " : ";
		for(int j=0;j<degree[i];j++)
		{
			int neigh;
			cin>>neigh;
			
			node * ptr = new node;
			ptr->vno = neigh;
			ptr->next = g[i].adjlist;
			
			g[i].adjlist = ptr;
		}
	}
	cout<<"\nAdjacency list of the graph:";
	for(int i=0;i<n;i++)
	{
		node * ptr = g[i].adjlist;
		cout<<"\nVertex "<<i<<": ";
		while(ptr != NULL)
		{
			cout<<ptr->vno<<" ";
			ptr = ptr->next;
		}	
	}

	cout<<"\nCritical junctions using simple algorithm :";
	findCritical(g,n);

	cout<<"\nCritical junctions using fast algortihm:";
	findCriticalFast(g,n);



	cout<<"\n";		
	free(degree);
	free(g);
}
























