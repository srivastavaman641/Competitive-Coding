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
ll dp[105][105];
ll p[105];
int n,m;
ll recur(int x,int y)
{
	if(x<0 || y<0)
		return INT_MAX;

	if(y==0)
		return 0;
	
	if(dp[x][y]!=-1)
		return dp[x][y];

	ll ans=INT_MAX;
	for(int i=1;i<=m;i++)
	{
		if(p[i]==-1)continue;
		ans=min(ans,p[i]+recur(x-1,y-i));
	}
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
   		for(int i=1;i<=m;i++)
   			cin>>p[i];
   		memset(dp,-1,sizeof dp);
   		ll ans=recur(n,m);
   		if(ans==INT_MAX)
   			ans=-1;
   		cout<<ans<<endl;
   }

   return 0;
}
