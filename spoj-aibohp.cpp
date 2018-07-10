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
ll dp[6105][6105];

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
   	string s,s1;

   		cin>>s;
   		memset(dp,-1,sizeof dp);
   		int n=s.length();
   		s1=s;
   		reverse(s1.begin(),s1.end());
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
   		cout<<n-dp[n][n]<<endl;
   }
   return 0;
}
