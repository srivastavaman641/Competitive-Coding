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
int dp[105][505];
int a[105],w[105];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int W,n;
	while(1){
		cin>>W>>n;
		if(W==0 && n==0)
			break;
		memset(dp,-1,sizeof dp);
		for(int i=1;i<=n;i++)
			cin>>w[i]>>a[i];
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=W;j++)
			{
				if(i==0 || j==0)
					dp[i][j]=0;
				else if(w[i]>j)
					dp[i][j]=dp[i-1][j];
				else
					dp[i][j]=max(a[i]+dp[i-1][j-w[i]],dp[i-1][j]);
			}
		}
		int ans=0;

		for(int i=0;i<=W;i++)
		{
			if(dp[n][i]==dp[n][W])
			{
				ans=i;
				break;
			}
		}
		cout<<ans<<" "<<dp[n][W]<<endl;
	}
	return 0;
}
