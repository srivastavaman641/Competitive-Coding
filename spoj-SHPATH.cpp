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
vector<pii>v[10005];
int djikshtra(int n,int m,int size)
{
	ll dis[size+1];
	int vis[size+1];
	priority_queue<pii,vector<pii>,greater<pii> >pq;
	memset(vis,0,sizeof vis);
	for(int i=0;i<=size;i++)
		dis[i]=INT_MAX;
	dis[n]=0;
	pq.push(mp(0,n));
	while(!pq.empty())
	{
		pii p=pq.top();
		pq.pop();
		ll x=p.first;
		ll y=p.second;
		if(vis[m])
			break;
		if(vis[y])
			continue;
		vis[y]=1;
		for(int i=0;i<v[y].size();i++)
		{
			ll k=v[y][i].first;
			ll z=v[y][i].second;
			if(k+dis[y]<dis[z])
			{
				dis[z]=k+dis[y];
				pq.push(mp(dis[z],z));
			}
		}
	}
	return dis[m];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<=n;i++)
			v[i].clear();
		map<string,int>m;
		for(int i=1;i<=n;i++)
		{
			string s;
			cin>>s;
			m[s]=i;
			int x;
			cin>>x;
			for(int j=1;j<=x;j++)
			{
				ll a,b;
				cin>>a>>b;
				v[i].pb(mp(b,a));
			}
		}
		int r;
		cin>>r;
		while(r--)
		{
			string s1,s2;
			cin>>s1>>s2;
			cout<<djikshtra(m[s1],m[s2],n)<<endl;
		}
	}

	return 0;
}
