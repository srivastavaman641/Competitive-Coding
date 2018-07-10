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
ll dp1[2005][2005];
int dp[2005][2005];
ll recur(int l,int h)
{
	if(dp[l][h])
		return 0;
	if(dp1[l][h]!=-1)
		return dp1[l][h];
	ll ans=INT_MAX;
	for(int i=l;i<h;i++){
		if(dp[l][i])
		ans=min(ans,1+recur(i+1,h));
	}
	return dp1[l][h]=ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int n=s.length();
		memset(dp,0,sizeof dp);
		for(int i=0;i<n;i++)
		{
			dp[i][i]=1;
		}
		for(int i=0;i<n-1;i++){
			if(s[i]==s[i+1])
				dp[i][i+1]=1;
			else
				dp[i][i+1]=0;
		}
		for(int i=3;i<=n;i++)
		{
			for(int j=0;j<n-i+1;j++)
			{
				int end=j+i-1;
				if(s[j]==s[end] && dp[j+1][end-1])
				{
					dp[j][end]=1;
				}
				else
					dp[j][end]=0;
			}
		}
		//cout<<dp[0][2]<<" "<<dp[2][4]<<endl;
		memset(dp1,-1,sizeof dp1);
		cout<<recur(0,n-1)+1<<endl;
	}


	return 0;
}
