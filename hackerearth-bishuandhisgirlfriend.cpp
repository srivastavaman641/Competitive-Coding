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
int vis[1005],dis[1005];
vector<int> v[1005];
void dfs(int root){
	vis[root]=1;
	for(int i=0;i<v[root].size();i++)
	{
		if(!vis[v[root][i]])
		{
			dis[v[root][i]]=dis[root]+1;
			dfs(v[root][i]);
		}
	}
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n,q,mn=INT_MAX,ans=0;
   cin>>n;
   memset(vis,0,sizeof vis);
   memset(dis,0,sizeof dis);
   for(int i=0;i<n-1;i++)
   {
   		int x,y;
   		cin>>x>>y;
   		v[x].pb(y);
   		v[y].pb(x);
   }
   dfs(1);
   cin>>q;
   while(q--)
   {
   		int q1;
   		cin>>q1;
   		if(dis[q1]<mn)
   		{
   			mn=dis[q1];
   			ans=q1;
   		}
   		if(dis[q1]==mn)
   		{
   			if(q1<ans)
   				ans=q1;
   		}
   }
   cout<<ans<<endl;
   return 0;
}
