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
int disc[10005],vis[10005],low[10005],parent[10005],ap[10005];
vector<int>v[10005];
int timer;
void dfs(int x,int pr)
{
	vis[x]=1;
	parent[x]=pr;
	low[x]=disc[x]=timer++;
	int child=0;
	for(int i=0;i<v[x].size();i++)
	{
		if(!vis[v[x][i]])
		{
			child++;
			dfs(v[x][i],x);
			low[x]=min(low[x],low[v[x][i]]);
			if(parent[x]!=0 && low[v[x][i]]>=disc[x])
				ap[x]=1;
			else if(parent[x]==0 && child>1)
				ap[x]=1;
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
   while(1)
   {
   		cin>>n>>m;
   		if(n==0 && m==0)
   			break;
   		for(int i=0;i<=n;i++)
   		{
   			vis[i]=0;
   			parent[i]=0;
   			ap[i]=0;
   			disc[i]=0;
   			low[i]=INT_MAX;
   			v[i].clear();
   		}
   		for(int i=1;i<=m;i++)
   		{
   			int x,y;
   			cin>>x>>y;
   			v[x].pb(y);
   			v[y].pb(x);
   		}
   		timer=0;
   		for(int i=1;i<=n;i++)
   		{
   			if(!vis[i])
   				dfs(i,0);
   		}
   		int ans=0;
   		for(int i=1;i<=n;i++)
   		{
   			if(ap[i])
   				ans++;
   		}
   		cout<<ans<<endl;

   }


   return 0;
}
