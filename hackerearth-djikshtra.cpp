#include<bits/stdc++.h>
#define ll long long int
#define s(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define w(t) while(t--)
#define f(i,n) for(int i=0;i<n;i++)
#define fd(i,n) for(int i=n-1;i>=0;i--)
#define p(a) printf("%d",a)
#define pl(a) printf("%lld",a)
#define ps(a) printf("%s",a)
#define pc(a) printf("%c",a)
#define ent printf("\n")
#define mod 1000000000
#define PI 3.14159265
#define gs getline(cin,s)
#define pb push_back
#define mp make_pair
#define INF 1e18
#define pii pair<ll,ll>
#define ff first
#define ss second

using namespace std;
vector<pair<ll,ll> >v[10005];
priority_queue<pii,vector<pii>,greater<pii> >q;
ll dist[10005],vis[10005];
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n,m;
   cin>>n>>m;
   for(int i=1;i<=n;i++){
   		dist[i]=mod;
   		vis[i]=0;
   }
   for(int i=0;i<m;i++)
   {
   		ll x,y,z;
   		cin>>x>>y>>z;
   		v[x].pb(mp(z,y));
   }
   q.push(mp(0,1));
   dist[1]=0;
   pair<ll,ll>p;
   while(!q.empty())
   {
   		p=q.top();
   		q.pop();
   		ll y=p.ff,x=p.ss;
   		if(vis[x])continue;
   		vis[x]=1;
   		for(ll i=0;i<v[x].size();i++)
   		{
   			if(dist[x]+v[x][i].ff<dist[v[x][i].ss])
   			{
   				dist[v[x][i].ss]=dist[x]+v[x][i].ff;
   				q.push(mp(dist[v[x][i].ss],v[x][i].ss));
   			}
   		}
   }
   for(int i=2;i<=n;i++){
   		cout<<dist[i]<<" ";
   }
   return 0;
}
	