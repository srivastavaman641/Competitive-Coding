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
int dp[105][10005],sp[105][10005];
int a[105],w[105];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=x;i++)
		{
			cin>>a[i]>>w[i];
			a[i]=a[i]-w[i];
		}
		memset(dp,0,sizeof dp);
		memset(sp,0,sizeof sp);
		for(int i=0;i<=x;i++)
		{
			for(int j=0;j<=y;j++)
			{
				if(i==0 || j==0)continue;
				if(j<w[i]){
					sp[i][j]=sp[i-1][j];
					dp[i][j]=dp[i-1][j];
				}
				else if(dp[i-1][j]<=a[i]+dp[i-1][j-w[i]])
				{
					dp[i][j]=a[i]+dp[i-1][j-w[i]];
					sp[i][j]=w[i]+sp[i-1][j-w[i]];
					if(dp[i-1][j]==a[i]+dp[i-1][j-w[i]])
						sp[i][j]=min(sp[i-1][j],w[i]+sp[i-1][j-w[i]]);
				}
				else
				{
					dp[i][j]=dp[i-1][j];
					sp[i][j]=sp[i-1][j];
				}
			}
		}
		cout<<sp[x][y]<<" "<<dp[x][y]+y<<endl;
	}


	return 0;
}
