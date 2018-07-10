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
int n,m;
ll a[205],b[205],dp[205][205];
ll recur(int x,int y)
{
	if(y<0)
		return 0;
	if(x==0){
		if(y==0)
			return 1;
		else
			return 0;
	}
	if(dp[x][y]!=-1)
		return dp[x][y];
	ll ans=0;
	for(int i=a[x];i<=b[x];i++)
	{
		ans=(ans+recur(x-1,y-i))%mod;
	}
	return dp[x][y]=ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i];
		}
		memset(dp,-1,sizeof dp);
		cout<<recur(n,m)<<endl;
	}
	return 0;
}
