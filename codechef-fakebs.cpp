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
vector<pair<ll,ll> >v;
ll a[100005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n,q;
		cin>>n>>q;
		v.clear();
		memset(a,0,sizeof a);
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			v.pb(mp(a[i],i));
		}
		sort(v.begin(),v.end());
		while(q--)
		{
			ll qu;
			cin>>qu;
			int low=0,high=n-1,mid;
			while(low<=high)
			{
				mid=(low+high)/2;
				if(v[mid].first==qu)
				{
					break;
				}
				else if(v[mid].first>qu)
				{
					high=mid-1;
				}
				else
					low=mid+1;
			}
			int greater=n-mid-1;
			int smaller=mid;
			int ans=v[mid].second;
			low=1,high=n;
			int large=0,small=0,a1=0,b=0;
			while(low<=high)
			{
				mid=(low+high)/2;
				if(a[mid]>qu)
				{
					if(mid>ans){
						a1++;
						high=mid-1;
					}
					else{
						small++;
						low=mid+1;
					}
				}
				else if(a[mid]<qu)
				{
					if(mid<ans){
						b++;
						low=mid+1;
					}
					else
					{
						large++;
						high=mid-1;
					}
				}
				else
					break;
			}
			if(large>small)
			{
				if(greater-a1>=large)
					cout<<large<<endl;
				else
					cout<<-1<<endl;
			}
			else
			{
				if(smaller-b>=small)
					cout<<small<<endl;
				else
					cout<<-1<<endl;
			}
		}
	}


	return 0;
}
