#include<bits/stdc++.h>
using namespace std;
main()
{
    string s1,s2;
    cin>>s1>>s2;
    char a[s1.size()];
    register int mid,i,k;
    k=s1.size();
    for(i=0;i<k;i++)
        a[i]=s1[i];
    sort(a,a+k);
        for(i=0;i<s2.size();i++)
    {
        int low=0;
        int high=(k-1);
        while(low<=high)
        {
            mid=(low+high)/2;
            if(a[mid]==s2[i])
            {
            cout<<s2[i]<<" ";
            break;
            }
            else if(a[mid]<s2[i])
                low=mid+1;
            else high=mid-1;
        }
    }
}
