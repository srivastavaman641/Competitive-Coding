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
#define mod 100000007
#define PI 3.14159265
#define gs getline(cin,s)
#define pb push_back
#define mp make_pair
#define INF 1e18
#define pii pair<int,int>

using namespace std;
ll dp[1005][1026],a[1005],b[1005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	int cnt=0;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		cnt++;
		map<int,int>mp;
		int c=0;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=m;i++){
			cin>>b[i];
			mp[b[i]]=1;
		}
		memset(dp,0,sizeof dp);
		for(int i=1;i<=n;i++)
			dp[i][a[i]]=1;
		dp[0][0]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<1024;j++)
			{
				dp[i][j]=(dp[i-1][j]+dp[i-1][j^a[i]])%mod;
			}
		}
		int ans=0;
		for(int i=0;i<=1023;i++)
		{
			//cout<<dp[n][i]<<" ";
			if(!mp[i])
				ans=(ans+dp[n][i])%mod;
		}
		cout<<"Case "<<cnt<<": "<<ans<<endl;
	}


	return 0;
}
