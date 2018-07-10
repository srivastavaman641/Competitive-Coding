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
int a[2005];
int dp[2005];
int recur(int x,int s,int n)
{
    if(dp[x]!=-1)
    	return dp[x];
    if(x<=0)
    	return 0;
    int ans=0,f=0;
    for(int i=0;i<n;i++)
    {
    	if(a[i]<=x){
    	 f=a[i]+recur(x-a[i],s,n);
    	 ans=max(ans,f);
    }
    }
    return dp[x]=ans;
}
int main()
{
   //ios_base::sync_with_stdio(false);
   //cin.tie(NULL);
   int t;
   cin>>t;
   while(t--)
   {
   	int n,k;
   	cin>>n>>k;
   	for(int i=0;i<2005;i++)
   		dp[i]=-1;
   	int ans=0;
   	for(int i=0;i<n;i++)
   	{
   		cin>>a[i];
   	}
   	ans=recur(k,k,n);
   	cout<<ans<<endl;
   }
   return 0;
}
