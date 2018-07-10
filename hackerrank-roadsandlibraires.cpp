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
vector<ll>v[100005];
int vis[100005];
ll c=0;
void dfs(ll i)
{
	vis[i]=1;
	for(ll j=0;j<v[i].size();j++)
	{
		if(vis[v[i][j]]==0)
		{
			dfs(v[i][j]);
			c++;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll q;
	cin>>q;
	while(q--)
	{
		ll n,m,lib,road;
		cin>>n>>m>>lib>>road;
		for(int i=0;i<100005;i++)
			v[i].clear();
		memset(vis,0,sizeof vis);
		for(ll i=1;i<=m;i++)
		{
			ll x,y;
			cin>>x>>y;
			v[x].pb(y);
			v[y].pb(x);
		}
		if(road>=lib)
		{
			cout<<n*lib<<endl;
			continue;
		}
		else
		{
			ll ans=0;
			for(ll i=1;i<=n;i++)
			{
				if(vis[i]==0)
				{
					c=0;
					c++;
					dfs(i);
					ans=ans+(lib+(road*(c-1)));
				}
			}
			cout<<ans<<endl;
		}	
	}

	return 0;
}
