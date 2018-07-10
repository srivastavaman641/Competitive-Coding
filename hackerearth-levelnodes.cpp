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
int vis[100005],dis[100005];
void dfs(int x,int d)
{
	vis[x]=1;
	dis[d]++;
	for(int i=0;i<v[x].size();i++)
	{
		if(!vis[v[x][i]])
		{
			dfs(v[x][i],d+1);
		}
	}
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n,d;
   cin>>n;
   for(int i=1;i<=n-1;i++)
   {
   		int x,y;
   		cin>>x>>y;
   		v[x].pb(y);
   		v[y].pb(x);
   }
   cin>>d;
   dfs(1,1);
   cout<<dis[d]<<endl;
   return 0;
}
