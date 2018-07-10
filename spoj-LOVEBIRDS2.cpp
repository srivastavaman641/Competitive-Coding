#include<bits/stdc++.h>
#define ll long long int
#define mod 1908

using namespace std;
int n;
ll dp[1005];
ll recur(int x)
{
	if(x==0 || x==1)
		return 1;
	if(dp[x]!=-1)
		return dp[x];
	ll ans=0;
	for(int i=1;i<=x;i++)
	{
		ans=(ans%mod+(recur(i-1)*recur(x-i))%mod)%mod;
	}
	return dp[x]=ans;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   memset(dp,-1,sizeof dp);
   while(t--)
   {
   		
   		cin>>n;
   		cout<<recur(n)<<endl;
   }
   return 0;
}
