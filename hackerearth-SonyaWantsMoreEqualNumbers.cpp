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
ll a[105];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	map<ll,ll>m;
	map<ll,ll> ::iterator it;
	vector<pii>v[100005];
	ll mx=0;
	for(int i=1;i<=n;i++)
	{
		ll sum=0;
		for(int j=i;j<=n;j++)
		{
			sum+=a[j];
			if(m[sum])
			{
				int flag=1;
				for(int k=0;k<v[sum].size();k++)
				{
					int x=v[sum][k].first;
					int y=v[sum][k].second;
					if((i>=x&&j<=y) || (i>=x&&i<=y) || (j>=x&&j<=y))

					{
						flag=0;
						break;
					}
				}
				if(flag==1)
				{
					m[sum]++;
					v[sum].pb(mp(i,j));
				}
			}
			else
			{
				m[sum]++;
				v[sum].pb(mp(i,j));
			}
			mx=max(mx,m[sum]);
		}
	}
	cout<<mx<<endl;
	for(it=m.begin();it!=m.end();it++)
	{
		if((*it).second==mx)
			cout<<(*it).first<<" ";
	}
	return 0;
}
