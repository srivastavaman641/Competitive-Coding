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
int low[100005],disc[100005],vis[100005],bridge[100005],parent[100005];
vector<pii>v[100005];
int timer=0;
void dfs(int x,int pr)
{
	vis[x]=1;
	low[x]=disc[x]=timer++;
	parent[x]=pr;
	for(int i=0;i<v[x].size();i++)
	{
		int x1=v[x][i].first;
		int y1=v[x][i].second;
		if(!vis[x1])
		{
			dfs(x1,x);
			low[x]=min(low[x],low[x1]);
			if(low[x1]>disc[x])
				bridge[y1]=1;
		}
		else if(x1!=parent[x])
			low[x]=min(low[x],disc[x1]);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,q;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].pb(mp(y,i));
		v[y].pb(mp(x,i));
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
			dfs(i,0);
	}
	cin>>q;
	while(q--)
	{
		int x;
		cin>>x;
		if(bridge[x]==1)
			cout<<"Unhappy"<<"\n";
		else
			cout<<"Happy"<<"\n";
	}

	return 0;
}
