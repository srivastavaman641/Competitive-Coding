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
vector<int>v[105],v1;
vector<pii>v2;
int timer=0;
int vis[105],disc[105],low[105],parent[105];
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
				v1.pb(x);
			else if(parent[x]!=-1 && low[v[x][i]]>=disc[x])
			{
				v1.pb(x);
			}
			if(low[v[x][i]]>disc[x])
				v2.pb(mp(x,v[x][i]));

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
   for(int i=0;i<n;i++)
   {
   		if(!vis[i])
   			dfs(i,-1);
   }
   sort(v1.begin(),v1.end());
   sort(v2.begin(),v2.end());
   int x=v1.size();
   cout<<x<<endl;
   for(int i=0;i<x;i++)
   		cout<<v1[i]<<" ";
   	cout<<endl;
   int y=v2.size();
   cout<<y<<endl;
   for(int i=0;i<y;i++)
   		cout<<v2[i].first<<" "<<v2[i].second<<endl;

   return 0;
}
