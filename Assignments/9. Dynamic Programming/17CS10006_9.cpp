//Ayush Kaushal
//17CS10006

#include<iostream>
#include<stdlib.h>

using namespace std;

int maxim_( int x, int y)
{
	if(x>y)
		return x;

	return y;
}

int A(int N, int l, int **m)
{
	
	if(N<1)
	{	cout<<"Invalid\n";
		return -1;
	}
	if( N==1)
	{	//m[N-1][l] = l;
		return l;
	}
	if( l==0)
		return 0;
	if( m[N-1][l] >0)
		return m[N-1][l];

	int min_days = l+1;

	for ( int x =1;x<=l;x++)
	{
		int curr_iter = maxim_( A(N,l-x,m), A(N-1,x-1,m) );
		if( min_days > curr_iter)
			min_days = curr_iter;
	}

	m[N-1][l] = min_days + 1;

	return m[N-1][l];
}

int findMinimumDays(int N, int T)
{
	int **m;
	m = (int**)malloc(sizeof(int*)*(N));
	
	for(int i=0;i<N;i++)
		m[i] = (int *) malloc(sizeof(int) * (T+1));

	for(int i=0;i<N;i++)
		for(int j=0;j<=T;j++)
			m[i][j] = 0;


	int answer_ = A(N,T,m);

	//cout<<answer_;
/*
	for(int i=0;i<N;i++)
	{	for(int j=0;j<=T;j++)
			cout<< m[i][j]<<" ";
		cout<<"\n";
	}
*/
	for(int i=0;i<N;i++)
		free(m[i]);
	free(m);
	
	return answer_;
}





int A2(int N, int l, int **m)
{
	
	if(N<1)
	{	cout<<"Invalid\n";
		return -1;
	}
	if( N==1)
	{	//m[N-1][l] = l;
		return l;
	}
	if( l==0)
		return 0;
	if( m[N-1][l] >0)
		return m[N-1][l];

	int min_days = l+1;

	if( l>3)  //This is based on a modified binary search, it has been made using the property that x must have a minimum value. It basically vcompares it with next and prev value that is different from it. and if it is less that both the next and preve value different from it then it is the desired value. 
	{	int low = 1, high = l, val_curr, val_prev, val_next, x;
		while(low!=high)
		{
			x = (low + high) /2;
			int i=1;
			val_curr = maxim_( A(N,l-x,m), A(N-1,x-1,m) );
			val_prev = val_curr;
			val_next = val_curr;
			
			while(val_next== val_curr && ((x+i)<=l))
			{
				val_next = maxim_( A(N,l-(x+i),m), A(N-1,(x+i)-1,m) );		
				i++;
			}
			
			i=1;
			while(val_prev == val_curr && (x-i)>=1)
			{
				val_prev = maxim_( A(N,l-(x-i),m), A(N-1,(x-i)-1,m) );
				i++;				
			}

			if(val_curr <= val_prev && val_curr <= val_next)
			{	
				min_days = val_curr;
				break;
			}
			else if( val_curr <=val_next)
				high = x+1;
			else 
				low = x-1;
		
		}
	}
	else //Do brute-force for small values
	{

		for ( int x =1;x<=l;x++)
		{
			int curr_iter = maxim_( A(N,l-x,m), A(N-1,x-1,m) );
			if( min_days > curr_iter)
				min_days = curr_iter;
		}
	}
	m[N-1][l] = min_days + 1;

	return m[N-1][l];
}

int findMinimumDaysFaster(int N, int T)
{
	int **m;
	m = (int**)malloc(sizeof(int*)*(N));
	
	for(int i=0;i<N;i++)
		m[i] = (int *) malloc(sizeof(int) * (T+1));

	for(int i=0;i<N;i++)
		for(int j=0;j<=T;j++)
			m[i][j] = 0;


	int answer_ = A2(N,T,m);

	//cout<<answer_;

/*
	for(int i=0;i<N;i++)
	{	for(int j=0;j<=T;j++)
			cout<< m[i][j]<<" ";
		cout<<"\n";
	}
*/
	for(int i=0;i<N;i++)
		free(m[i]);
	free(m);
	
	return answer_;
}




int main()
{
	int n,t;
	cout<<"Write n:";
	cin>>n;
	cout<<"\nWrite t:";
	cin>>t;

	int answer1 = findMinimumDays(n,t);

	cout<<"\ng("<<n<<","<<t<<") = "<<answer1<<"\n\n";
	
	cout<<"Write n:";
	cin>>n;
	cout<<"\nWrite t:";
	cin>>t;

	int answer2 = findMinimumDaysFaster(n,t);

	cout<<"\ng("<<n<<","<<t<<") = "<<answer2<<"\n\n";

}
