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
ll a[505][505],b[505][505],dp[505][505];
ll recur(int n,int m)
{
	if(n==0 || m==0)
		return 0;
	if(dp[n][m]!=-1)
		return dp[n][m];
	ll ans=max(a[n][m]+recur(n-1,m),b[n][m]+recur(n,m-1));
	return dp[n][m]=ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(1)
	{
		int n,m;
		cin>>n>>m;
		if(n==0 && m==0)
			break;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
				a[i][j]+=a[i][j-1];
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				cin>>b[i][j];
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
				b[j][i]+=b[j-1][i];
		}
		memset(dp,-1,sizeof dp);
		cout<<recur(n,m)<<endl;
	}

	return 0;
}
