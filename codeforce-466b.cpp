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
	ll n,k,a,b;
	cin>>n>>k>>a>>b;
	ll mx=(n-1)*a,ans=0;
	if(k==1)
	{
		cout<<mx<<endl;
		return 0;
	}
	while(n!=1){

		if(n%k==0 && ((n-(n/k))*a)>b)
		{
			n/=k;
			ans+=b;
		}
		else if(n%k==0 && ((n-(n/k))*a)<=b)
		{
			
			ans+=((n-(n/k))*a);
			n=(n/k);
		}
		else if(n/k!=0)
		{
			ll x=n%k;
			n-=x;
			ans+=(x*a);
		}
		else
		{
			
			ans+=((n-1)*a);
			n=1;
		}

	}
	cout<<min(ans,mx)<<endl;
	return 0;
}
