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
int x[]={0,0,0,1,-1};
int y[]={0,1,-1,0,0};
ll a[55][55];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	}
	vector<pii>v;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int c=0;
			for(int k=1;k<5;k++)
			{
				if(i+x[k]>0 && i+x[k]<=n && j+y[k]>0 && j+y[k]<=m)
					c++;
			}
			if(c==4)
				v.pb(mp(i,j));
		}
	}
	ll ans=0,mx=0;
	//cout<<v.size()<<endl;
	for(int i=0;i<v.size();i++)
	{

		int x1=v[i].first;
		int y1=v[i].second;
		for(int j=i+1;j<v.size();j++)
		{
			int x2=v[j].first;
			int y2=v[j].second;
			//cout<<"Coord "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
			int flag=1;
			ans=0;
			for(int k=0;k<5;k++)
			{
				for(int l=0;l<5;l++)
				{
					if((x1+x[k]==x2+x[l])&&(y1+y[k]==y2+y[l]))
					{
						//cout<<x1+x[k]<<" "<<y1+y[k]<<" "<<x2+x[l]<<" "<<y2+y[l]<<endl;
						flag=0;
						break;
					}
				}
				if(flag==0)
					break;
			}
			if(flag==1)
			{
				for(int k=0;k<5;k++)
				{
					ans=ans+(a[x1+x[k]][y1+y[k]]*a[x2+x[k]][y2+y[k]]);
					
				}
				mx=max(mx,ans);
			}
		}
	}
	cout<<mx<<endl;

	return 0;
}
