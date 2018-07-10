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
int a[105],b[105],c[105];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	int n=s.length();
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='A'){
			a[i]=1;
			if(i!=n-1)
				a[i+1]=1;
			if(i!=0)
				a[i-1]=1;
		}
		if(s[i]=='B'){
			b[i]=1;
			if(i!=n-1)
				b[i+1]=1;
			if(i!=0)
				b[i-1]=1;
		}
		if(s[i]=='C'){
			c[i]=1;
			if(i!=n-1)
				c[i+1]=1;
			if(i!=0)
				c[i-1]=1;
		}


	}
	for(int i=0;i<n;i++)
	{
		if(a[i] && b[i] && c[i])
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;


	return 0;
}
