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
int dist(pii p1,pii p2)
{
	int x1=p1.first;
	int x2=p2.first;
	int y1=p1.second;
	int y2=p2.second;
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<pii>v,v1;
	vector<int> ans1,ans2;
	for(int i=0;i<4;i++)
	{
		int x,y;
		cin>>x>>y;
		v.pb(mp(x,y));
	}
	for(int i=0;i<4;i++)
	{
		int x,y;
		cin>>x>>y;
		v1.pb(mp(x,y));
	}
	int xidx,yidx;
	for(int i=0;i<4;i++)
	{
		int x=v[i].first;
		int y=v[i].second;
		for(int j=i+1;j<4;j++)
		{
			int x1=v[j].first;
			int y1=v[j].second;
			if(x==x1)
			{
				yidx=abs(y1-y)/2;
			}
			if(y==y1)
			{
				xidx=abs(x-x1)/2;
			}
		}
	}
	pii p=mp(xidx,yidx);
	cout<<xidx<<" "<<yidx<<endl;
	int x=xidx;
	for(int i=0;i<4;i++)
	{
		ans2.pb(dist(v1[i],p));
	}
	sort(ans2.begin(),ans2.end());
	if(ans2[0]<x)
	{
		cout<<"YES"<<endl;
	}
	else
		cout<<"NO"<<endl;

	return 0;
}
