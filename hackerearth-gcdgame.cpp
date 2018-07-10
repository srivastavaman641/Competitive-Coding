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
int dp[1005][1005][2];
int recur(int x,int y,int turn)
{
	if(x==1 && y==1)
		return 3;
	else if(x==1)
		return 0;
	else if(y==1)
		return 1;
	if(dp[x][y][turn]!=-1)
		return dp[x][y][turn];
	int g=__gcd(x,y);
	if(turn==0)
	{
		if(g!=1)
		{
			return dp[x][y][turn]=recur(x,y/g,!turn)|recur(x,y-1,!turn);
		}
		else
			return dp[x][y][turn]=recur(x,y-1,!turn);
	}
	else
	{
		if(g!=1)
		{
			return dp[x][y][turn]=recur(x/g,y,!turn)&recur(x-1,y,!turn);
		}
		else
			return dp[x][y][turn]=recur(x-1,y,!turn);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	memset(dp,-1,sizeof dp);
	/*dp[1][1][0]=dp[1][1][1]=3;
	for(int i=1;i<=1004;i++){
		dp[1][i][0]=dp[1][i][1]=0;
		dp[i][1][0]=dp[i][1][1]=1;
	}

	for(int i=2;i<=1004;i++)
	{
		for(int j=2;j<=1004;j++)
		{
			int g=__gcd(i,j);
			for(int k=0;i<2;k++)
			{

				if(k==0){
					dp[i][j][k]=dp[i][j-1][!k];
					if(g!=1)
						dp[i][j][k]=dp[i][j][k]|dp[i][j/g][!k];
				}
				else
				{
					dp[i][j][k]=dp[i-1][j][!k];
					if(g!=1)
						dp[i][j][k]=dp[i][j][k]&dp[i/g][j][!k];

				}
			}
		}
	}*/
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		int x=recur(a,b,0);
		if(x==0)
			cout<<"Chandu Don"<<endl;
		else if(x==1)
			cout<<"Arjit"<<endl;
		else
			cout<<"Draw"<<endl;
	}


	return 0;
}
