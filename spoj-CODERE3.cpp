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
int dp[1005],dp1[1005],a[1005];
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   while(t--)
   {
   		int n;
   		cin>>n;
   		int mx=0;
   		for(int i=1;i<=n;i++)
   		{
   			cin>>a[i];
   			dp[i]=dp1[i]=1;
   		}
   		for(int i=1;i<=n;i++)
   		{
   			for(int j=1;j<i;j++)
   			{
   				if(a[i]>a[j])
   					dp[i]=max(dp[i],1+dp[j]);
   			}
   		}
   		for(int i=n;i>0;i--)
   		{
   			for(int j=n;j>i;j--)
   			{
   				if(a[i]>a[j])
   					dp1[i]=max(dp1[i],1+dp1[j]);
   			}
   		}
   		for(int i=1;i<=n;i++)
   		{
   			mx=max(mx,dp[i]+dp1[i]-1);
   		}
   		cout<<mx<<endl;

   }


   return 0;
}
