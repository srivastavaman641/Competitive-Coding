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
ll tree[80005],a[20005];
void build(int node,int l,int r)
{
	if(l==r)
	{
		tree[node]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(2*node,l,mid);
	build(2*node+1,mid+1,r);
	tree[node]=tree[2*node]&tree[2*node+1];
}
ll query(ll node,ll start,ll end,ll l,ll r)
{
	if(start>r||end<l)
		return -1ll;
	if(start>=l && end<=r)
		return tree[node];
	int mid=(start+end)/2;
	ll ans=query(2*node,start,mid,l,r)&query(2*node+1,mid+1,end,l,r);
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		for(ll i=1;i<=n;i++)
			cin>>a[i];
		memset(tree,0,sizeof tree);
		build(1,1,n);
		k=min(k,n);
		for(ll i=1;i<=n;i++)
		{
			ll l=(i-k+n)%n;
			ll r=(i+k)%n;
			if(l==0){
				l=n;
			}
			if(r==0){
				r=n;
			}
			ll ans;
			if(l<i)
				ans=query(1,1,n,l,i);
			else
				ans=(query(1,1,n,1,i)&query(1,1,n,l,n));
			if(r>i)
				ans&=query(1,1,n,i,r);
			else
				ans&=query(1,1,n,i,n)&query(1,1,n,1,r);
			cout<<ans<<" ";
		}
		cout<<endl;
	}


	return 0;
}
