#include<bits/stdc++.h>
#define ll long long int
#define s(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define w(t) while(t--)
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
#define f first
using namespace std;
ll a[100005];
vector<pii>v;
vector<ll>ans1;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m,d;
	cin>>n>>m>>d;
	for(int i=0;i<m;i++)
	{
		cin>>a[i];
		v.pb(mp(a[i],i));
	}
	sort(v.begin(),v.end());
	ll i=0,ans=m;
	
	for(int j=0;j<n;j++)
		ans1.pb(v[j].second);

	sort(ans1.begin(),ans1.end());

	for(int i=0;i<n;i++)
	{
		cout<<a[ans1[i]]<<" ";
	}
	return 0;
}