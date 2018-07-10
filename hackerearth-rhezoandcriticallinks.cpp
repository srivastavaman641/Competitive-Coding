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
int ans=0,cnt=1,e=0;
int vis[100005],vis1[100005];
vector<int>v[100005];
int n,m,p;
void dfs1(int x)
{
	vis1[x]=1;
	for(int i=0;i<v[x].size();i++)
	{
		e++;
		if(!vis1[v[x][i]])
		{
			cnt++;
			dfs1(v[x][i]);
		}
	}
}
int dfs(int x)
{
	vis[x]=1;
	int child=1;
	for(int i=0;i<v[x].size();i++)
	{
		if(!vis[v[x][i]])
		{
			child+=dfs(v[x][i]);
			if(abs(cnt-child)<p)
				ans++;
		}
	}
	return child;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   cin>>n>>m>>p;
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
   			cnt=1;
   			e=0;
   			dfs1(i);
   			e/=2;
   			if(e==cnt-1)
   				dfs(i);
   		}
   }
   cout<<ans<<endl;

   return 0;
}
