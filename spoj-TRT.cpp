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
ll dp[2005][2005];
ll a[2005];
 int n;
ll recur(int l,int h)
{
	if(l>h)
		return 0;
	if(dp[l][h]!=-1)
		return dp[l][h];
	int age=n-(h-l+1)+1;
	ll ans=0;
	ans=max(a[l]*age+recur(l+1,h),a[h]*age+recur(l,h-1));
	return dp[l][h]=ans;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cin>>n;
   for(int i=1;i<=n;i++)
   		cin>>a[i];
   memset(dp,-1,sizeof dp);
   cout<<recur(1,n)<<endl;
   return 0;
}
