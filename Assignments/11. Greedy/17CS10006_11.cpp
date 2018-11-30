//Ayush Kaushal
//17CS10006

#include<iostream>
#include<stdlib.h>

using namespace std;


typedef struct {
	int subpartID;
	int cost_per_day;
	int duration;
}subpart_data;

typedef struct {
	int predecessorID;
	int successorID;
}dependency_info;

typedef struct {
	int pred, succ;
	int index;
} make_chain;


void sortedmerge(subpart_data * parts, int low, int mid, int high)
{
	int i = low, j = mid, k = 0;
	
	subpart_data * tmp = (subpart_data *) malloc( sizeof(subpart_data) * (high - low +1));
	
	while ( i< mid && j < high)
	{
		if (parts[i].cost_per_day > parts[j].cost_per_day)
		{
			tmp[k] = parts[i];
			k++;
			i++;
		}
		else
		{
			tmp[k] = parts[j];
			k++;
			j++;
		}
	}

	while( i<mid)
	{
		tmp[k] = parts[i];
		k++;
		i++;
	}
	while( j<high)
	{
		tmp[k] = parts[j];
		k++;
		j++;
	}


	for(i=0;i<k;i++)
		parts[low + i] = tmp [i];
}

void merge__sort(subpart_data * parts, int low, int high)
{
	if( (high - low) <=1)
		return;
	
	int mid = (high +low )/2;
	
	merge__sort(parts,low,mid);
	merge__sort(parts,mid,high);
	
	sortedmerge(parts, low, mid, high);
	
}

void print_schedule(subpart_data *A, int k)
{
	merge__sort(A,0,k);

	subpart_data *parts = A;
/*	for(int i=0;i<k;i++)
	{
		cout<<parts[i].subpartID<<" "<<parts[i].cost_per_day<<" ";
		cout<<parts[i].duration<<"\n";
	}
*/

	int time = 0, cost =0;
	
	for(int i = 0;i<k;i++)
	{
		time += parts[i].duration;
		cost += time * parts[i].cost_per_day;
	}
	
	cout<<"cost="<<cost<<"\n";

}

//////////////////////sub part ids start form 1








/*

void print_schedule1(subpart_data *a, int k, dependency_info *b, int l)
{
	
	//subpart_data * make_chain = (subpart_data *) malloc (sizeof(subpart_data) * k);
	make_chain * new_data = (make_chain *) malloc (sizeof(make_chain) * k);
	for (int i=0;i<k;i++)
	{	new_data[i].index = i;
		new_data[i].pred = -1;
		new_data[i].succ = -1;
	}
	for (int i=0;i<l;i++)
	{
		new_data[b[i].predecessorID].succ = b[i].successorID;
		new_data[b[i].successorID].pred = b[i].predecessorID;
	}
	make_chain **chains = (make_chain **) malloc(sizeof(make_chain) *k);
	int no_chains = 0;
	for(int i=0;i<k;i++)
		if( new_data[i].pred == -1)
		{
			chains[no_chains] = &new_data[i];
			no_chains ++;
		}

	int chain_c_day[no_chains];
	int chain_upto[no_chains];

for(int i=0;i<k;i++)
{	cout<<new_data[i].index<<" "<<new_data[i].pred<<" "<<new_data[i].succ<<"\n";
}for(int i=0;i<no_chains;i++)
{
	cout<<chains[i]->index<<" "<<new_data[chains[i]->succ].index<<" ||";
}

	for(int i=0;i<no_chains;i++)
	{
		make_chain *ptr = chains[i];
		int cost=0; int duration=0;
		chain_c_day[i] = 0;
		int iter =0;
		do{
			iter++;
			duration += a[ptr->index].duration;
			cout<<ptr->index<<"a ";
			cost += a[ptr->index].cost_per_day *a[ptr->index].duration;
			if( cost/duration > chain_c_day[i])
			{
				chain_c_day[i] = cost/duration;
				chain_upto[i] = iter; 
			}
			ptr = &new_data[ptr->succ];
		}while(ptr->succ != -1);
		cout<<chain_c_day[i]<<" "<<chain_upto[i]<<"\n";

	}
	
	
	
	//for(int i=0;i<no_chains;i++)
	
	subpart_data sorted[k];
	
	for(int i=0;i<k;i++)
	{
		
	}
}

*/
	
	

int main()
{
	int k; //Number of sub parts
	cin>>k;

	subpart_data * parts = (subpart_data * ) malloc(sizeof(subpart_data)*k);

	for(int i=0;i<k;i++)
	{	parts[i].subpartID = i+1;
		cin>>parts[i].duration;
	}
	for(int i=0;i<k;i++)
		cin>>parts[i].cost_per_day;

	print_schedule(parts,k);


	int l;
	cin>>l;

	dependency_info * part_pairs = (dependency_info *) malloc( sizeof(dependency_info) * l);

	for(int i=0;i<l;i++)
	{
		int pred,succ;
		cin>>pred >>succ;
		part_pairs[i].predecessorID = pred -1;
		part_pairs[i].successorID = succ -1;
		//cout<<part_pairs[i].successorID<<" ";
	}	

	//print_schedule1(parts,k,part_pairs,l);
	free(part_pairs);
	free(parts);
}
