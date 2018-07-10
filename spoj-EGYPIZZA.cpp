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
	int n;
	cin>>n;
	int c1=0,c2=0,c3=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		if(s[0]=='1'&&s[2]=='2')
			c1++;
		else if(s[0]=='1'&&s[2]=='4')
			c2++;
		else
			c3++;
	}
	ans+=(c1/2);
	c1=c1-2*ans;
	int b=min(c2,c3);
	c2-=b;
	c3-=b;
	ans+=b;
	ans+=c3;
	ans+=(ceil(c1*0.5+c2*0.25));
	cout<<ans+1<<endl;
	return 0;
}
