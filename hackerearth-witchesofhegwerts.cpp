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
map<ll,ll>dp;
ll recur(ll n){
	if(n==1 || n==0)
		return 0;
	if(dp[n]!=0)
		return dp[n];

	ll x=mod,y=mod,z=mod;
	z=1+recur(n-1);
	if(n%2==0)
		y=1+recur(n/2);
	if(n%3==0)
		x=1+recur(n/3);
	dp[n]=min(x,min(y,z));
	return dp[n];
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   //ll mx=mod;
   //ll l=recur(mx);
   //dp[1]=0;	
   while(t--){
   		ll n;
   		cin>>n;
   		cout<<recur(n)<<endl;
   }
   return 0;
}
