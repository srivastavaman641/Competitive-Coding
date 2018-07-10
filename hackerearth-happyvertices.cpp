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
vector<int> v[100005];
int vis[100005],parent[100005];
void dfs(int x)
{
	vis[x]=1;
	for(int i=0;i<v[x].size();i++)
	{
		if(!vis[v[x][i]])
		{
			parent[v[x][i]]=x;
			dfs(v[x][i]);
		}
	}
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n,m;
   cin>>n>>m;
   memset(vis,0,sizeof vis);
   for(int i=1;i<=m;i++)
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
   			parent[i]=-1;
   			dfs(i);
   		}
   }
   ll cnt=0;
   for(int i=1;i<=n;i++)
   {
   		if(parent[i]!=-1)
   		{
   			if(parent[parent[i]]==-1)
   			{
   				if(v[i].size()-1>v[parent[i]].size())
   					cnt++;
   			}
   			else{
   				if(v[i].size()>v[parent[i]].size())
   					cnt++;
   			}
   		}
  
   }
   cout<<cnt<<endl;
   return 0;
}
