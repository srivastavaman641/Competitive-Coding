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
string s1,s2;
int dp[105][105][105];
int recur(int n,int m,int k)
{
	int ans=0;
	if(dp[n][m][k]!=-1)
		return dp[n][m][k];
	if(n==0 || m==0){
		if(k==0)
		return 0;
		else
			return INT_MIN;
	}
	if(k==0)
		return 0;
	if(s1[n-1]==s2[m-1])
	{
		ans=max(recur(n-1,m-1,k),(int)s1[n-1]+recur(n-1,m-1,k-1));
	}
	else
	{
		ans=max(recur(n-1,m,k),recur(n,m-1,k));
	}
	return dp[n][m][k]=ans;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   while(t--)
   {
   	int k;
   	cin>>s1>>s2;
   	cin>>k;
   	memset(dp,-1,sizeof dp);
   	int a=s1.length();
   	int b=s2.length();
   	ll x=recur(a,b,k);
   	if(x<0)
   		cout<<0<<endl;
   	else
   		cout<<x<<endl;
   }


   return 0;
}
