#include <iostream>

using namespace std;

int main()
{
	int n;
	cout<<"Enter the no of dates: ";
	cin>>n;

	cout<<"Fun for each day = ";
	int a[n];
	int alltimemax,currentmax;
	for(int i = 0;i<n;i++)
		cin>>a[i];

	alltimemax = 0;
	currentmax = 0;
	int this_i = 0, overall_i, overall_j = 0;

	for(int k = 0;k<n;k++)
	{
		currentmax = currentmax + a[k];

		if(currentmax>alltimemax)
		{
			alltimemax = currentmax;
			overall_i = this_i;
			overall_j = k;
			//cout<<alltimemax<<" ";
		}
		
		if(currentmax <0)
		{	this_i = 0;
			currentmax = 0;
		}

		
	}
	
	cout<<"\ni = "<<overall_i+1;
	cout<<"\nj = "<<overall_j+1<<"\n";

}
	
