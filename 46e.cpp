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
int low[300005],disc[300005],vis[300005],parent[300005];
int timer=0;
vector<int>v[300005];	
int ans=0;
void dfs(int x,int par)
{
	vis[x]=1;
	low[x]=disc[x]=timer++;
	parent[x]=par;
	for(int i=0;i<v[x].size();i++)
	{
		if(!vis[v[x][i]])
		{
			dfs(v[x][i],x);
			low[x]=min(low[x],low[v[x][i]]);
			if(low[v[x][i]]>disc[x])
				ans++;
		}
		else if(v[x][i]!=parent[x])
			low[x]=min(low[x],disc[v[x][i]]);
	}
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n,m;
   cin>>n>>m;
   for(int i=0;i<m;i++)
   {
   		int x,y;
   		cin>>x>>y;
   		v[x].pb(y);
   		v[y].pb(x);
   }
   for(int i=1;i<=n;i++)
   {
   		if(!vis[i])
   			dfs(i,-1);
   }
   cout<<ans<<endl;

   return 0;
}
