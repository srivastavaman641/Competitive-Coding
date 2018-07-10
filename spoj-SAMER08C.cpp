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
ll r[100005],c[100005],dp[100005];
ll recur(int x,int lim,int id)
{
	if(x>lim)
		return 0;
	if(dp[x]!=-1)
		return dp[x];
	ll ans=0;
	if(id==1)
		ans=max(r[x]+recur(x+2,lim,id),recur(x+1,lim,id));
	else
		ans=max(c[x]+recur(x+2,lim,id),recur(x+1,lim,id));
	return dp[x]=ans;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n,m;
   while(1)
   {
   		cin>>n>>m;
   		if(n==0 && m==0)
   			break;
   		for(int i=1;i<=n;i++)
   		{
   			for(int j=1;j<=m;j++)
   				cin>>r[j];
   			fill(dp,dp+m+1,-1);
   			c[i]=recur(1,m,1);
   		}
   		fill(dp,dp+n+1,-1);
   		cout<<recur(1,n,2)<<endl;
   }


   return 0;
}
