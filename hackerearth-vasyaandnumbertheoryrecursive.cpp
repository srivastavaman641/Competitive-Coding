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
ll dp[1005][1005],a[1005];
int n;
ll recur(int curr,int prev)
{
	if(curr==n+1)
		return 0;
	if(dp[curr][prev]!=-1)
		return dp[curr][prev];
	ll ans=1;
	ans=recur(curr+1,prev);
	if(prev==0 || a[curr]%a[prev]==0)
		ans=max(ans,1+recur(curr+1,curr));
	return dp[curr][prev]=ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	memset(dp,-1,sizeof dp);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a,a+n+1);
	ll ans=recur(1,0);
	if(ans<2)
		ans=-1;
	cout<<ans<<endl;
	return 0;
}




