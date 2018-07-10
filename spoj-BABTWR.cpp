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
ll a[35],b[35],c[35];
ll dp[2505][2505];
int n;
ll recur(ll x,ll y)
{
	if(dp[x][y]!=-1)
		return dp[x][y];
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		if(b[i]<x && c[i]<y)
			ans=max(ans,a[i]+recur(b[i],c[i]));
		if(b[i]<y && c[i]<x)
			ans=max(ans,a[i]+recur(c[i],b[i]));
		if(a[i]<x && c[i]<y)
			ans=max(ans,b[i]+recur(a[i],c[i]));
		if(c[i]<x && a[i]<y)
			ans=max(ans,b[i]+recur(c[i],a[i]));
		if(a[i]<x && b[i]<y)
			ans=max(ans,c[i]+recur(a[i],b[i]));
		if(b[i]<x && a[i]<y)
			ans=max(ans,c[i]+recur(b[i],a[i]));
	}
	return dp[x][y]=ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(1)
	{
		cin>>n;
		if(n==0)
			break;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		memset(dp,-1,sizeof dp);
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,c[i]+recur(a[i],b[i]));
			ans=max(ans,a[i]+recur(b[i],c[i]));
			ans=max(ans,b[i]+recur(a[i],c[i]));
			ans=max(ans,c[i]+recur(b[i],a[i]));
			ans=max(ans,a[i]+recur(c[i],b[i]));
			ans=max(ans,b[i]+recur(c[i],a[i]));
		}
		cout<<ans<<endl;
	}


	return 0;
}
