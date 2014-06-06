#include<bits/stdc++.h>
using namespace std;
#pragma pack(1)
struct Node
{
    int data;
    Node *ad;
};
main()
{
    register int n,i,j;
    cin>>n;
    register int ad[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>ad[i][j];
        }
    }
    register int s;
    Node *p,*q;
    register int input[n];
    register int output[n];
    j=0;
    register int k=0,m,l,f=0;
    cout<<"enter source :";
    cin>>s;
    p=new Node;
    p->data=s;
    p->ad=0;
    input[j]=s;
    j++;
    while(p!=0)
    {
        s=p->data;
        output[k]=s;
        k++;
        p=p->ad;
        for(m=0;m<n;m++)
        {
            if(ad[s][m]==1)
            {
                for(l=0;l<j;l++)
                {
                    if(m==input[l])
                    {
                        f=1;
                        break;
                    }
                }
                if(f==0)
                {
                    input[j]=m;
                    j++;
                    if(p==0)
                    {
                        p=new Node;
                        p->data=m;
                        p->ad=0;
                    }
                    else{
                        q=new Node;
                        q->ad=p;
                        p=q;
                        p->data=m;
                    }
                }
            }
            f=0;
        }
    }
    for(i=0;i<k;i++)
        cout<<output[i]<<" ";
}
