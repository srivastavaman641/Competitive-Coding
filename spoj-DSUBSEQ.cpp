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
ll dp[100005];
int prv[505];
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
   		memset(prv,0,sizeof prv);
   		dp[0]=1;
   		for(int i=1;i<=n;i++)
   		{
   			dp[i]=(dp[i-1]*2)%mod;
   			if(prv[s[i-1]])
   			{
   				dp[i]=(dp[i]-dp[prv[s[i-1]]-1]+mod)%mod;
   			}

   			prv[s[i-1]]=i;
   		}
   		cout<<dp[n]<<endl;

   }


   return 0;
}
