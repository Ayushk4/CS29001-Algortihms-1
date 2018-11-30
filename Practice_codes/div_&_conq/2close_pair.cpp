#include<iostream>
#include<math.h>

using namespace std;

struct pt{
    int x, y;
};

int dist(pt p1, pt p2)
{
    return ( (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y) );
}

int minim(int x,int y)
{
    if(x>y)
        return y;
    return x;
}

int brute(pt p[], int l, int h)
{
    if( (h-l) <2)
        return 10000;

    int min_dist = dist(p[l],p[l+1]);

    for(int i=l;i<h;i++)
        for(int j=i+1;j<h;j++)
            if( dist(p[i],p[j]) < min_dist ) 
                min_dist =  dist(p[i],p[j]);

    return min_dist;
}

int border_min(pt p[], int l, int h, int minimm)
{
    pt strip[h-l+1];

    int j = 0;
    for (int i = l; i < h; i++)
        if ( ( (p[i].x - p[(h+l)/2].x)  *  (p[i].x - p[(h+l)/2].x) ) < minimm)
        {   strip[j] = p[i];
            j++;
        }
    
    for(int i=0;i<j;i++)
        for(int k=i+1;k<j;k++)
            if( dist(strip[i], strip[k]) < minimm )
                minimm =  dist(strip[i], strip[k]);

    return minimm;
}

int closest_dist(pt p[], int l, int h)
{
    if( (h-l) <=3)
        return brute(p,l,h);

    int min_dist, lmin, rmin, mid = (l+h)/2 ;
    
    lmin = (p,l,mid);
    rmin = (p,mid,h);
    min_dist = minim(lmin,rmin);

    min_dist = minim( min_dist, border_min(p,l,h,min_dist));

    return min_dist;
}





void swap(pt *p1, pt * p2)
{
    pt tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}
int prtn(pt p[],int l, int h)
{
    int i=l,j=h,piv =l;

    while(i<j)
    {
        while(p[i].x <= p[piv].x &&  i<h) 
            i++;
        while(p[j].x > p[piv].x) 
            j--;
        
        if(i<j)
        {
            swap(&p[i],&p[j]);
            j--;
        }
    }

    swap(&p[piv],&p[j]);
    return j;
}
void quick_sort(pt p[],int l, int h)
{
    if((h-l)<=1)
        return;
    
    int parti = prtn(p, l, h);

    quick_sort(p,l,parti);
    quick_sort(p,parti+1,h);
}

int main()
{
    int n,i;
    cin>>n;

    pt* p;
    p = (pt*)malloc(sizeof(pt)*n);
    for(i=0;i<n;i++)
        cin>>p[i].x>>p[i].y;
    quick_sort(p,0,n);

    cout<<"\n";
    for(i=0;i<n;i++)
        cout<<p[i].x<<" "<< p[i].y<<"\n";
    
    cout<<closest_dist(p,0,n);
    cout<<"\n";

}

//input

//sort acc x
//base case min
//min l, min r
//min l-r
