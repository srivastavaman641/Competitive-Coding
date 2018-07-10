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
ll dp[1005][1005];
ll n,m;
ll recur(ll x,ll y)
{
	if(y<((n-x)-y)*m)
		return 0;
	if(x==0){
		if(y>n-y)
			return 1;
		else
			return 0;
	}
	if(dp[x][y]!=-1)
		return dp[x][y];
	ll ans=0;
	ans=(recur(x-1,y)+recur(x-1,y+1))%mod;
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
		memset(dp,-1,sizeof dp);
		cout<<recur(n,0)<<endl;
	}
	return 0;
}
