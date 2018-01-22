#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
    int low,high,sum;
}node;
node cross_subarr(int a[],int l,int mid,int h)
{
    node n;
    int i,leftsum=-10000,rightsum=-10000,sum=0,x,y;
    for(i=mid;i>=l;i--)
    {
        sum+=a[i];
        if(sum>leftsum)
        {
            leftsum=sum;
            x=i;
        }
    }
    sum=0;
    for(i=mid+1;i<=h;i++)
    {
        sum+=a[i];
        if(sum>rightsum)
        {
            rightsum=sum;
            y=i;
        }
    }
    n.low=x,n.high=y,n.sum=leftsum+rightsum;
    return n;
}
node maximumsubarr(int a[],int l,int h)
{
    if(l==h)
        {
            node n;
            n.low=l;
            n.high=h;
            n.sum=a[l];
            return n;
        }
    else
    {
        node left,right,cross;
        int mid=(l+h)/2;
        left=maximumsubarr(a,l,mid);
        right=maximumsubarr(a,mid+1,h);
        cross=cross_subarr(a,l,mid,h);
        cout<<left.sum<<' ';
        cout<<right.sum<<' ';
        cout<<cross.sum<<'\n';
        if(left.sum>=cross.sum&&left.sum>=right.sum)
            return left;
        else if(right.sum>=cross.sum&&right.sum>=left.sum)
            return right;
        else return cross;
    }
    //return 0;
}
int main()
{
    int n;
    cin>>n;
    int a[n],i;
    for(i=1;i<=n;i++)
    cin>>a[i];
    node ans=maximumsubarr(a,1,n);
    cout<<ans.low<<' '<<ans.high<<' '<<ans.sum;
    return 0;
}
