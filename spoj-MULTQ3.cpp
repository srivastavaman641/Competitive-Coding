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
ll lazy[400005],tree[400005][3];
void build(int node,int start,int end)
{
	if(start==end)
	{
		tree[node][0]=1;
		tree[node][1]=tree[node][2]=0;
		return;
	}
	int mid=(start+end)/2;
	build(2*node,start,mid);
	build(2*node+1,mid+1,end);
	tree[node][1]=tree[node][2]=0;
	tree[node][0]=tree[2*node][0]+tree[2*node+1][0];
}
void update(int node,int start,int end,int l,int r)
{
	if(lazy[node])
	{
		if(start!=end)
		{
			lazy[2*node]=(lazy[2*node]+lazy[node])%3;
			lazy[2*node+1]=(lazy[2*node+1]+lazy[node])%3;
		}
		if(lazy[node]==2)
		{
			int temp=tree[node][0];
			tree[node][0]=tree[node][1];
			tree[node][1]=tree[node][2];
			tree[node][2]=temp;
		}
		else if(lazy[node]==1)
		{
			int temp=tree[node][0];
			tree[node][0]=tree[node][2];
			tree[node][2]=tree[node][1];
			tree[node][1]=temp;
		}
		lazy[node]=0;
	}
	if(start>r || end<l)return;
	if(start>=l && end<=r)
	{
		if(start!=end)
		{
			lazy[2*node]=(1+lazy[2*node])%3;
			lazy[2*node+1]=(1+lazy[2*node+1])%3;
		}
		int temp=tree[node][0];
		tree[node][0]=tree[node][2];
		tree[node][2]=tree[node][1];
		tree[node][1]=temp;
		return;
	}
	int mid=(start+end)/2;
	update(2*node,start,mid,l,r);
	update(2*node+1,mid+1,end,l,r);
	tree[node][0]=tree[2*node][0]+tree[2*node+1][0];
	tree[node][1]=tree[2*node][1]+tree[2*node+1][1];
	tree[node][2]=tree[2*node][2]+tree[2*node+1][2];
}
ll query(int node,int start,int end,int l,int r)
{
	if(lazy[node])
	{
		if(start!=end)
		{
			lazy[2*node]=(lazy[2*node]+lazy[node])%3;
			lazy[2*node+1]=(lazy[2*node+1]+lazy[node])%3;
		}
		if(lazy[node]==2)
		{
			int temp=tree[node][0];
			tree[node][0]=tree[node][1];
			tree[node][1]=tree[node][2];
			tree[node][2]=temp;
		}
		else if(lazy[node]==1)
		{
			int temp=tree[node][0];
			tree[node][0]=tree[node][2];
			tree[node][2]=tree[node][1];
			tree[node][1]=temp;
		}
		lazy[node]=0;
	}
	if(start>r || end<l)return 0;
	if(start>=l && end<=r)
		return tree[node][0];
	int mid=(start+end)/2;
	return query(2*node,start,mid,l,r)+query(2*node+1,mid+1,end,l,r);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q;
	cin>>n>>q;
	memset(lazy,0,sizeof lazy);
	memset(tree,0,sizeof tree);
	build(1,1,n);
	while(q--)
	{
		int o,x,y;
		cin>>o>>x>>y;
		x++;y++;
		if(o==0)
		{
			update(1,1,n,x,y);
		}
		else
			cout<<query(1,1,n,x,y)<<endl;
	}


	return 0;
}
