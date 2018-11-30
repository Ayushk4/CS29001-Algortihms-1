#include <iostream>

using namespace std;


void insert_sort(int a[],int n)
{
	if(n==1)
		return;

	insert_sort(a,n-1);

	int k=a[n-1];
	int i=n-2;
	while (i>=0 && a[i]>k)
	{	a[i+1]=a[i];
		i--;
	}

	a[i+1]=k;

}


int main()
{
	int n;
	cout<<"enter the no ";
	cin>>n;

	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	insert_sort(a,n);
	
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
}
