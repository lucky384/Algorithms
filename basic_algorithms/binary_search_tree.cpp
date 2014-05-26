//preorder,postorder,inorder traversal of bst and its height determination
#include<bits/stdc++.h>
using namespace std;
#pragma pack(1)
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
// creating bst using recursive algorithm implemented using linked list initially creating root node.
struct node *bst(struct node *p,int d)
{
    if(p==0)
    {
        p=(struct node *)malloc(sizeof (struct node));
        p->data=d;
        p->right=0;
        p->left=0;
            }
        else
        {
            if(d>(p->data))
                p->right=bst(p->right,d);
                else
                p->left=bst(p->left,d);
        }
        return p;
}
//inorder traversal
int inorder(struct node *p)
{
    if(p!=0)
    {
    inorder(p->left);
    cout<<p->data<<" ";
    inorder(p->right);
    }
}
// preorder traversal
int preorder(struct node *p)
{
    if(p!=0)
    {
        cout<<p->data<<" ";
        preorder(p->left);
        preorder(p->right);
    }
}
// postorder traversal
int postorder(struct node *p)
{
    if(p!=0)
    {
        postorder(p->left);
        postorder(p->right);
        cout<<p->data<<" ";
    }
}
// determining left height and right height,hence determining tree's height
int height(struct node *p)
{
    int lh=1,rh=1;
    if(p==0)
    return 0;
    else
    {
    lh=lh+height(p->left);
    rh=rh+height(p->right);
    }
    if(lh>rh)
        return lh;
     else
        return rh;
}
// driver function
main()
{
    struct node *r=0;
    register int n,i,k;
    cin>>n;
    register int x[n];
    for(i=0;i<n;i++)
    {
        cin>>x[i];
    }
    for(i=0;i<n;i++)
    {
        r=bst(r,x[i]);
    }
    inorder(r);
    cout<<endl;
    preorder(r);
    cout<<endl;
    postorder(r);
    k=height(r);
    cout<<endl<<k;
}


