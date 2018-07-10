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
		int n;
		cin>>n;
		vector<pii>v;
		for(int i=1;i<=n;i++)
		{
			ll x,y;
			cin>>x>>y;
			v.pb(mp(x,y));
		}
		ll s,f;
		cin>>s>>f;
		for(int i=0;i<n;i++)
		{
			v[i].first=s-v[i].first;
		}
		v.pb(mp(s,0));
		sort(v.begin(),v.end());
		priority_queue<ll>q;
		ll ans=0;
		int flag=0;
		ll x=v[0].first;
		ll y=v[0].second;
		if(f-x<0)
		{
			cout<<-1<<endl;
			continue;
		}
		f=f-x;
		q.push(y);
		for(int i=1;i<=n;i++)
		{
			x=v[i].first;
			y=v[i].second;
			x=x-v[i-1].first;
			f=f-x;
			if(x<=f)
			{
				q.push(y);
			}
			else
			{
				while(!q.empty() && f<0)
				{
					ll a=q.top();
					q.pop();
					f+=a;
					ans++;
				}
				if(f<0)
				{
					flag=1;
					break;
				}
				q.push(y);
			}
		}
		if(flag==1)
			ans=-1;
		cout<<ans<<endl;
	}


	return 0;
}
