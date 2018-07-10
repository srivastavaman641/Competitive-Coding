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
#define pii pair<ll,ll>

using namespace std;
ll t[200005],d[200005];
priority_queue<ll>p;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++)
	{
		cin>>t[i]>>d[i];
	}
	ll ans=0,pw=0;
	for(ll i=0;i<n;i++)
	{
		pw+=d[i];
		p.push(d[i]);
		while(pw>t[i] && !p.empty()){
			ll x=p.top();
			p.pop();
			pw-=x;
			ans++;
		}
	}
	cout<<ans<<endl;

	return 0;
}
