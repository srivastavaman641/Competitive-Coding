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
typedef unsigned long long int ull;
map<int,int>mp;
int a[100005];
int dp[100005];
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   while(t--)
   {
   		ull n,k;
   		cin>>n>>k;
   		memset(dp,0,sizeof dp);
   		for(int i=1;i<=n;i++)
   			cin>>a[i];
   		for(int i=1;i<=n;i++)
   		{
   			if(mp[a[i]]){
   				dp[i]=dp[i-1];
   				mp[a[i]]++;
   			}
   			else
   			{
   				dp[i]=dp[i-1]+1;
   				mp[a[i]]++;
   			}
   		}
   		

   }


   return 0;
}