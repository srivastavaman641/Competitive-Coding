#include<bits/stdc++.h>
#define ll long long int


using namespace std;
ll dp[3001][4][3001]={0};
ll a[3001],val[3001];
int n;
ll recur(int x,int prev,int cnt)
{
	if(cnt==0)
		return 0;
	if(x==n+1)
		return INT_MAX;
	if(dp[x][cnt][prev])
		return dp[x][cnt][prev];
	ll ans=recur(x+1,prev,cnt);
	if(a[x]>a[prev])
		ans=min(ans,val[x]+recur(x+1,x,cnt-1));
	return dp[x][cnt][prev]=ans;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cin>>n;
   for(int i=1;i<=n;i++)
    cin>>a[i];
 for(int i=1;i<=n;i++)
    cin>>val[i];

 ll ans=recur(1,0,3);
 if(ans==INT_MAX)
    ans=-1;
 cout<<ans<<endl;
 return 0;
}