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
vector<int>v,v1;
int dp[2005][2005];
int n,m;
int recur(int x,int y)
{
	if(x==n||y==m)
		return 0;
	if(dp[x][y]!=-1)
		return dp[x][y];
	int ans=0;
	if(v[x]==v1[y])
		ans=1+recur(x+1,y+1);
	else
	ans=max(recur(x+1,y),recur(x,y+1));
	return dp[x][y]=ans;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   memset(dp,-1,sizeof dp);
   cin>>n>>m;
   for(int i=1;i<=n;i++)
   {
   	 int x;
   	 cin>>x;
   	 v.pb(x);
   }
   for(int i=1;i<=m;i++)
   {
   	 int x;
   	 cin>>x;
   	 v1.pb(x);
   }

   cout<<recur(0,0)<<endl;
   return 0;
}
