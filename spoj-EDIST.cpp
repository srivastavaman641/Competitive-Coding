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
int dp[2005][2005];
string s1,s2;
int n,m;
int recur(int i,int j)
{
	if(i==n)
		return m-j;
	if(j==m)
		return n-i;
	if(dp[i][j]!=-1)
		return dp[i][j];
	if(s1[i]==s2[j])
		return dp[i][j]=recur(i+1,j+1);
	int ans=INT_MAX;
	ans=1+min(recur(i,j+1),min(recur(i+1,j),recur(i+1,j+1)));
	return dp[i][j]=ans;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   while(t--)
   {
   		cin>>s1>>s2;
   		n=s1.length();
   		m=s2.length();
   		memset(dp,-1,sizeof dp);
   		cout<<recur(0,0)<<endl;
   }


   return 0;
}
