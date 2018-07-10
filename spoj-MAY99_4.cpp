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
#define mod 10000007
#define PI 3.14159265
#define gs getline(cin,s)
#define pb push_back
#define mp make_pair
#define INF 1e18
#define pii pair<int,int>

using namespace std;
ll dp[105][105];
int p,x;
ll recur(int n,int r)
{
	if(n<r || n<0 || r<0)
		return 0;
	if(r==0 || r==x)
		return 1;
	if(dp[n][r]!=-1)
		return dp[n][r];
	return dp[n][r]=(recur(n-1,r-1)%mod+recur(n-1,r)%mod)%mod;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>x>>p;
	memset(dp,-1,sizeof dp);
	if(x<p)
		cout<<"-1"<<endl;
	else if(x==p)cout<<1<<endl;
	else
		cout<<recur(x-1,p-1)<<endl;



	return 0;
}
