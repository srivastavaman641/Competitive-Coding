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
ll dis[100005],vis[100005];
map<ll,ll>m1;
priority_queue<pii,vector<pii>,greater<pii> >pq;
ll n,m,k,q;
void djikshtra()
{
	while(!pq.empty())
	{
		pii p=pq.top();
		pq.pop();
		ll d=p.first;
		ll x=p.second;
		if(vis[x])
			continue;
		vis[x]=1;
		for(int i=0;i<v[x].size();i++)
		{
			ll k=v[x][i].first;
			ll l=v[x][i].second;
			if(dis[l]>dis[x]+k)
			{
				dis[l]=dis[x]+k;
				pq.push(mp(dis[l],l));
			}
		}

	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>k>>q;
	for(int i=1;i<=m;i++)
	{
		ll x,y,z;
		cin>>x>>y>>z;
		v[x].pb(mp(z,y));
		v[y].pb(mp(z,x));
	}
	for(int i=1;i<=n;i++)
	{
		vis[i]=0;
		dis[i]=INT_MAX;
	}
	for(int i=1;i<=k;i++)
	{
		int x;
		cin>>x;
		pq.push(mp(0,x));
		dis[x]=0;   
	}
	
	djikshtra();
	while(q--)
	{
		int x;
		cin>>x;
		cout<<dis[x]<<endl;
	}


	return 0;
}
