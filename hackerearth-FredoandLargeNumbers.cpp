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
#define pii pair<ll,ll>

using namespace std;
ll a[1000005],b[1000005];
ll lef[1000005],vis[1000005];
vector<pii>v;
int main()
{
	int n;
	cin>>n;
	v.resize(n);
	for(int i=0;i<n;i++)
	{
		v[i].first=v[i].second=0ll;
	}
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		b[i]=a[i];
	}
	sort(b,b+n);
	ll mxf=-1;
	for(int i=0;i<n;i++){
		ll tmp=a[i];
		a[i]=lower_bound(b,b+n,a[i])-b;
		v[a[i]].first+=1;
		v[a[i]].second=tmp;
		mxf=max(mxf,v[a[i]].first);
	}
	ll curr=0;
	for(int i=0;i<n;i++)
	{
		ll x=v[a[i]].first;
		if(x>curr)
		{
			while(x>curr)
			{
				lef[x]=v[a[i]].second;
				x--;
			}
			curr=v[a[i]].first;
		}
		if(!vis[v[a[i]].first])
		{
			vis[v[a[i]].first]=v[a[i]].second;
		}
	}

	int q;
	scanf("%d",&q);
	while(q--)
	{
		int x;
		ll y;
		scanf("%d%lld",&x,&y);
		if(y>mxf)
		{
			printf("0\n");
			continue;
		}
		if(x==0)
		{
			printf("%lld\n",lef[y]);
		}
		else
		{
			printf("%lld\n",vis[y]);
		}

	}

	return 0;
}
