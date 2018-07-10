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
ll dp[55][1005];
ll recur(int balls,int floors)
{
	if(floors==0 || floors==1)
		return floors;
	if(balls==1)
		return floors;
	if(dp[balls][floors]!=-1)
		return dp[balls][floors];
	ll ans=INT_MAX;
	for(int i=1;i<=floors;i++)
	{
		ans=min(ans,max(1+recur(balls,floors-i),1+recur(balls-1,i-1)));
	}
	return dp[balls][floors]=ans;

}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   memset(dp,-1,sizeof dp);
   while(t--)
   {
   		int x,y,z;
   		cin>>x>>y>>z;
   		cout<<x<<" "<<recur(y,z)<<endl;
   }


   return 0;
}
