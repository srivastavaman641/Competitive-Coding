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
ll a[100005],dp[100005][128];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	ll mx=0;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=127;j++)
		{
			dp[i][j]=((dp[i-1][j]+dp[i-1][j^a[i]]))%mod;
		}
	}
	ll ans=0;
	dp[n][0]--;
	for(int i=0;i<=127;i++)
	{
		ll x=dp[n][i];
		if(x>1)
			ans=(ans+(x*(x-1)/2))%mod;
	}
	cout<<ans<<endl;
	return 0;
}
