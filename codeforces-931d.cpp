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

//int ar[100005];
vector<int> v[100005];
int vis[100005];
int lvl[100005];

inline void dfs(int u,int h)
{
	vis[u]=1;
   lvl[h]++;
	int i;
	f(i,v[u].size())
	{
		if(vis[v[u][i]]==0)
		{
			dfs(v[u][i],h+1);
		}
	}

}
int main()
{
   int n;
   cin>>n;
   int i,j,x;
   for(i=2;i<=n;i++)
   {
   	cin>>x;
   v[i].pb(x);
   v[x].pb(i);
   }
   memset(vis,0,sizeof vis);
   memset(lvl,0,sizeof lvl);
    dfs(1,0);

int ans=0;
   for(i=0;i<=n;i++)
   {
   	 if(lvl[i]&1)
   	 {
   	 	ans++;
   	 }
   }

   cout<<ans<<endl;

   return 0;
}
