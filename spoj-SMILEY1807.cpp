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
int dp[4];
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   string s;
   cin>>s;
   int n=s.length();
   if(n<4)
   {
   		cout<<0<<endl;
   		return 0;
   }
   for(int i=0;i<n;i++)
   {
   		if(s[i]=='1')
   			dp[0]++;
   		else if(s[i]=='8')
   		{
   			if(dp[0]>0)
   			{
   				dp[1]=1+max(dp[0],dp[1]);
   			}
   		}
   		else if(s[i]=='0')
   		{
   			if(dp[1]>0)
   				dp[2]=1+max(dp[1],dp[2]);
   		}
   		else
   		{
   			if(dp[2]>0)
   				dp[3]=1+max(dp[3],dp[2]);
   		}
   }
   cout<<dp[3]<<endl;


   return 0;
}
