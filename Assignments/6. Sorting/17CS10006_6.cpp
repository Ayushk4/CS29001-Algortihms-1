//Ayush Kaushal
//17CS10006

#include<iostream>
#include<stdlib.h>

using namespace std;

void combine(int A[], int left, int middle, int right)
{

	int i = 0, curr1 = left, curr2 = middle ;
	

	int *b = (int *) malloc ( (right - left) * sizeof(int));
	
	i =0;
	while ( (curr1 < middle) && (curr2 < right ))
	{
		
		if( A[curr1] < A[curr2] )
		{	b[i] = A[curr1];
			curr1++;
		}
		else
		{	b[i] = A[curr2];
			curr2++;
		}
		i++;
	}
	
	while( curr1 < middle)
	{
		b[i] = A[curr1++];
		i++;
	}
	
	while( curr2 <right )
	{
		b[i] = A[curr2++];
		i++;
	}
	
	for(i=left;i<right ;i++)
		A[i] = b[i-left];	
	//freeing the memory
	free (b);
}

void superbSorting(int A[], int sizeOfA)
{
	int twopower = 0 ,n =sizeOfA ;
	while(sizeOfA>0)
	{
		sizeOfA /=2;
		twopower++;
	}
	//n is size of A;
	
	int i, pair_factor = 1;
	
	
	for( i=0;i<twopower;i++)
	{
		int low = 0, mid = pair_factor , high = 2 * pair_factor;
		
		while(mid< n)
		{
			combine(A,low, mid, high);
			//Updating the loop
			low = low + 2 * pair_factor;
			mid = mid + 2 * pair_factor;
			high = high + 2* pair_factor;
			if( high >n) high =n;
			
		
		}
		pair_factor *= 2;
	}
}




int compare1(int X[], int sizeOfX, int x, int y)
{
	int i=-1,j=-1;
	
	for( int k=0; k<sizeOfX;k++)
	{	
		if( X[k] ==x)
			i = k;
		
		else if( X[k] ==y)
			j = k;

		if( i!=-1 && j!=-1)
			break;
	}
	
	if( i<j)
		return 1;
	else
		return -1;
}
void combine1(int A[], int left, int middle, int right, int B[], int sizeOfB)
{

	int i = 0, curr1 = left, curr2 = middle ;
	

	int *temp = (int *) malloc ( (right - left) * sizeof(int));
	
	i =0;
	while ( (curr1 < middle) && (curr2 < right ))
	{
		
		if( compare1 (B, sizeOfB, A[curr1], A[curr2]) == 1 )
		{	temp[i] = A[curr1];
			curr1++;
		}
		else
		{	temp[i] = A[curr2];
			curr2++;
		}
		i++;
	}
	
	while( curr1 < middle)
	{
		temp[i] = A[curr1++];
		i++;
	}
	
	while( curr2 <right )
	{
		temp[i] = A[curr2++];
		i++;
	}

	for(i=left;i<right ;i++)
	{	
		A[i] = temp[i-left];	
	}
	//freeing the memory
	free (temp);
}
void superbSorting1(int A[], int sizeOfA, int B[], int sizeOfB)
{
	int twopower = 0 ,n =sizeOfA ;
	while(sizeOfA>0)
	{
		sizeOfA /=2;
		twopower++;
	}
	//n is size of A;
	
	int i, pair_factor = 1;
	
	
	for( i=0;i<twopower;i++)
	{
		int low = 0, mid = pair_factor , high = 2 * pair_factor;
		
		while(mid< n)
		{
			combine1(A,low, mid, high, B, sizeOfB);
			//Updating the loop
			low = low + 2 * pair_factor;
			mid = mid + 2 * pair_factor;
			high = high + 2* pair_factor;
			if( high >n) high =n;
			
		
		}
		pair_factor *= 2;
	}
}


int compare2(int x, int y, int H[])
{
	int i = H[x],j = H[y];
		
	if( i<j)
		return 1;
	else
		return -1;
}
void combine2(int A[], int left, int middle, int right, int H[])
{

	int i = 0, curr1 = left, curr2 = middle ;
	

	int *temp = (int *) malloc ( (right - left) * sizeof(int));
	
	i =0;
	while ( (curr1 < middle) && (curr2 < right ))
	{
		
		if( compare2 (A[curr1], A[curr2], H) == 1 )
		{	temp[i] = A[curr1];
			curr1++;
		}
		else
		{	temp[i] = A[curr2];
			curr2++;
		}
		i++;
	}
	
	while( curr1 < middle)
	{
		temp[i] = A[curr1++];
		i++;
	}
	
	while( curr2 <right )
	{
		temp[i] = A[curr2++];
		i++;
	}

	for(i=left;i<right ;i++)
	{	
		A[i] = temp[i-left];	
	}
	//freeing the memory
	free (temp);
}
void superbSorting2(int A[], int sizeOfA,  int H[])
{
	int twopower = 0 ,n =sizeOfA ;
	while(sizeOfA>0)
	{
		sizeOfA /=2;
		twopower++;
	}
	//n is size of A;
	
	int i, pair_factor = 1;
	
	
	for( i=0;i<twopower;i++)
	{
		int low = 0, mid = pair_factor , high = 2 * pair_factor;
		
		while(mid< n)
		{
			combine2(A,low, mid, high, H);
			//Updating the loop
			low = low + 2 * pair_factor;
			mid = mid + 2 * pair_factor;
			high = high + 2* pair_factor;
			if( high >n) high =n;
			
		
		}
		pair_factor *= 2;
	}
}
void hashfn(int B[], int n2, int H[], int h_n)
{

	for(int i=0;i<n2;i++)
	{	H[B[i]] = i+1;
		
	}
	
	
}

int main()
{
	int n,i;
	cout<<"Enter numbers of number in an array a: ";
	cin>>n;
	int *a = (int * ) malloc(n * sizeof(int));
	
	for(i=0;i<n;i++)
		cin>>a[i];
	
	superbSorting (a, n);
	cout<<"\nArray A sorted in non descending order: ";
	for(int j =0;j < n;j++)
		cout<< a[j] <<" ";
	cout<<"\n";
	//free(a)	
	
	
		
	//cin>>n;
	//a = (int * ) malloc(n * sizeof(int));
	
	for(i=0;i<n;i++)
		cin>>a[i];
	
	int n2;
	cout<<"Enter number of numbers in the array B: ";
	cin>>n2;
	
	int *B = (int * ) malloc(n2* sizeof(int));
	for( i=0;i<n2;i++)
		cin>>B[i];
	
	superbSorting1 (a, n, B, n2);
	
	cout<<"\nArray A after rearranging:";
	for(int j =0;j < n;j++)
		cout<< a[j] <<" ";
	cout<<"\n";
	free(B);





	cout<<"Enter number in an array a: ";
	for(i=0;i<n;i++)
		cin>>a[i];
	cout<<"Enter number of numbers in the array B: ";
	cin>>n2;

	B = (int * ) malloc(n2* sizeof(int));
	for( i=0;i<n2;i++)
		cin>>B[i];

	int *H = (int*)malloc(sizeof(int) *10 *n);
	hashfn(B,n2,H,10*n);

	//for(int k =0;k<n2;k++)
	//	cout<<B[k]<<" ";
	superbSorting2 (a, n, H);

	cout<<"\nArray A after rearranging:";
	for(int j =0;j < n;j++)
		cout<< a[j] <<" ";
	cout<<"\n";
	//free(B);


}
