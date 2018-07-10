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
int r,c;
ll dp[105][105],a[105][105];
ll recur(int m,int n)
{
	if(m==r)
		return a[m][n];
	if(dp[m][n]!=-1)
		return dp[m][n];
	ll x=-1,y=-1,z=-1;
	if(m+1<=r)
		 x=recur(m+1,n);
	if(m+1<=r && n-1>0)
		 y=recur(m+1,n-1);
	if(m+1<=r && n+1<=c)
		 z=recur(m+1,n+1);
	ll ans=a[m][n]+max(x,max(y,z));
	return dp[m][n]=ans;

}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   while(t--)
   {
   		
   		cin>>r>>c;
   		memset(dp,-1,sizeof dp);
   		for(int i=1;i<=r;i++)
   		{
   			for(int j=1;j<=c;j++)
   			{
   				cin>>a[i][j];
   			}
   		}
   		ll mx=-1;
   		for(int i=1;i<=c;i++)
   		{
   			mx=max(mx,recur(1,i));
   		}
   		cout<<mx<<endl;
   }


   return 0;
}
