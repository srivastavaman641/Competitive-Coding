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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		double result = n;
		for(ll i=2;i*i<=n;i++)
		{
			if(n%i==0)
			{
				while(n%i==0)
					n/=i;
				result*=(1.0-(1.0/i*1.0));
			}
		}
		if(n>1)
		{
			result*=(1.0-(1.0/n*1.0));
		}
		cout<<(ll)result<<endl;
	}

	return 0;
}
