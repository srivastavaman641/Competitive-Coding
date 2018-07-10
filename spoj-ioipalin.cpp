#include<bits/stdc++.h>

using namespace std;
int dp[5005][5005];
char s[5005],s1[5005];
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   scanf("%d",&n);
   scanf("%s",s);
	memset(dp,-1,sizeof dp);
	for(int i=0;i<n;i++)
	{
		s1[i]=s[n-i-1];
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0||j==0)
				dp[i][j]=0;
			else if(s[i-1]==s1[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		}
	}
	printf("%d\n",n-dp[n][n]);
	


   return 0;
}

