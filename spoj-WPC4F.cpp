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
int dp[25][5];
int a[25][5];
int n;
int recur(int pos,int prev)
{
	if(pos>n)
		return 0;
	if(dp[pos][prev]!=-1)
		return dp[pos][prev];
	int ans=INT_MAX;
	for(int i=1;i<=3;i++)
	{
		if(i==prev)continue;
		ans=min(ans,a[pos][i]+recur(pos+1,i));
	}
	return dp[pos][prev]=ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		}
		memset(dp,-1,sizeof dp);
		cout<<recur(1,-1)<<endl;
	}


	return 0;
}
