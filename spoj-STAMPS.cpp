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
ll a[1005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		ll x,n;
		cin>>x>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a,a+n+1);
		ll sum=0,ans=0;
		for(int i=n;i>0;i--)
		{
			if(sum>=x)
			{
				break;
			}
			sum+=a[i];
			ans++;
		}
		cout<<"Scenario #"<<k<<":"<<endl;
		if(sum<x)
			cout<<"impossible"<<endl;
		else
		cout<<ans<<endl;
	}


	return 0;
}
