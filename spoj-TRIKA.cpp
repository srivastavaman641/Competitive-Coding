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
int n,m;
int a[25][25];
ll dp[25][25];
ll recur(int x,int y)
{
	if(x>n || y>m)
		return INT_MAX;
	if(x==n && y==m)
		return a[x][y];
	if(dp[x][y]!=-1)
		return dp[x][y];
	ll ans=INT_MAX;
	ans=a[x][y]+min(recur(x+1,y),recur(x,y+1));
	return dp[x][y]=ans;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int x,y;
   cin>>n>>m>>x>>y;
   for(int i=1;i<=n;i++)
   {
   		for(int j=1;j<=m;j++)
   			cin>>a[i][j];
   }
   memset(dp,-1,sizeof dp);
   ll ans=recur(x,y);
   ans-=a[x][y];;
   if(a[x][y]-ans>=0)
   {
   		cout<<"Y"<<" "<<a[x][y]-ans<<endl;
   }
   else
   		cout<<"N"<<endl;
   return 0;
}
