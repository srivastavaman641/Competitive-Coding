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
ll dp[45];
bool isprime[300005];
ll a[300005];
void seive()
{
	isprime[0]=isprime[1]=0;
	for(int i=2;i*i<=300004;i++)
	{
		if(isprime[i])
		{
			for(int j=i*i;j<=300004;j+=i)
			{
				isprime[j]=0;
			}
		}
	}
	for(int i=2;i<=300004;i++)
	{
		if(isprime[i])
			a[i]=1+a[i-1];
		else
			a[i]=a[i-1];
	}
}
ll recur(int x)
{
	if(x==0)
		return 1;
	if(x<0)
		return 0;
	ll ans=recur(x-1)+recur(x-4);
	return dp[x]=ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	for(int i=0;i<=300004;i++)
		isprime[i]=1;
	seive();
	memset(dp,-1,sizeof dp);
	while(t--)
	{
		int n;
		cin>>n;
		ll ans=recur(n);
		cout<<a[ans]<<endl;
	}
	return 0;
}
