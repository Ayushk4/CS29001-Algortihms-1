//Ayush Kaushal
//17CS10006

#include<iostream>
#include<stdlib.h>
using namespace std;

#define MAX_SIZE 100 
typedef struct _job { 
	int jobid; 
	int starttime; 
	int joblength;
	int remlength; 
} job;

typedef struct _heap { 
	job list[MAX_SIZE]; 
	int numjobs; 
} heap;

void initHeap(heap *H)
{
	H->numjobs = 1;	
}

void sift_up(heap *H,int i)
{
	int big_valindex = i;
/////////////////////////////////////////////////////////////////
	if( (i>1) && (H->list[i/2].remlength >H->list[i].remlength)) 
		big_valindex = i/2;
	
	if (big_valindex == i)
	{	if(i>1)
		{	if(H->list[i/2].remlength == H->list[i].remlength)
				if( H->list[i/2].jobid > H->list[i].jobid)
					big_valindex = i/2;
		
		}
	}

	if (big_valindex == i)
			return;
	job tmp = H->list[i];
	H->list[i] = H->list[big_valindex];
	H->list[big_valindex]  = tmp;
	
	sift_up(H,big_valindex);
}

void insertJob(heap *H, job j)
{
	H->list[H->numjobs] = j;
	H->list[H->numjobs].remlength = H->list[H->numjobs].joblength;
	
	sift_up(H,H->numjobs);
	H->numjobs++;
}

void sift_down(heap *H,int i)
{
	int small_ind = i;
	int n =H->numjobs;

	if( (2*i <n) &&( (H->list[2*i].remlength<H->list[small_ind].remlength)|| ( (H->list[2*i].remlength==H->list[small_ind].remlength) && (H->list[2*i].jobid < H->list[small_ind].jobid))))
		small_ind = 2*i;
	if( (2*i+1 <n) &&( (H->list[2*i+1].remlength < H->list[small_ind].remlength)|| ( (H->list[2*i+1].remlength==H->list[small_ind].remlength) && (H->list[2*i+1].jobid < H->list[small_ind].jobid))))
		small_ind = 2*i+1;
	
	if(small_ind == i)
		return;

	job tmp = H->list[i];
	H->list[i] = H->list[small_ind];
	H->list[small_ind]  = tmp;
	
	sift_down(H,small_ind);

}

int extractMinJob(heap *H, job *j)
{
	if(H->numjobs <1)
	{	
		return -1;
	}
	*j = H->list[1];
	
	H->list[1] = H->list[H->numjobs-1];
	H->numjobs--;
	
	sift_down(H,1);
	
	return 0;
}

void mergearr(job a[], int l, int mid, int h)
{
	int i = l, j = mid, p =0;
	job tmp[h-l+1];
	while( (i < mid) && (j < h))
	{
		if( a[i].starttime < a[j].starttime)
		{	tmp[p] = a[i];
			i++;
		}

		else
		{	tmp[p] = a[j];
			j++;
		}
		p++;
	} 
	while( i<mid)
	{
		tmp[p] = a[i];
		p++;
		i++;
	}
	while( j<h)
	{
		tmp[p] = a[j];
		p++;
		j++;
	}
	for(int i =0 ;i<p;i++)
		a[i+l] = tmp[i];
}
void sortarr(job a[],int l, int h)
{
	if( (h-l)<=1)
		return;
	
	int mid = l+h;
	mid= mid/2;
	
	sortarr(a,l,mid);
	sortarr(a,mid,h);

	mergearr(a,l,mid,h);
}

void scheduler(job jobList[], int n) 
{
	heap *h;
	h = (heap*)malloc(sizeof(heap));
	initHeap(h);

	int jobindex=0, maxtime = jobList[n-1].starttime, time =0, turnaround = 0;
	job j;
	cout<<"Jobs schedules at each timestep are: \n";

	
	while(time<=maxtime)
	{
		while(jobList[jobindex].starttime == time)
		{
			insertJob(h,jobList[jobindex]);
			jobindex++;
		}

		if( h->numjobs== 1)
			cout<<" 0 ";
		else
		{
			while(h->numjobs>1 && h->list[1].remlength == 0)
				extractMinJob(h,&j);
			
			if(h->list[1].remlength == h->list[1].joblength)
				turnaround += time - h->list[1].starttime;
			
			cout<<" "<<h->list[1].jobid<<" ";
			h->list[1].remlength = h->list[1].remlength-1;
			
			while(h->numjobs>1 && h->list[1].remlength == 0)
				extractMinJob(h,&j);
		}
		time++;
	}
	
	while(h->numjobs>1)
	{
		while(h->numjobs>1 && h->list[1].remlength == 0)
			extractMinJob(h,&j);
		
		if(h->list[1].remlength == h->list[1].joblength)
			turnaround += time - h->list[1].starttime;
			
		cout<<" "<<h->list[1].jobid<<" ";
		h->list[1].remlength = h->list[1].remlength-1;
			
		while(h->numjobs>1 && h->list[1].remlength == 0 )
			extractMinJob(h,&j);

		time++;
	}
	
	double turnaround_avg = float(turnaround)/float(n);
	cout<<"\nAverage Turnaroung Time is : "<<turnaround_avg<<"\n";
	free(h);
}




int main()
{
	cout<<"Enter the number of jobs: \n";
	int n;
	cin>>n;
	
	cout<<"Enter the jobs: \n";
	job *arr;
	arr= (job *)malloc(n* sizeof(job));
	for(int i=0;i<n;i++)
	{	cin>>arr[i].jobid>>arr[i].starttime>>arr[i].joblength;
		arr[i].remlength = arr[i].joblength;
	}
	sortarr(arr,0,n);
	
	scheduler(arr,n);
	free(arr);
}
/*
	job j;
	
	cout<<"\n\n\n\n";
	for(int jj=0;jj<n;jj++)
	{		
		 cout<<extractMinJob(h,&j)<<" ::: \n";

		cout<<j.jobid<<" "<<j.starttime<<" "<<j.joblength<<" "<<j.remlength;

	cout<<"\n";
	}	




	for(int i=0;i<n;i++)
	{
		cout<<"\n"<<arr[i].jobid<<" "<<arr[i].starttime<<" "<<arr[i].joblength;
	}
	sortarr(arr,n);



void sortarr(job arr[],int n)
{
	int i,j;
	for(int i=0;i<n;i++)
	{
		int min = i;
		for(int j=i;j<n;j++)
			if( arr[min].starttime>arr[j].starttime)
				min = j;

		job tmp = arr[i];
		arr[i] = arr[min];
		arr[min] = tmp;
	}
}
*/
//If  there  are  two  jobs  with  the  same  remLength  value,  the  one  with  the  lower  job  id  is  to  be  chosen. 
