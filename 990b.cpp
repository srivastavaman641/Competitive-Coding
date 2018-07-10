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
vector<ll>v;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		v.pb(x);
	}
	sort(v.rbegin(),v.rend());
	ll lim=0,c=0;
	int i=0;
	while(i<n)
	{
		//cout<<i<<endl;
		ll val=v[i];
		ll low=i+1,high=n-1;
		ll ans=-1;
		while(low<=high)
		{
			ll mid=(low+high)/2;
			if(v[mid]+k>=val && v[mid]<val)
			{
				low=mid+1;
				ans=max(ans,mid);
			}
			else
			{
				high=mid-1;
			}
		}
		//cout<<ans<<endl;
		if(ans!=-1){
			//cout<<ans<<" "<<i<<endl;
			c+=(ans-i);
			i=ans;
			//cout<<c<<endl;
		}
		else
			i++;
	}
	cout<<n-c<<endl;


	return 0;
}
