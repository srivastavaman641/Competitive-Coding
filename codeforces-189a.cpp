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
int n,a,b,c;
ll dp[4005];
int recur(int x)
{
	if(x<0)
		return -10000007;
	if(x==0)
		return 0;
	if(dp[x]!=-1)
		return dp[x];
	int ans=0;
	ans=max(1+recur(x-a),max(1+recur(x-b),1+recur(x-c)));
	return dp[x]=ans;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cin>>n>>a>>b>>c;
   memset(dp,-1,sizeof dp);
   cout<<recur(n)<<endl;

   return 0;
}
