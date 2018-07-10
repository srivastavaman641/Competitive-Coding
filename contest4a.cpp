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
#define PI 3.14159265
#define gs getline(cin,s)
#define pb push_back
#define mp make_pair
#define INF 1e18
#define pii pair<int,int>
#define z 1000000007
using namespace std;
string s;
ll dp[200005];

inline long long int recur(int x)
{
	//cout<<x<<endl;
	if(dp[x]!=-1)
		return 0;
	if(x==s.length())
		return 0;
	ll y=0,res=0;
	for(ll i=x;i<s.length();i++)
	{
		y=((y%z)*(10%z))%z+(s[i]-'0')%z;
		//cout<<y<<endl;
		res=res%z+y%z+(recur(i+1))%z;
		//cout<<res<<endl;
	}
	return dp[x]=res;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   for(ll i=0;i<200005;i++)
   {
   	dp[i]=-1;
   }
 //  cout<<dp[0];
   cin>>s;
   ll ans=recur(0);
   cout<<dp[0]<<endl;
   return 0;
}
