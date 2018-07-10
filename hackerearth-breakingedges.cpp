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
vector<ll>v[200010];
int vis[200010];
ll b[1050000][23];
ll a[200010];
ll ans=0;
void dfs(int x)
{
	vis[x]=1;
	for(int i=0;i<v[x].size();i++)
	{
		if(!vis[v[x][i]])
		{
			dfs(v[x][i]);
			for(int j=0;j<22;j++)
			{
				b[x][j]+=b[v[x][i]][j];
			}

		}
	}
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin>>n;
   for(int i=1;i<=n;i++)
   {
   		cin>>a[i];
   		for(int j=0;j<22;j++)
   		{
   			if(a[i]&(1<<j))
   				b[i][j]+=1;
   		}
   }
   for(int i=0;i<n-1;i++)
   {
   		ll x,y;
   		cin>>x>>y;
   		v[x].pb(y);
   		v[y].pb(x);
   }
   dfs(1);
  for(int i=2;i<=n;i++)
   {
   		for(int j=0;j<22;j++)
			{
				b[1][j]-=b[i][j];
			}
			int flag=1;
		for(int j=0;j<22;j++)
		{
			if((b[1][j]>0 && b[i][j]>0)|| (b[1][j]==0 && b[i][j]==0))
			{
				flag=1;
			}
			else
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
			ans++;
		for(int j=0;j<22;j++)
			{
				b[1][j]+=b[i][j];
			}

   }
   cout<<ans<<endl;


   return 0;
}
