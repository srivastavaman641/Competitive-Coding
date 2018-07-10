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
ll dp[1005][1005];
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   dp[0][0]=1;
   for(int i=1;i<=1004;i++)
   {
   		for(int j=0;j<=i;j++)
   		{
   			if(j==0)
   				dp[i][j]=1;
   			else
   				dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
   		}
   }
   for(int i=1;i<=1004;i++)
   {
   		for(int j=0;j<=i;j++)
   		{
   			dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
   		}
   }
   while(t--)
   {
   		int n,p;
   		cin>>n>>p;
   		cout<<dp[n][p]<<endl;
   }


   return 0;
}
