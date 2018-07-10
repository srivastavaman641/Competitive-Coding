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
ll a[10005],bit[10005];
void update(int x,ll val)
{
	for(;x<=10004;x+=x&(-x))
		bit[x]+=val;
}
ll query(ll x)
{
	ll sum=0;
	for(;x>0;x-=x&(-x))
		sum+=bit[x];
	return sum;
}
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
		memset(bit,0,sizeof bit);
		v.clear();
		v.resize(n);
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
		for(int i=0;i<n;i++)
		{
			update(i+1,1);
		}
		sort(v.begin(),v.end());
		for(int i=0;i<n;i++)
		{
			int x=v[i].second;
			x++;
			int low=1,high=n,ans=n+1;
			while(low<=high)
			{
				int mid=(low+high)/2;
				if(query(mid)>=x)
				{
					ans=min(ans,mid);
					high=mid-1;
				}
				else
				{
					low=mid+1;
				}
			}
			a[ans-1]=v[i].first;
			update(ans,-1);	
		}
		for(int i=0;i<n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}


	return 0;
}
