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
ll dp[1005][26][86],v1[1005],v2[1005],w[1005];
ll n;
ll recur(ll x,ll x1,ll x2)
{
	if((x1==0 && x2==0))
		return 0;
	if(x==n+1)
		return INT_MAX;
	if(dp[x][x1][x2]!=-1)
		return dp[x][x1][x2];
	ll ans=INT_MAX;
	ans=min(w[x]+recur(x+1,max(0ll,x1-v1[x]),max(0ll,x2-v2[x])),recur(x+1,x1,x2));
	return dp[x][x1][x2]=ans;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   while(t--)
   {
   		ll o,v;
   		cin>>o>>v>>n;
   		for(int i=1;i<=n;i++)
   			cin>>v1[i]>>v2[i]>>w[i];
   		for(int i=0;i<1005;i++){
   			for(int j=0;j<25;j++){
   				for(int k=0;k<85;k++){
   					dp[i][j][k]=-1;
   				}
   			}
   		}
   		cout<<recur(0,o,v)<<endl;
   }


   return 0;
}
	