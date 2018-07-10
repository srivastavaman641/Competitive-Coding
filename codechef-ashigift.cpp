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
ll y[10005],q[10005],r[10005];
vector< pair<ll, pair<ll,ll> > > v;
int fun(ll m)
{
	for(int i=0;i<v.size();i++)
	{
		if(v[i].second.second==1)
		{
			m-=y[v[i].second.first];
			
		}
		else if(m>=q[v[i].second.first])
		{
			m+=r[v[i].second.first];
		}
	}
	if(m>0)
		return 1;
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	
	while(t--){
		ll X,b,c;
		cin>>X>>b;
		ll s=0;
		v.clear();
		for(int i=0;i<b;i++)
		{
			ll x;
			cin>>x>>y[i];
			s+=y[i];
			v.pb(mp(x,mp(i,1)));
		}
		cin>>c;
		for(int i=0;i<c;i++)
		{
			ll p;
			cin>>p>>q[i]>>r[i];
			v.pb(mp(p,mp(i,2)));
		}
		if(c==0)
			cout<<s+1<<endl;
		else{
			sort(v.begin(),v.end());
			ll low=1,high=s+1;
			while(low<high)
			{
				ll mid=(low+high)/2;
				if(fun(mid))
					high=mid;
				else
					low=mid+1;
			}
			cout<<low<<endl;
		}
	}
	return 0;

}