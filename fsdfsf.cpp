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
ll power(ll x,ll y)
{
	ll ans=1;
	while(y)
	{
		if(y%2)
			ans=ans*x;
		x=x*x;
		y/=2;
	}
	return ans;
}
ll totalPrimeFactors(ll n,ll l,ll r)
{
	ll count=0;
	if (!(n%2))
	{
		if(n>=l && n<=r)
			count++;
		while(!(n%2))
			n/=2;
	}
	for (ll i=3;i*i<=n;i=i+2)
	{
		if (!(n%i))
		{
			if(n>=l && n<=r)
				count++;
			while (!(n%i))
				n /= i;
		}
	}
	if (n>2 && n>=l && n<=r)
		count++;
	return count;
}
ll countPairs(ll G,ll L,ll l,ll r)
{
	if(L%G!=0)
		return 0;
	ll div=L/G;
	ll ans=0;
	ans=totalPrimeFactors(div,l,r);
	if(ans==0){
		if(__gcd(l,r)==G && l*r==G*L)
			return 1;
		return 0;
	}
	ans=power(2,ans);
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll l,r,x,y;
	cin>>l>>r>>x>>y;
	cout<<countPairs(x,y,l,r)<<endl;
	return 0;
}
