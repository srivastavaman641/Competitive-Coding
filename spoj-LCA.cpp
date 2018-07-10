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
int tree[16005],euler[4005],first[1005],level[4005];
vector<int>v[1005];
int idx=1;
void build(int node,int start,int end)
{
	if(start==end)
	{
		tree[node]=start;
		return;
	}
	int mid=(start+end)/2;
	build(2*node,start,mid);
	build(2*node+1,mid+1,end);
	if(level[tree[2*node]]<level[tree[2*node+1]])
		tree[node]=tree[2*node];
	else
		tree[node]=tree[2*node+1];
}
int query(int node,int start,int end,int l,int r)
{
	if(start>r || end<l)
		return INT_MAX;
	if(start>=l && end<=r)
		return tree[node];
	int mid=(start+end)/2;
	int l1=query(2*node,start,mid,l,r);
	int l2=query(2*node+1,mid+1,end,l,r);
	if(l1==INT_MAX)
		return l2;
	else if(l2==INT_MAX)
		return l1;
	else if(level[l1]>level[l2])
		return l2;
	else 
		return l1;
}
void dfs(int x,int lvl)
{
	level[idx]=lvl;
	if(first[x]==-1)
		first[x]=idx;
	euler[idx]=x;
	idx++;
	for(int i=0;i<v[x].size();i++)
	{
		dfs(v[x][i],lvl+1);
		euler[idx]=x;
		level[idx]=lvl;
		idx++;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	for(int p=1;p<=t;p++)
	{
		int n;
		cin>>n;
		memset(tree,0,sizeof tree);
		memset(first,-1,sizeof first);
		for(int i=0;i<=n;i++)
			v[i].clear();
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			for(int j=0;j<x;j++){
				int k;
				cin>>k;
				v[i].pb(k);
			}
		}
		idx=1;
		dfs(1,0);
		build(1,1,idx-1);
		int q;
		cin>>q;
		cout<<"Case "<<p<<":"<<endl;
		while(q--)
		{
			int x,y;
			cin>>x>>y;
			int l=first[x];
			int r=first[y];
			cout<<euler[query(1,1,idx-1,min(l,r),max(l,r))]<<endl;
		}
	}

	return 0;
}
