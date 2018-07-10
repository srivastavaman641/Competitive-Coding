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
ll dp[10005],p[10005];
vector< pair<ll,pii> > v;
int n;
ll recur(int pos)
{
	if(pos==n)
		return 0;
	if(dp[pos]!=-1)
		return dp[pos];
	ll ans=0;
	ans=recur(pos+1);
	ll x=v[pos].first;
	ll z=v[pos].second.second;
	ll y=v[pos].second.first;
	ans=max(ans,z+recur(p[pos]));
	return dp[pos]=ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		v.clear();
		for(int i=0;i<n;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			v.pb(mp(x,mp(x+y,z)));
		}
		sort(v.begin(),v.end());
		memset(p,0,sizeof p);
		for(int pos=0;pos<n;pos++)
		{
			ll x=v[pos].first;
			ll z=v[pos].second.second;
			ll y=v[pos].second.first;
			int low=pos+1,high=n-1,an=n;
			while(low<=high)
			{
				int mid=(low+high)/2;
				if(v[mid].first>y)
				{
					an=min(an,mid);
					high=mid-1;
				}
				else
					low=mid+1;
			}
			p[pos]=an;
		}
		/*cout<<endl;
		for(int pos=0;pos<n;pos++)
		{
			ll x=v[pos].first;
			ll z=v[pos].second.second;
			ll y=v[pos].second.first;
			cout<<x<<" "<<y<<" "<<z<<endl;
		}
		for(int i=0;i<n;i++)
			cout<<p[i]<<endl;*/
		memset(dp,-1,sizeof dp);
		cout<<recur(0)<<endl;
	}

	return 0;
}
