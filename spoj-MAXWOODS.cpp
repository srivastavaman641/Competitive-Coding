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
int dp[205][205][2];
char a[205][205];
int n,m;
int recur(int i,int j,int f)
{
	if(i>n||i<1||j>m||j<1)
		return 0;
	if(a[i][j]=='#')
		return 0;
	if(dp[i][j][f]!=-1)
		return dp[i][j][f];
	int ans=0;
	if(f==0)
	{		
		if(a[i][j]=='T')
			ans=max(1+recur(i+1,j,1),1+recur(i,j+1,0));
		else if(a[i][j]!='#')
			ans=max(recur(i+1,j,1),recur(i,j+1,0));
	}

	else
	{
		if(a[i][j]=='T')
			ans=max(1+recur(i+1,j,0),1+recur(i,j-1,1));
		else if(a[i][j]!='#')
			ans=max(recur(i+1,j,0),recur(i,j-1,1));
	}	


	return dp[i][j][f]=ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
			}
		}
		memset(dp,-1,sizeof dp);
		cout<<recur(1,1,0)<<endl;
	}


	return 0;
}
