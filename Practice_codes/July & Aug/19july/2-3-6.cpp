#include<iostream>

using namespace std;

int main()
{
	int n;
	cout<<"Enter the no: ";
	cin>>n;

	int a[n];
	
	for(int i=0;i<n;i++)
		cin>>a[i];

	int i,j;

	for(i=1;i<n;i++)
	{
		int k= a[i];
		j=i-1;
		
		while(j>=0 && a[j]>k)
		{
			a[j+1]=a[j];
			j--;
		}

		a[j+1]=k;
	}

	for (i=0;i<n;i++)
		cout<<a[i]<<" ";

}
