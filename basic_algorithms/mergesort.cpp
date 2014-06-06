#include<bits/stdc++.h>
using namespace std;
int merge1(int *,int,int,int);
int merge_sort(int a[],int low,int up)
{
    int m;
    if(low<up)
    {
        m=(low+up)/2;
        merge_sort(a,low,m);
        merge_sort(a,m+1,up);
        merge1(a,low,m,up);
    }
}
int merge1(int x[],int low,int m,int up)
{
    int i=low,j=m+1,k=low;
    int z[(up+1)];
    while(i<=m && j<=up)
    {
        if(x[i]<x[j])
        {
            z[k]=x[i];
            k++;
            i++;
        }
        else
        {
            z[k]=x[j];
            k++;
            j++;
        }
    }
    while(i<=m)
    {
        z[k]=x[i];
        k++;
        i++;
    }
    while(j<=up)
    {
        z[k]=x[j];
        k++;
        j++;
    }
    for(i=low;i<=up;i++)
    {
        x[i]=z[i];
    }
}
main()
{
    register int n,i;
    cin>>n;
    register int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    merge_sort(a,0,(n-1));
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
