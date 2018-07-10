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
priority_queue<pii,vector<pii>,greater<pii> >q;
int vis[10005];
int main()
{
   int n,m;
   cin>>n>>m;
   for(int i=1;i<=m;i++)
   {
   		int x,y,z;
   		cin>>x>>y>>z;
   		v[x].pb(mp(z,y));
   		v[y].pb(mp(z,x));
   }
   q.push(mp(0,1));
   ll ans=0;
   pii p;
   while(!q.empty())
   {
   		p=q.top();
   		q.pop();
   		int x=p.first,y=p.second;
   		if(vis[y])
   			continue;
   		vis[y]=1;
   		ans+=x;
   		for(int i=0;i<v[y].size();i++)
   		{
   			if(!vis[v[y][i].second])
   				q.push(v[y][i]);
   		}
   }
   cout<<ans<<endl;
   return 0;
}
