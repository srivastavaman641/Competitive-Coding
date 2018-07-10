#include<bits/stdc++.h>
#define ll long long int
#define s(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define w(t) while(t--)
#define f(i,n) for(int i=0;i<n;i++)
#define fd(i,n) for(int i=n-1;i>=0;i--)
#define p(a) printf("%d",a)
#define pl(a) printf("%lld",a)
#define ps(a) printf("%s",a)
#define pc(a) printf("%c",a)
#define ent printf("\n")
#define mod 1000000007
#define PI 3.14159265
#define gs getline(cin,s)
#define pb push_back
#define mp make_pair
#define INF 1e18
#define pii pair<int,int>

using namespace std;
int a[100005],tree[300005];
void build(int node,int start,int end)
{
	if(start==end)
	{
		tree[node]=a[start];
		return;
	}
	int mid=(start+end)/2;
	build(2*node,start,mid);
	build(2*node+1,mid+1,end);
	tree[node]=min(tree[2*node],tree[2*node+1]);
}
void update(int node,int start,int end,int idx,int val)
{
	if(start==end)
	{
		a[idx]=val;
		tree[node]=val;
		return;
	}
	int mid=(start+end)/2;
	if(start<=idx && idx<=mid)
		update(2*node,start,mid,idx,val);
	else
		update(2*node+1,mid+1,end,idx,val);
	tree[node]=min(tree[2*node],tree[2*node+1]);
}
int query(int node,int start,int end,int l,int r)
{
	if(end<l || start>r)
		return INT_MAX;
	if(start>=l && end<=r)
		return tree[node];
	int mid=(start+end)/2;
	int ans=min(query(2*node,start,mid,l,r),query(2*node+1,mid+1,end,l,r));
	return ans;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n,q;
   cin>>n>>q;
   for(int i=1;i<=n;i++)
   		cin>>a[i];
   build(1,1,n);
   while(q--)
   {
   		char c;
   		int x,y;
   		cin>>c>>x>>y;
   		if(c=='q')
   		{
   			cout<<query(1,1,n,x,y)<<endl;
   		}
   		else
   		{
   			update(1,1,n,x,y);
   		}
   }
   return 0;
}
	