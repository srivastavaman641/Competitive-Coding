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
ll dp[100005][12];
vector<int>v[12];
int n;
ll recur(int x,int start)
{
	if(x==1)
		return 1;
	if(dp[x][start]!=-1)
		return dp[x][start];
	ll ans=0;
	for(int i=0;i<v[start].size();i++)
	{
		ans=(ans%mod+recur(x-1,v[start][i])%mod)%mod;
	}
	return dp[x][start]=ans;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   v[1].pb(2);
   v[1].pb(4);

   v[2].pb(1);
   v[2].pb(3);
   v[2].pb(5);

   v[3].pb(2);
   v[3].pb(6);

   v[4].pb(1);
   v[4].pb(5);
   v[4].pb(7);

   v[5].pb(4);
   v[5].pb(6);
   v[5].pb(8);
   v[5].pb(2);

   v[6].pb(9);
   v[6].pb(3);
   v[6].pb(5);

   v[7].pb(4);
   v[7].pb(8);
   v[7].pb(0);

   v[8].pb(5);
   v[8].pb(9);
   v[8].pb(7);

   v[9].pb(6);
   v[9].pb(8);

   v[0].pb(7);
   memset(dp,-1,sizeof dp);
   while(t--)
   {
   		cin>>n;
   		ll ans=0;
   		for(int i=0;i<=9;i++)
   			ans=(ans+recur(n,i))%mod;
   		cout<<ans<<endl;
   }
   return 0;
}