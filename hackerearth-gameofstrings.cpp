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
#define INF 1e18
#define pii pair<int,int>

using namespace std;
map<char,int>mp;
 string s1,s2;
 int dp[5005][5005];
int recur(int n,int m)
{
	if(n==s1.length() || m==s2.length())
		return 0;
	if(dp[n][m]!=-1)
		return dp[n][m];
	if(s1[n]==s2[m])
	{
		if(!mp[s1[n]])
			return dp[n][m]= 1+recur(n+1,m+1);
		else
			return dp[n][m]=recur(n+1,m+1);
	}
	else
		return dp[n][m]=max(recur(n+1,m),recur(n,m+1));
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   memset(dp,-1,sizeof dp);
   cin>>s1>>s2;
   mp['a']=mp['e']=mp['i']=mp['o']=mp['u']=1;
   cout<<recur(0,0);
   return 0;
}
