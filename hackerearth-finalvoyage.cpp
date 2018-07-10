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
int n,c;
int dp[1005][1005];
int w[1005],a[1005];
int recur(int x,int p)
{
	if(x>n || p==0)
		return 0;
	if(dp[x][p]!=-1)
		return dp[x][p];
	int ans=0;
	if(w[x]>p)
		ans=recur(x+1,p);
	else
		ans=max(recur(x+1,p),a[x]+recur(x+1,p-w[x]));
	return dp[x][p]=ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>c;
		for(int i=1;i<=n;i++)
			cin>>w[i];
		for(int i=1;i<=n;i++)
			cin>>a[i];
		memset(dp,-1,sizeof dp);
		cout<<recur(1,c)<<endl;	
	}


	return 0;
}
