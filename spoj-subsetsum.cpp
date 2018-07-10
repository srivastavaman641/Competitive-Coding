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
ll dp[105][1000005];
ll a[105];
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
   		ll ans=0,s=0;
   		for(int i=1;i<=n;i++){
   			cin>>a[i];
   			s+=a[i];
   		}
   		for(ll i=0;i<=n;i++)
   			for(ll j=0;j<=s;j++)
   				dp[i][j]=0;
   		for(int i=0;i<=n;i++){
   			dp[i][0]=1;
   		}
   		for(ll i=1;i<=n;i++)
   		{
   			for(ll j=1;j<=s;j++)
   			{
   				if(a[i]>j)
   					dp[i][j]=dp[i-1][j];
   				else
   					dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i]];
   			}
   		}
   		for(ll i=0;i<=s;i++)
   		{
   			if(dp[n][i])
   				ans+=i;
   		}
   		cout<<ans<<endl;
   }


   return 0;
}
