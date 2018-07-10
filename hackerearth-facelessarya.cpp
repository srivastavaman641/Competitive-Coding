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
ll dp[505][505],a[505][505];
vector<vector<vector<ll> > >g;
int n,m;
ll recur(ll x,ll y)
{
	if(x==n)
		return a[x][y];
	if(dp[x][y]!=-1)
		return dp[x][y];
	ll ans=0;
	for(int i=1;i<=m;i++)
	{
		ll g1=g[x][y][i];
		if(g1!=1)
			ans=max(ans,a[x][y]+recur(x+1,i));
	}
	return dp[x][y]=ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		g.resize(n+5);
		for(int i=1;i<=n+4;i++)
			g[i].resize(m+5);
		for(int i=1;i<=n+4;i++)
		{
			for(int j=1;j<=m+4;j++)
				g[i][j].resize(m+5);
		}
		if(n==1 && m==1)
		{
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j];
			for(int i=1;i<n;i++)
			{
				for(int j=1;j<=m;j++)
				{
					for(int k=1;k<=m;k++)
					{
						g[i][j][k]=__gcd(a[i][j],a[i+1][k]);
					}
				}
			}
			memset(dp,-1,sizeof dp);
			ll ans=0;
			for(int i=1;i<=m;i++)
			{
				ans=max(ans,recur(1,i));
			}
			cout<<ans<<endl;
		}
		return 0;
	}
