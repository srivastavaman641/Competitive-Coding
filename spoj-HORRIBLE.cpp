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
ll tree[400005],lazy[400005];
void update(ll node,ll start,ll end,ll l,ll r,ll val)
{
	if(lazy[node]!=0)
	{
		tree[node]+=((end-start+1)*lazy[node]);

		if(start!=end)
		{
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}

		lazy[node]=0;
	}
	if(start>end || start>r || end<l)
		return;
	if(start>=l && end<=r)
	{
		tree[node]+=(end-start+1)*val;

		if(start!=end){

			lazy[2*node]+=val;
			lazy[2*node+1]+=val;
		}

		return;
	}
	ll mid=(start+end)/2;

	update(2*node,start,mid,l,r,val);
	update(2*node+1,mid+1,end,l,r,val);

	tree[node]=tree[2*node]+tree[2*node+1];
}
ll query(ll node,ll start,ll end,ll l,ll r)
{
	if(start>end || start>r || end<l)
		return 0;
	if(lazy[node]!=0)
	{
		tree[node]+=((end-start+1)*lazy[node]);
		if(start!=end)
		{
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(start>=l && end<=r)
		return tree[node];
	ll mid=(start+end)/2;
	ll p1 = query(node*2, start, mid, l, r);        
    ll p2 = query(node*2 + 1, mid + 1, end, l, r); 
    return (p1 + p2);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--){
		ll n,q;
		cin>>n>>q;
		memset(lazy,0,sizeof lazy);
		memset(tree,0,sizeof tree);
		while(q--)
		{
			ll m,x,y,val;
			cin>>m;
			if(m==0)
			{
				cin>>x>>y>>val;
				update(1,1,n,x,y,val);
			}
			else
			{
				cin>>x>>y;
				cout<<query(1,1,n,x,y)<<endl;
			}

		}
	}
	return 0;
}
