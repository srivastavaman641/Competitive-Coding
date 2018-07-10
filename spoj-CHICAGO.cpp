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
double dp[105][105];
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n,m;
   while(1)
   {
   		cin>>n;
   		if(n==0)
   			break;
   		cin>>m;
   		memset(dp,0.0,sizeof dp);
   		for(int i=1;i<=m;i++)
   		{
   			int x,y,z;
   			cin>>x>>y>>z;
   			dp[x][y]=(z*1.0)/(100*1.0);
   			dp[y][x]=(z*1.0)/(100*1.0);
   		}
   		for(int k=1;k<=n;k++)
   		{
   			for(int i=1;i<=n;i++)
   			{
   				for(int j=1;j<=n;j++)
   				{
   					dp[i][j]=max(dp[i][j],dp[i][k]*dp[k][j]);
   				}
   			}
   		}
   		printf("%.6f percent\n",dp[1][n]*100.0);

   }


   return 0;
}
