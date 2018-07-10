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
ll dp[11][90][90][2];
bool isprime[505];
void seive(int n)
{
	isprime[0]=isprime[1]=0;
	for(int i=2;i*i<=n;i++)
	{
		if(isprime[i])
		{
			for(int j=i*i;j<=n;j+=i)
				isprime[j]=0;
		}
	}
}
void todigit(ll n,vector<ll> &v)
{
	while(n)
	{
		v.pb(n%10);
		n/=10;
	}
}

ll recur(int idx,int sum1,int sum2,int tight,vector<ll> &v)
{
	
	if(idx==-1)
	{
		if(sum1-sum2>0 && isprime[sum1-sum2])
			return 1;
		else
			return 0;
	}
	if(dp[idx][sum1][sum2][tight]!=-1 && tight!=1)
		return dp[idx][sum1][sum2][tight];
	int k=(tight) ? v[idx] : 9;
	ll ans=0;
	for(int i=0;i<=k;i++)
	{
		int newtight= (i==v[idx]) ? tight: 0;
		if(idx%2==1)
			ans+=recur(idx-1,sum1+i,sum2,newtight,v);
		else
			ans+=recur(idx-1,sum1,sum2+i,newtight,v);
	}
	if(!tight)
		dp[idx][sum1][sum2][tight]=ans;
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	for(int i=0;i<=504;i++)
		isprime[i]=1;
	seive(504);
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		vector<ll>v;
		vector<ll>v1;
		n--;
		memset(dp,-1,sizeof dp);
		v.clear();
		v1.clear();
		todigit(n,v);
		todigit(m,v1);
		int sz1=v1.size();
		int sz=v.size();
		ll ans1=recur(sz1-1,0,0,1,v1);
		ll ans=recur(sz-1,0,0,1,v);
		cout<<ans1-ans<<endl;
	}
	return 0;
}
