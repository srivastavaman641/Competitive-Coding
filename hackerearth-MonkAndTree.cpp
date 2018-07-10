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
int parent[200005],vis[200005];
vector<pair<int,pii> >v;
vector<int>adj[200005];
int root(int x)
{
	while(x!=parent[x])
	{
		parent[x]=parent[parent[x]];
		x=parent[x];
	}
	return x;
}
void union1(int x,int y)
{
	parent[x]=y;
}
void dfs(int x)
{
	vis[x]=1;
	for(int i=0;i<adj[x].size();i++)
	{
		if(!vis[adj[x][i]])
			dfs(adj[x][i]);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		v.clear();
		for(int i=1;i<=n;i++){
			parent[i]=i;
			vis[i]=0;
			adj[i].clear();
		}
		for(int i=1;i<=m;i++)
		{
			int x,y,z;
			cin>>x>>y;
			adj[x].pb(y);
			adj[y].pb(x);
			z=abs(x-y);
			v.pb(mp(z,mp(x,y)));
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==0){
				dfs(i);
				ans++;
			}
		}
		ans--;
		sort(v.rbegin(),v.rend());
		for(int i=0;i<v.size();i++)
		{
			int x=v[i].second.first;
			int y=v[i].second.second;
			int z=v[i].first;
			int a=root(x);
			int b=root(y);
			if(a!=b)
			{
				union1(a,b);
			}
			else
			{
				ans+=z;
			}
		}
		int cnt=0;
		/*for(int i=1;i<=n;i++)
		{
			if(parent[i]==i)
				cnt++;
		}*/
		cout<<ans<<endl;
	}


	return 0;
}
