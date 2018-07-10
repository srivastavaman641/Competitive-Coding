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
ll dp[505][105][105];
int a[505];
int n;
ll gcd(ll x,ll y)
{
	if(y==0)
		return x;
	return gcd(y,x%y);
}
ll recur(int x,int gc,int prev)
{
	if(x>n)
	{
		if(gc==1)
			return 1;
		else
			return 0;
	}
	if(dp[x][gc][prev]!=-1)
		return dp[x][gc][prev];
	ll ans=0;
	if(prev<a[x])
	{
		ans=(recur(x+1,gc,prev)%mod+recur(x+1,gcd(gc,a[x]),a[x])%mod)%mod;
	}
	else
		ans=recur(x+1,gc,prev);
	return dp[x][gc][prev]=ans;

}	
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cin>>n;
   memset(dp,-1,sizeof dp);
   for(int i=1;i<=n;i++)
   		cin>>a[i];
   cout<<recur(0,0,0)<<endl;


   return 0;
}
