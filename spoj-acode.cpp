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
string s;

ll dp[5005];
ll recur(ll i)
{
	ll n=s.length();
	ll ans=0;
	if(dp[i]!=-1)
		return dp[i];
	if(i>n-1)
		return 1;
	if((s[i]-'0')==0)
		return 0;
	if((s[i]-'0')>0 && (s[i]-'0')<27)
	{
		ans=ans+recur(i+1);
	}
	if(i+1<n){
		ll a=(s[i]-'0')*10+(s[i+1]-'0');
		if(a>0 && a<27)
		{
			ans=ans+recur(i+2);
		}
	}
	return dp[i]=ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while(1)
	{
		cin>>s;
		if(s[0]=='0')
			break;
		else
		{
			memset(dp,-1,sizeof dp);
			ll ans1=recur(0);
			cout<<dp[0]<<endl;
		}
	}


	return 0;
}
