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
/*int recur(int n)
{
	if(n==1)return 0;
	return (recur(n-1)+2)%n;
}*/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	cout<<1+recur(n)<<endl;
	string s;
	while(1){
		cin>>s;
		if(s[0]=='0' && s[1]=='0' && s[3]=='0')break;
		ll n=(s[0]-'0')*10+s[1]-'0';
		ll d=s[3]-'0';
		for(int i=1;i<=d;i++)
			n=n*10;
		ll p=1;
		while(p<=n)
			p*=2;
		cout<<2*n-p+1<<endl;
	}

	return 0;
}
