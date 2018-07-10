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
#define INF 1e18
#define pii pair<int,int>

using namespace std;
int a[1005];
int gc(int x,int y)
{
	if(y==0)
		return x;
	return gc(y,x%y);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int flag=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[i]==1)
				flag=1;
		}
		if(flag==1)
		{
			cout<<0<<endl;
			continue;
		}
		sort(a,a+n);
		reverse(a,a+n);
		int x=gc(a[0],a[1]);
		for(int i=2;i<n;i++)
		{
			x=gc(x,a[i]);
		}
		if(x!=1)
		{
			cout<<-1<<endl;
		}
		else
			cout<<0<<endl;
	}

	return 0;
}