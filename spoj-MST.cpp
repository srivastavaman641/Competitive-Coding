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
vector<pii>v[100005];
int vis[100005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		ll x,y,z;
		cin>>x>>y>>z;
		v[x].pb(mp(z,y));
		v[y].pb(mp(z,x));
	}
	priority_queue<pii,vector<pii>,greater<pii> >pq;
	pq.push(mp(0,1));
	ll ans=0;
	while(!pq.empty())
	{
		pii p=pq.top();
		pq.pop();
		ll x=p.second;
		ll z=p.first;
		if(vis[x])
			continue;
		vis[x]=1;
		ans+=z;
		for(int i=0;i<v[x].size();i++)
		{
			ll x1=v[x][i].second;
			ll y1=v[x][i].first;
			if(!vis[x1])
				pq.push(v[x][i]);
		}

	}
	cout<<ans<<endl;

	return 0;
}
