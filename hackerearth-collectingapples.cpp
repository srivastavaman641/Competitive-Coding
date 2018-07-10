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
ll n,p;
ll dp[1005][1005],milk[1005],apple[1005];
ll recur(ll x,ll e)
{
	if(x>n || e<0)
		return 0;
	if(e>n)
		e=n
	if(dp[x][e]!=-1)
		return dp[x][e];
	ll ans=0;
	ans=max(apple[x]+recur(x+1,e-1),recur(x+1,e+milk[x]-1));
	return dp[x][e]=ans;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   while(t--)
   {
   		cin>>n>>p;
   		for(int i=1;i<=n;i++)
   			cin>>milk[i];
   		ll sum=0;
  		for(int i=1;i<=n;i++){
  			cin>>apple[i];
  			sum+=apple[i];
  		}
  		if(p>n)
  		{
  			cout<<sum<<endl;
  			continue;
  		}
  		memset(dp,-1,sizeof dp);
  		cout<<recur(1,p-1)<<endl;
   }


   return 0;
}
