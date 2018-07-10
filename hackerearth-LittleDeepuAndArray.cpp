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
ll a[100005],tree[400005],lazy[400005];
void build(int node,int start,int end)
{
	if(start==end){
		tree[node]=a[start];
		return;
	}
	int mid=(start+end)/2;
	build(2*node,start,mid);
	build(2*node+1,mid+1,end);
	tree[node]=min(tree[2*node],tree[2*node+1]);
}
void update(int node,int start,int end,int l,int r,int x,int val)
{
	if(start>r || end<l)
		return;
	if(lazy[node])
	{
		tree[node]+=lazy[node];
		if(start!=end)
		{
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(tree[node]>x)
	{
		tree[node]+=val;
		if(start!=end)
		{
			lazy[2*node]+=val;
			lazy[2*node+1]+=val;
		}
		return;
	}
	if(start==end)return;
	int mid=(start+end)/2;
	update(2*node,start,mid,l,r,x,val);
	update(2*node+1,mid+1,end,l,r,x,val);
	tree[node]=min(tree[2*node],tree[2*node+1]);

}
ll query(int node,int start,int end,int l,int r)
{
	if(start>r || end<l)return INF;
	if(lazy[node])
	{
		tree[node]+=lazy[node];
		if(start!=end)
		{
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(start>=l && end<=r)
		return tree[node];
	int mid=(start+end)/2;
	return min(query(2*node,start,mid,l,r),query(2*node+1,mid+1,end,l,r));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	build(1,1,n);
	cin>>q;
	while(q--)
	{
		ll x;
		cin>>x;
		update(1,1,n,1,n,x,-1);
	}
	for(int i=1;i<=n;i++)
	{
		cout<<query(1,1,n,i,i)<<" ";
	}

	return 0;
}
