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
ll dp[10005],a[505],w[505];
int n;
ll recur(int W)
{
	if(W==0)
		return 0;
	if(W<0)
		return INT_MAX;
	if(dp[W]!=-1)
		return dp[W];
	ll ans=INT_MAX;
	for(int i=1;i<=n;i++)
	{
		ans=min(ans,a[i]+recur(W-w[i]));
	}
	return dp[W]=ans;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   while(t--)
   {
   		int e,f;
   		cin>>e>>f>>n;
   		int W=f-e;
   		memset(dp,-1,sizeof dp);
   		for(int i=1;i<=n;i++)
   			cin>>a[i]>>w[i];
   		ll x=recur(W);
   		if(x==INT_MAX)
   			cout<<"This is impossible."<<endl;
   		else
   			cout<<"The minimum amount of money in the piggy-bank is "<<x<<"."<<endl;
   }


   return 0;
}
