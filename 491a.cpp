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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a,b,c,n;
	cin>>a>>b>>c>>n;

	if(a >n|| b >n || c >n)
	{
		cout<<-1;
		return 0;
	}
	if(c>a || c>b)
	{
		cout<<-1;
		return 0;
	}
	a-=c;
	b-=c;
	if(n-(a+b+c)>=1)
	{
		cout<<n-a-b-c;
		return 0;
	}
	else 
	{
		cout<<-1<<endl;
		return 0;
	}

	return 0;
}
