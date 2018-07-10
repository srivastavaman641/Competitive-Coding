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
int a[100005];
int dp[100005];
int n;
int ans=0;
int recur(int i)
{
	int res=0;
	if(dp[i]!=-1)
		return dp[i];
	if(i==n-2)
		return dp[i]=max(abs(1-a[i+1]),abs(a[i]-a[i+1]));
	res=max(abs(1-recur(i+1)),abs(a[i]-recur(i+1)));
	ans+=res;
	return dp[i]=ans;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   //int n;
   for(int i=0;i<100005;i++)
   	dp[i]=-1;
   cin>>n;
   for(int i=0;i<n;i++)
   {
   	cin>>a[i];
   }
   int ans=recur(0);
   for(int i=0;i<n;i++)
   {
   	cout<<dp[i]<<endl;
   }
   cout<<ans<<endl;
   return 0;
}
