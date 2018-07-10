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
vector<int>v[105];
int timer=0;
int vis[105],disc[105],low[105],parent[105],ap[105];
void dfs(int x,int pr)
{
	vis[x]=1;
	disc[x]=low[x]=timer++;
	parent[x]=pr;
	int child=0;
	for(int i=0;i<v[x].size();i++)
	{
		if(!vis[v[x][i]])
		{
			child++;
			dfs(v[x][i],x);
			low[x]=min(low[x],low[v[x][i]]);
			if(parent[x]==-1 && child>1)
				ap[x]=1;
			else if(parent[x]!=-1 && low[v[x][i]]>=disc[x])
			{
				ap[x]=1;
			}
		}
		else if(v[x][i]!=parent[x])
		{
			low[x]=min(low[x],disc[v[x][i]]);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	for(int i = 1;i <= n; i++){
		low[i] = INT_MAX;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
			dfs(i,-1);
	}
	int q;
	cin>>q;
	while(q--)
	{
		int x;
		cin>>x;
		if(ap[x]==1)
		{
			int ans=0;
			ans=v[x].size();
			cout<<"Satisfied "<<ans<<endl;
		}
		else
			cout<<"Not Satisfied"<<endl;

	}
	return 0;
}
