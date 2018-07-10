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
ll tree[400005],a[100005];
ll n;
void build(ll node,ll start,ll end)
{
	if(start==end)
	{
		tree[node]=start;
		return;
	}
	ll mid=(start+end)/2;
	build(2*node,start,mid);
	build(2*node+1,mid+1,end);
	if(a[tree[2*node]]>a[tree[2*node+1]])
		tree[node]=tree[2*node+1];
	else
		tree[node]=tree[2*node];
}
ll query(ll node,ll start,ll end,ll l,ll r)
{
	if(start>end || start>r || end<l)
		return -1;
	if(start>=l && end<=r)
		return tree[node];
	ll mid=(start+end)/2;
	ll p1=query(2*node,start,mid,l,r);
	ll p2=query(2*node+1,mid+1,end,l,r);
	if(p1==-1)
		return p2;
	else if(p2==-1)
		return p1;
	if( a[p1]>a[p2])
		return p2;
	else
		return p1;
}
ll dfs(ll node,ll start,ll end)
{
	if(start>end)
		return INT_MIN;
	if(start==end)
		return a[start];
	ll mn=query(1,1,n,start,end);
	return max(a[mn]*(end-start+1),max(dfs(2*node,start,mn-1),dfs(2*node+1,mn+1,end)));

}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   while(1)
   {
   		cin>>n;
   		if(n==0)
   			break;
   		for(int i=1;i<=n;i++)
   			cin>>a[i];
   		memset(tree,0,sizeof tree);
   		build(1,1,n);
   		cout<<dfs(1,1,n)<<endl;
   }


   return 0;
}
