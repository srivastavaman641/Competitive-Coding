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
map<ll,ll>m,size;
ll root(ll x)
{
	while(x!=m[x])
	{
		m[x]=m[m[x]];
		x=m[x];
	}
	return x;
}
void union1(ll x,ll y)
{
	ll root_x=x;
	ll root_y=y;
	if(size[root_x]>size[root_y])
	{
		m[root_y]=root_x;
		size[root_x]+=size[root_y];
	}
	else
	{
		m[root_x]=root_y;
		size[root_y]+=size[root_x];
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,mp;
	cin>>n>>mp;
	ll ans=n;
	for(int i=1;i<=mp;i++)
	{
		ll x,y;
		cin>>x>>y;
		if(!m[x])
		{
			m[x]=x;
			size[x]=1;
		}
		if(!m[y])
		{
			m[y]=y;
			size[y]=1;
		}
		ll a=root(x);
		ll b=root(y);
		if(a!=b)
		{
			union1(a,b);
			ans--;
		}
	}
	cout<<ans<<endl;

	return 0;
}
