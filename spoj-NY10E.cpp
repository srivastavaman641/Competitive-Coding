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
ll dp[75][15];
ll n,x;
ll recur(ll p,ll prev)
{
	if(p==0)
		return 1;
	if(dp[p][prev])
		return dp[p][prev];
	ll ans=0;
	for(int i=prev;i<=9;i++)
	{
		ans=ans+recur(p-1,i);
	}
	return dp[p][prev]=ans;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   while(t--)
   {
   		cin>>x>>n;
   		cout<<x<<" "<<recur(n,0)<<endl;
   }
   return 0;
}
