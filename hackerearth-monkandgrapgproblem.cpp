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
vector<int>v[100005];
int vis[100005];
ll e=0,edges=0;
   ll mx=0;
void dfs(int x)
{
	vis[x]=1;
	for(int i=0;i<v[x].size();i++)
	{
			edges++;
		if(!vis[v[x][i]])
			dfs(v[x][i]);
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
   		{
   			e=0,edges=0;
   			dfs(i);
   			mx=max(mx,edges/2);
   		}
   }
   cout<<mx<<endl;

   return 0;
}
