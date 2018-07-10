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
int x[]={1,-1,0,0};
int y[]={0,0,1,-1};
int vis[1005][1005];
int a[1005][1005];
ll dp[1005][1005];
ll n;
ll dfs(int i,int j)
{
	if(dp[i][j])
		return dp[i][j];
	vis[i][j]=1;
	ll ans=1;
	for(int k=0;k<4;k++)
	{
		if(i+x[k]<=n && i+x[k]>0 && j+y[k]>0 && j+y[k]<=n && a[i+x[k]][j+y[k]]<a[i][j] && !vis[i+x[k]][j+y[k]])
		{
			ans=(ans+dfs(i+x[k],j+y[k]))%mod;
		}
	}
	vis[i][j]=0;
	return dp[i][j]=ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	ll res=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			res=(res+dfs(i,j))%mod;
		}
	}	
	cout<<res<<endl;

	return 0;

}
