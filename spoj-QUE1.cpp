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
vector<pii>v;
ll a[1005];
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
		v.clear();
		v.resize(n);

		for(int i=0;i<n;i++)
			a[i]=INT_MAX;
		for(int i=0;i<n;i++)
		{
			ll x;
			cin>>x;
			v[i].first=x;
		}
		for(int i=0;i<n;i++)
		{
			ll x;
			cin>>x;
			v[i].second=x;
		}
		
		sort(v.begin(),v.end());
		for(int i=0;i<n;i++)
		{
			int x=v[i].second;
			int cnt=0;
			for(int j=0;j<n;j++)
			{
				if(cnt==x && a[j]==INT_MAX)
				{
					a[j]=v[i].first;
					break;
				}
				if(a[j]==INT_MAX)
				{
					cnt++;
				}
			}
		}
		for(int i=0;i<n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}


	return 0;
}
