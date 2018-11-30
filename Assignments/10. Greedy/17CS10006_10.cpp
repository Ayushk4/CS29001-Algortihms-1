//Ayush Kaushal
//17CS10006

#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct _rwd {
	int start_time;
	int service_time;
} reqWD, reqwd;

struct reqdata_w{
	reqwd data;
	int id;
};

typedef struct _rsd {
	int service_time;
	int target_time;
} reqSD,redsd;

struct reqdata_sd{
	reqSD data;
	int id;
};

void sorted_merge(reqdata_w jobs[],int low, int mid ,int high)
{
	int i=low, j= mid, k =0;
	reqdata_w *tmp= (reqdata_w*)malloc(sizeof(reqdata_w)*(high-low+1));
	
	while(i<mid && j<high)
	{
		if( jobs[i].data.start_time<jobs[j].data.start_time) 
			tmp[k++] = jobs[i++];
		else
			tmp[k++] = jobs[j++];	
	}
	while(i<mid)
	{
		tmp[k++] = jobs[i++];
	}
	while(j<high)
	{
		tmp[k++] = jobs[j++];
	}
	
	for(i=0;i<k;i++)
		jobs[low+i] = tmp[i];
	
	free(tmp);
}

void sort_merge(reqdata_w jobs[],int low,int high)
{
	if((high-low)<=1)
		return;

	int mid = (low+high)/2;

	sort_merge(jobs,low,mid);
	sort_merge(jobs,mid,high);

	sorted_merge(jobs,low,mid,high);
}

void schedule1(reqdata_w jobs[], int n)//The following algo goes for assigning jobs so the a counter stays busy for maximum time, and then counter next with the remaining jobs and so on, so that minimum number of counters are required.
{
	int *flag = (int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
		flag[i] = 1;
	
	sort_merge(jobs,0,n);//sort by start time...
/*
	for(int i=0;i<n;i++)
	{
		cout<<jobs[i].id<<" "<<jobs[i].data.start_time<<" ";
		cout<<jobs[i].data.start_time + jobs[i].data.service_time<<"\n";
	}
*/
	int jobcount=1, counter=0;
	while(jobcount>0)
	{
		jobcount = 0;
		int timee = 0;
		for(int i=0;i<n;i++)
			if(flag[i]==1)
				if(jobs[i].data.start_time>=timee)
				{
					jobcount++;
					break;
				}
			
		
		if(jobcount>0)
		{
			jobcount =0;
			cout<<"\nCounter "<<counter;
			for(int i=0;i<n;i++)
				if(flag[i]==1)
					if(jobs[i].data.start_time>=timee)
					{
						timee=jobs[i].data.start_time+jobs[i].data.service_time;
						cout<<"\n"<<jobs[i].id<<" "<<jobs[i].data.start_time<<" "<<jobs[i].data.start_time+jobs[i].data.service_time;
						jobcount++;
						flag[i]=0;
					}
		}
		counter++;
	}
	cout<<"\n";
	free(flag);
}


void sorted_merge_sd(reqdata_sd jobs[],int low, int mid ,int high)
{
	int i=low, j= mid, k =0;
	reqdata_sd *tmp= (reqdata_sd*)malloc(sizeof(reqdata_sd)*(high-low+1));
	
	while(i<mid && j<high)
	{
		if( jobs[i].data.target_time<jobs[j].data.target_time) 
			tmp[k++] = jobs[i++];
		else
			tmp[k++] = jobs[j++];	
	}
	while(i<mid)
	{
		tmp[k++] = jobs[i++];
	}
	while(j<high)
	{
		tmp[k++] = jobs[j++];
	}
	
	for(i=0;i<k;i++)
		jobs[low+i] = tmp[i];
	
	free(tmp);
}

void sort_merge_sd(reqdata_sd jobs[],int low,int high)
{
	if((high-low)<=1)
		return;

	int mid = (low+high)/2;

	sort_merge_sd(jobs,low,mid);
	sort_merge_sd(jobs,mid,high);

	sorted_merge_sd(jobs,low,mid,high);
}



void schedule2(reqdata_sd jobs[], int n)
{
	int *flag = (int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
		flag[i] = 1;

	sort_merge_sd(jobs,0,n);//sort by dead line...

/*	for(int i=0;i<n;i++)
	{
		cout<<jobs[i].id<<" "<<jobs[i].data.service_time<<" "<<jobs[i].data.target_time<<"\n";
	}
*/
	int time=0;
	for(int i=0;i<n;i++)
	{
		cout<<jobs[i].id<<" "<<time<<" "<<time+jobs[i].data.service_time<<"\n";
		time+=jobs[i].data.service_time;

	}

	cout<<"\n";
	free(flag);
}

int main()
{
	int n;
	cout<<"Enter the number of requests over weekday:";
	cin>>n;

	cout<<"\nEnter the start time and length for each of the requests:";

	reqdata_w *jobs_w = (reqdata_w*) malloc(sizeof(reqdata_w)*n); 
	for(int i=0;i<n;i++)
	{	
		cout<<"\nRequest "<<i<<"::";
		cin>>jobs_w[i].data.start_time>>jobs_w[i].data.service_time;
		jobs_w[i].id=i;
	}
	cout<<"\n\n";
	schedule1(jobs_w,n);

	free(jobs_w);


	cout<<"\n\n\nEnter the number of requests over Saturday:";
	cin>>n;

	cout<<"\nEnter the length and the deadline for each of the requests:";

	reqdata_sd *jobs = (reqdata_sd*) malloc(sizeof(reqdata_sd)*n); 
	for(int i=0;i<n;i++)
	{	
		cout<<"\nRequest "<<i<<"::";
		cin>>jobs[i].data.service_time>>jobs[i].data.target_time;
		jobs[i].id=i;
	}
	cout<<"\n\n";
	schedule2(jobs,n);

	free(jobs);
}
