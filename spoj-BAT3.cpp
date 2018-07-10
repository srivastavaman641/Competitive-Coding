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
ll dp[1005];
ll a[1005];
ll recur(int pos)
{
	if(pos==n)
		return 0;
	if(dp[pos]!=-1)
		return dp[pos];
	ll ans=0;
	for(int i=pos+1;i<=n;i++)
	{
		if(pos==m+1){
			ans=max(ans,1+recur(i));
		}
		else
		{
			if(a[i]<a[pos])
				ans=max(ans,1+recur(i));
		}

	}
	return dp[pos]=ans;
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
			cin>>a[i];
		memset(dp,-1,sizeof dp);
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,1+recur(i));
		}
		cout<<ans<<endl;
	}


	return 0;
}
