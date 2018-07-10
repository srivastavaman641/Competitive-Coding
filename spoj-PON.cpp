#include<bits/stdc++.h>
#define ll unsigned long long int
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
ll mulmod(ll a, ll b, ll c){
	ll x=0,y=a%c;
	while(b>0){
		if(b&1) x = (x+y)%c;
		y = (y<<1)%c;
		b >>= 1;
	}
	
	return x;
}
ll power(ll x,ll y,ll MOD)
{
	ll ans=1;
	x=x%MOD;
	while(y)
	{
		if(y & 1)
			ans=mulmod(ans,x,MOD);
		x=mulmod(x,x,MOD);
		y/=2;
	}
	return ans;
}
int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		if(n<2 || n==4)
		{
			cout<<"NO"<<endl;
			continue;
		}
		if(n==2 || n==3)
		{
			cout<<"YES"<<endl;
			continue;
		}
		ll ans,flag=1;
		for(int i=0;i<5;i++){
			int a = 2 + rand()%(n-4);  
			if ((power(a,n-1,n)+n)%n!=1){
				flag=0;
				break;
			}
		}
		if(flag==1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;

	}


	return 0;
}
