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
vector<ll>v,v1;
void todigit(ll a,vector<ll> &v)
{
	while(a)
	{
		v.pb(a%10);
		a/=10;
	}
}
ll dp[11][95][2];
ll recur(int idx,int sum,int tight,vector<ll> &v)
{
	if(idx==-1)
		return sum;

	if(dp[idx][sum][tight]!=-1 && !tight)
		return dp[idx][sum][tight];

	int k= (tight) ? v[idx]:9;
	ll ans=0;
	for(int i=0;i<=k;i++)
	{
		int newtight= (i==v[idx])?tight :0;
		ans+=recur(idx-1,sum+i,newtight,v);
	}
	if(!tight)
		dp[idx][sum][tight]=ans;

	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll a,b;
	memset(dp,-1,sizeof dp);
	while(1){
		cin>>a>>b;
		if(a==-1 && b==-1)
			break;
		v.clear();
		v1.clear();
		a--;
		todigit(b,v1);
		todigit(a,v);
		int n=v.size();
		int m=v1.size();
		cout<<recur(m-1,0,1,v1)-recur(n-1,0,1,v)<<endl;
	}


	return 0;
}
