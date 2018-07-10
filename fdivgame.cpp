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
ll grendy(ll n)
{
	if(n==0)
		return 0;
	else if(n==1)
		return 1;
	else if(n==2 || n==3)
		return 2;
	else if(n==4 || n==5)
		return 3;
	else if(n>5 && n<12)
		return 0;
	return grendy(n/12);
}
ll a[105];
int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		ll ans=0;
		for(int i=0;i<n;i++)
		{
				ans^=grendy(a[i]);
		}
		if
			(ans!=0)
		{
			cout<<"Henry"<<endl;

		}
		else
			cout<<"Derek"<<endl;
	}


	return 0;
}
