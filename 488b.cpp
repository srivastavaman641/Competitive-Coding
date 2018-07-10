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
ll a[100005],b[100005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	vector<pii>ans,v;
	for(int i=0;i<n;i++)
	{
		v.pb(mp(a[i],i));
	}
	sort(v.begin(),v.end());
	ll sum=0;
	priority_queue<ll,vector<ll>,greater<ll> >pq;
	
	for(int i=0;i<=k;i++)
	{
		ll x=v[i].second;
		sum+=b[x];
		pq.push(b[x]);
		ans.pb(mp(x,sum));
	}
	for(int i=k+1;i<n;i++)
	{
		ll x=v[i].second;
		ll t=pq.top();
		if(t<b[x])
		{
			pq.pop();
			sum-=t;
			sum+=b[x];
			pq.push(b[x]);
			ans.pb(mp(x,sum));
		}
		else
		{
			ans.pb(mp(x,sum-t+b[x]));
		}
	}
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)
		cout<<ans[i].second<<" ";



	return 0;
}
