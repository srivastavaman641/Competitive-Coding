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
ll a[100005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		map<int,int>m;
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
			m[a[i]]=i;
		}
		vector<int>v;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			v.pb(m[x]);
		}
		vector<int>tail;
		tail.resize(n,0);
		tail[0]=v[0];
		int length=1;
		for(int i=1;i<n;i++)
		{
			if(v[i]<tail[0])
				tail[0]=v[i];
			else if(v[i]>tail[length-1])
			{
				tail[length]=v[i];
				length++;
			}
			else
			{
				int low=0,high=length-1,ans=length;
				while(low<=high)
				{
					int mid=(low+high)/2;
					if(tail[mid]>=v[i])
					{
						ans=min(ans,mid);
						high=mid-1;
					}
					else
						low=mid+1;
				}
				tail[ans]=v[i];
			}
		}
		cout<<length<<endl;

	}


	return 0;
}
