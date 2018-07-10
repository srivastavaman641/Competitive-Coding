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
ll n,l;
ll dp[10005][85];
ll len[85],val[85];
ll recur(ll x,ll p)
{
	if(x<=0)
		return 0;

	if(dp[x][p]!=-1)
		return dp[x][p];

	ll a=INT_MAX;
	for(ll i=p+1;i<=n;i++)
	{
		a=min(a,len[i]+recur(x-len[i],i));
	}
	return dp[x][p]=a;
}
ll recur2(ll x,ll p)
{
	if(x==0 || p==n)
		return 0;
	if(dp[x][p]!=-1)
		return dp[x][p];
	ll a=0;
	for(int i=p+1;i<=n;i++)
	{
		if(len[i]<=x)
			a=max(a,val[i]+recur2(x-len[i],i));
	}
	return dp[x][p]=a;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>l;
	for(ll i=1;i<=n;i++)
	{
		cin>>len[i]>>val[i];
	}
	memset(dp,-1,sizeof dp);
	ll x=recur(l,0);
	memset(dp,-1,sizeof dp);
	cout<<recur2(x,0)<<endl;
	return 0;
}