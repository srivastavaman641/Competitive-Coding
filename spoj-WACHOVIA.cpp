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
int dp[55][1005];
int a[55],w[55];
int n,k;
int recur(int x,int p)
{
	if(x==n+1 || p==0)
		return 0;
	if(dp[x][p]!=-1)
		return dp[x][p];
	if(w[x]>p)
		return dp[x][p]=recur(x+1,p);
	else
		return dp[x][p]=max(recur(x+1,p),a[x]+recur(x+1,p-w[x]));
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   while(t--)
   {
   		cin>>k>>n;
   		for(int i=1;i<=n;i++)
   			cin>>w[i]>>a[i];
   		memset(dp,-1,sizeof dp);
   		cout<<"Hey stupid robber, you can get "<<recur(1,k)<<"."<<endl;
   }


   return 0;
}
